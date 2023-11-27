#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c) : col(c)
{
	//TODO - Implementation
	this->first();
}

TElem MultiMapIterator::getCurrent() const
{
	if (!this->valid())
		throw std::exception();

	return this->currentNode->data;
}

bool MultiMapIterator::valid() const
{
	return this->currentIndex >= 0 && this->currentIndex < col.capacity;
}

void MultiMapIterator::next()
{
	if (!this->valid())
		throw std::exception();

	this->currentNode = this->currentNode->next;

	while (this->currentNode == nullptr && this->currentIndex < col.capacity)
	{
		this->currentIndex++;
		this->currentNode = col.elements[this->currentIndex];
	}
}

void MultiMapIterator::first()
{
	this->currentIndex = 0;
	this->currentNode = col.elements[0];

	while (this->currentNode == nullptr && this->currentIndex < col.capacity)
	{
		this->currentIndex++;
		this->currentNode = col.elements[this->currentIndex];
	}
}

