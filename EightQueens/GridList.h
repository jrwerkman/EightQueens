#pragma once

struct GridNode {
	Grid *grid;
	GridNode *next;
};

class GridList
{
	GridNode *node;
	bool isCreated;
	int m_size;
public:
	GridList() {
		isCreated = false;
		m_size = 0;
	}

	~GridList() {
		if (isCreated) {
			GridNode * nextNode = node;
			GridNode * deletionNode;

			for (int i = 0; i < m_size; i++) 
			{
				deletionNode = nextNode;
				nextNode = deletionNode->next;

				delete deletionNode->grid;
				delete deletionNode;
			}
		}
	}

	void insertStart(Grid &grid) {
		if (!isCreated) {
			create(grid);
			return;
		}

		if (isAdded(grid))
			return;

		GridNode *tempNode = new GridNode();
		tempNode->grid = new Grid(grid);
		tempNode->next = this->node;

		this->node = tempNode;
		m_size++;
	}

	void insertEnd(Grid &grid) {
		if (!isCreated) {
			create(grid);
			return;
		}

		if (isAdded(grid))
			return;

		GridNode *tempNode = new GridNode();
		tempNode->grid = new Grid(grid);
		tempNode->next = NULL;

		GridNode *lastNode = node;
		while(lastNode->next != NULL)
			lastNode = lastNode->next;

		lastNode->next = tempNode;
		m_size++;
	}

	void deleteFirst() {
		GridNode *deletionNode;

		if (m_size == 1) {
			deletionNode = node;
		}
		else {
			deletionNode = node;

			GridNode *tempNode = node->next;
			node = tempNode;
		}

		delete deletionNode->grid;
		delete deletionNode;
		m_size--;
	}

	void deleteLast() {
		GridNode * deletionNode = node;

		while (node->next != NULL)
			deletionNode = node->next;

		delete deletionNode->grid;
		delete deletionNode;
		m_size--;
	}

	Grid* get(const int index) {
		if(index >= m_size || !isCreated)
			return nullptr;

		//if (index == 0)
		//	return node->grid;

		GridNode * returnNode = node;
		for (int i = 0; i < index; i++)
			returnNode = returnNode->next;

		return returnNode->grid;
	}

	const int size() {
		return m_size;
	}
private:
	void create(Grid &grid) {
		node = new GridNode;
		node->grid = new Grid(grid);
		node->next = NULL;

		m_size++;
		isCreated = true;
	}

	bool isAdded(Grid &grid) {
		GridNode * checkNode = node;

		for (int i = 0; i < m_size; i++)
		{
			if (checkNode->grid->compare(grid))
				return true;

			checkNode = checkNode->next;
		}

		return false;
	}
};