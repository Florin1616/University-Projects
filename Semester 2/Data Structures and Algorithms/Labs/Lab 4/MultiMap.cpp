#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

//BC=AC=WC=Theta(1)
int MultiMap::hash(TKey key) const
{
	int hashResult = key % capacity;

	if (hashResult < 0)
		hashResult *= -1;

	return hashResult;
}

//Best case: O(1) 
//Worst case: O(N) When the initialization involves iterating through the entire list to set each element to nullptr
//Total case: O(N) 
MultiMap::MultiMap()
{
	//TODO - Implementation
	this->numberOfElements = 0;
	this->capacity = 1019;

	this->elements = (Node**)new Node[this->capacity];

	if (this->elements == nullptr)
		return;

	for (int i = 0; i < this->capacity; i++)
		this->elements[i] = nullptr;
}

//Best case: O(1) When the element to be added can be added at the beginning of the list
//Worst case: O(N) When the element to be added needs to be added at the end of the list
//Total case: O(N) 
void MultiMap::add(TKey c, TValue v)
{
	TElem data = std::pair<TKey, TValue>(c, v);
	Node* newNode = new Node(data, nullptr);

	int index = this->hash(c);

	Node* previousHead = this->elements[index];
	newNode->next = previousHead;

	this->elements[index] = newNode;

	this->numberOfElements++;
}

//Best case: O(1) When the element to be removed is the first element in the list
//Worst case: O(N) When the element to be removed is the last element in the list
//Total case: O(N) 
bool MultiMap::remove(TKey c, TValue v)
{
	int index = this->hash(c);

	Node* currentNode = this->elements[index];
	Node* previousNode = this->elements[index];

	while (currentNode != nullptr)
	{
		if (currentNode->data.first == c && currentNode->data.second == v)
		{
			if (currentNode == previousNode)
			{
				this->elements[index] = this->elements[index]->next;

				this->numberOfElements--;
				return true;
			}

			previousNode->next = currentNode->next;

			this->numberOfElements--;
			return true;
		}

		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	return false;
}

//Best case: O(1) When the element to be searched is the first element in the list or when the element is not in the list
//Worst case: O(N) When the element to be searched is the last element in the list
//Total case: O(N) 
vector<TValue> MultiMap::search(TKey c) const
{
	std::vector<TValue> values;

	int index = this->hash(c);

	Node* currentNode = this->elements[index];

	while (currentNode != nullptr)
	{
		if (currentNode->data.first == c)
			values.push_back(currentNode->data.second);

		currentNode = currentNode->next;
	}

	return values;
}

//BC=AC=WC=Theta(1)
int MultiMap::size() const
{
	//TODO - Implementation
	return this->numberOfElements;
}

//BC=AC=WC=Theta(1)
bool MultiMap::isEmpty() const
{
	//TODO - Implementation
	return this->numberOfElements == 0;
}

//BC=AC=WC=Theta(1)
MultiMapIterator MultiMap::iterator() const
{
	return MultiMapIterator(*this);
}

//BC=AC=WC=Theta(1)
MultiMap::~MultiMap()
{
	//TODO - Implementation
	delete[] this->elements;
}

//Best Case = O(1) When there are no nodes in the linked list
//Worst Case = O(N) When there are N nodes in the linked list
//Average Case = 0(N)
vector<TValue> MultiMap::removeKey(TKey key)
{
	vector<TValue> removedValues;

	int index = hash(key);
	Node* currentNode = elements[index];
	Node* previousNode = nullptr;

	while (currentNode != nullptr)
	{
		if (currentNode->data.first == key)
		{
			removedValues.push_back(currentNode->data.second);

			if (previousNode == nullptr)
				elements[index] = currentNode->next;
			else
				previousNode->next = currentNode->next;

			Node* nodeToDelete = currentNode;
			currentNode = currentNode->next;
			delete nodeToDelete;
			numberOfElements--;
		}
		else
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
	}
	return removedValues;
}

