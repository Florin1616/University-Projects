#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>


//BC=AC=WC=Theta(1)
SortedIndexedList::SortedIndexedList(Relation r) {
	this->R = r;
	this->root = NULL;
	this->sizeBST = 0;
}

//BC=AC=WC=Theta(1)
int SortedIndexedList::size() const {
	if (root == NULL) return 0;
	return this->sizeBST;
}

//Complexity: BC=AC=WC=Theta(1)
bool SortedIndexedList::isEmpty() const {
	if (this->sizeBST == 0) return true;
	return false;
}


//WC=O(n) when we have a degenerate tree and the node we need is a leaf (we have to parse through all of its nodes)
//BC=O(1) when the node we need is the root
//AC=O(log n)
TComp SortedIndexedList::getElement(int i) const {
	if (i < 0 || i >= this->sizeBST)
	{
		exception myex;
		throw(myex);
	}
	node* current = this->root;
	int position = 0;
	while (current != NULL)
	{
		if (i == position + current->nrLeft)return current->info;
		if (i < position + current->nrLeft)
		{
			current = current->left;
		}
		else
		{
			position = position + current->nrLeft + 1;
			current = current->right;
		}
	}
}


//WC=O(n) when we have a degenerate tree and the node to be deleted is a leaf - we need to parse through all of its other nodes
//BC=O(1) when the node to be deleted is the root and the tree has a size of 1 (the root is the only element)
//AC=O(log n)
TComp SortedIndexedList::remove(int i) {
	if (i < 0 || i >= this->sizeBST)
	{
		exception myex;
		throw(myex);
	}
	node* prev = NULL;
	node* current = this->root;
	int position = 0;
	while (current)
	{
		if (i == position + current->nrLeft) break;
		if (i < position + current->nrLeft)
		{
			prev = current;
			current = current->left;
		}
		else
		{
			prev = current;
			position = position + current->nrLeft + 1;
			current = current->right;

		}
	}
	int deleted = current->info;
	if (current->left == NULL && current->right == NULL)
	{
		decrease(i);
		if (prev == NULL)
		{
			this->root == NULL;
		}
		else
		{
			if (this->R(current->info, prev->info)) prev->left = NULL;
			else prev->right = NULL;
			delete[] current;
		}
		this->sizeBST--;
	}
	else
	{
		if (current->left == NULL || current->right == NULL)
		{
			decrease(i);

			node* descendant;
			if (current->left == NULL)
				descendant = current->right;
			else
				descendant = current->left;

			if (prev == NULL)
			{
				//root
				this->root = descendant;
			}
			else
			{
				//not root
				if (this->R(current->info, prev->info))
				{
					//on left
					prev->left = descendant;
				}
				else
				{
					//on right
					prev->right = descendant;
				}
				delete[] current;

			}
			this->sizeBST--;
		}
		else
		{
			TComp ssuccessor = this->successor(current->info);
			int index = this->search(ssuccessor);

			this->remove(index);



			current->info = ssuccessor;
		}
	}
	return deleted;
}


//WC=O(n) when we have a degenerate tree and the node whose parent we need is a leaf - we need to parse through all of its other nodes as well
//BC=O(1) when the tree has a size of 1 (only contains the root)
//AC=O(log n)
TComp SortedIndexedList::parent(TComp e)
{
	if (this->root->info == e)
		return -1;
	node* current = this->root;

	while (current && current->left->info != e && current->right->info != e)
	{
		if (!this->R(current->info, e))
			current = current->left;
		else
			current = current->right;
	}

	return current->info;
}


//WC=O(n) when we have a degenerate tree and we need to get to the leaf - we need to parse through all of its other nodes as well
//BC=O(1) when the tree has a size of 1 (only contains the root)
//AC=O(log n)
void SortedIndexedList::decrease(int i) const
{
	if (i >= this->sizeBST || i < 0)
		throw(exception());

	node* current = this->root;
	int position = 0;
	while (current)
	{
		if (i == position + current->nrLeft)
			return;
		if (i < position + current->nrLeft)
		{
			//left
			current->nrLeft--;
			current = current->left;
		}
		else
		{
			//right
			position = position + current->nrLeft + 1;
			current = current->right;
		}
	}

}


