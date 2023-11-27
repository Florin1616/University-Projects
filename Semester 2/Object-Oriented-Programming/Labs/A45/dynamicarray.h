#pragma once
#include "domain.h"

template <typename TElem>
//
//class DynamicVectorIterator {
//	friend class DynamicVector<TElem>;
//
//	private:
//	const DynamicVector<TElem>& vector;
//	int currentPosition;
//
//	public:
//		DynamicVectorIterator(const DynamicVector<TElem>& vector) : vector{ vector } {
//			this->currentPosition = 0;
//		}
//		void first() {
//			this->currentPosition = 0;
//		}	
//		void next() {
//			if (this->currentPosition == this->vector.getSize())
//				throw std::exception();
//			this->currentPosition++;
//		}
//
//		bool valid() {
//			return this->currentPosition < this->vector.getSize();
//		}
//
//		TElem& getCurrent() {
//			return this->vector.getElement(this->currentPosition);
//		}
//
//};

//template <typename TElem>


class DynamicVector {
private:
	TElem* elements;
	int size;
	int capacity;
	void resize();
public:
	DynamicVector();
	DynamicVector(const DynamicVector&);
	~DynamicVector();


	void addElem(const TElem element);
	void deleteElem(int delete_index);
	void updateElem(int update_index, TElem element);
	int getCapacity() const;
	int getSize() const;
	TElem& getElement(int position) const;
	TElem* getAll();
	
};
template <typename TElem>
DynamicVector<TElem>::DynamicVector() {

	this->size = 0;
	this->capacity = 10;
	this->elements = new TElem[10];
}

template <typename TElem>
DynamicVector<TElem>::~DynamicVector() {
	delete[] this->elements;
}

template <typename TElem>
void DynamicVector<TElem>::addElem(TElem element) {
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = element;
	this->size++;
}


template <typename TElem>
int DynamicVector<TElem>::getCapacity() const {
	return this->capacity;
}

template <typename TElem>
int DynamicVector<TElem>::getSize() const {
	return this->size;
}


template <typename TElem>
TElem* DynamicVector<TElem>::getAll() {
	return this->elements;
}

template <typename TElem>
void DynamicVector<TElem>::resize() {
	auto* newElems = new TElem[this->capacity * 2];
	int index;
	for (index = 0; index < this->capacity; index++) {
		newElems[index] = this->elements[index];
	}
	delete[] this->elements;
	this->elements = newElems;
	this->capacity *= 2;
}

template <typename TElem>
void DynamicVector <TElem> ::updateElem(int update_index, TElem update_element) {
	this->elements[update_index] = update_element;
}


template <typename TElem>
void DynamicVector<TElem>::deleteElem(int index) {
	if (index < 0 || index >= this->size)
		throw exception("The element does not exist! ");
	for (int i = index; i < this->size - 1; i++) {
		this->elements[i] = this->elements[i + 1];
	}
	this->size--;
}

template <typename TElem>
TElem& DynamicVector<TElem>::getElement(int position) const {
	if (position >= this->size || position < 0)
	{
		throw exception("The searched position is not valid");
	}
	return this->elements[position];
}

template<class TElem>
DynamicVector<TElem>::DynamicVector(const DynamicVector& dynamicVector)
{
	this->capacity = dynamicVector.capacity;
	this->size = dynamicVector.size;

	this->elements = new TElem[this->capacity];

	if (this->elements == nullptr)
		return;

	for (int i = 0; i < this->size; i++)
		this->elements[i] = dynamicVector.elements[i];
}



//template <class TElem>
//DynamicVector<TElem>::DynamicVector(const DynamicVector& dynamicVector) {
//	this->capacity = dynamicVector.capacity;
//	this->size = dynamicVector.size;
//
//	this->elements = new TElem[this->capacity];
//
//	if (this->elements == nullptr)
//		return;
//
//	for (int i = 0; i < this->size; i++)
//		this->elements[i] = dynamicVector.elements[i];
//}