//WC=O(n) when we have a degenerate tree and the minimum/maximum is a leaf - we need to parse through all of its nodes once
//BC=O(1) when the tree has a size of 1 (only contains the root)
//AC=O(log n)
int SortedIndexedList::getRange() const
{
	if (this->sizeBST == 0) return -1;
	TComp min, max;
	node* current = this->root;
	while (current->left) current = current->left;
	min = current->info;
	current = this->root;
	while (current->right) current = current->right;
	max = current->info;
	return max - min;
}


//WC=O(n^2) when we have a degenerate tree and we need to get to the leaf - we need to parse through all of its other nodes as well - and the parent function has a worst time complexity
//BC=O(n) when the parent funcion has a best case complexity
//AC=O(log^2 n)
TComp SortedIndexedList::successor(TComp e)
{
	node* current = this->root;
	while (current->info != e)
	{

		if (this->R(e, current->info)) current = current->left;
		else current = current->right;

	}
	if (current->right)
	{
		current = current->right;
		while (current->left)
			current = current->left;
		return current->info;
	}
	else
	{
		int p = this->parent(current->info);
		node* parent = this->root;

		while (parent->info != p)
		{

			if (this->R(p, current->info)) current = current->left;
			else current = current->right;

		}

		while (parent && parent->left != current)
		{
			current = parent;
			int p = this->parent(current->info);
			node* parent = this->root;

			while (parent->info != p)
			{

				if (this->R(p, current->info)) current = current->left;
				else current = current->right;

			}
		}
		return p;
	}
}


//WC=O(n) when we have a degenerate tree and the node we need is a leaf (we have to parse through all of its nodes)
//BC=O(1) when the node we need is the root
//AC=O(log n)
int SortedIndexedList::search(TComp e) const {
	node* current = this->root;
	int position = 0;
	while (current != NULL)
	{
		//return position
		if (current->info == e)return position + current->nrLeft;
		if (this->R(e, current->info)) current = current->left;
		else
		{
			position = position + current->nrLeft + 1;
			current = current->right;
		}
	}
	return -1;
}	


//WC=O(n) when we have a degenerate tree and we add the node at the end (it will be a leaf) - we need to parse through all of its other nodes
//BC=O(1) when the node we need is the root
//AC=O(log n)
void SortedIndexedList::add(TComp e) {
	node* newNode = new node;
	newNode->info = e;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->nrLeft = 0;
	if (root == NULL)
		root = newNode;
	else
	{
		node* current = this->root;
		while (current)
		{
			if (this->R(e, current->info))
			{
				current->nrLeft++;
				if (current->left == NULL)
				{

					current->left = newNode;
					current = NULL;
				}
				else current = current->left;
			}
			else
			{
				//current->nrRight++;
				if (current->right == NULL)
				{
					current->right = newNode;
					current = NULL;
				}
				else current = current->right;
			}
		}
	}
	this->sizeBST++;
}


//BC=AC=WC=Theta(1)
ListIterator SortedIndexedList::iterator() {
	return ListIterator(*this);
}

//BC=AC=WC=Theta(1)
SortedIndexedList::~SortedIndexedList() {
	while (!this->isEmpty())this->remove(0);
}



void SortedIndexedList::filter(Condition cond)
{
	SortedIndexedList filteredList(this->R);

	// Iterate over the elements in the original list
	ListIterator iterator = this->iterator();
	while (iterator.valid())
	{
		TComp element = iterator.getCurrent();
		if (cond(element))
		{
			// If it satisfies the condition, add it to the filtered list
			filteredList.add(element);
		}
		iterator.next();
	}

	while (!this->isEmpty())
		this->remove(0);

	// Copy the elements from the filtered list back to the original list
	ListIterator filteredIterator = filteredList.iterator();
	while (iterator.valid())
	{
		TComp element = iterator.getCurrent();
		this->add(element);
		iterator.next();
	}
}
