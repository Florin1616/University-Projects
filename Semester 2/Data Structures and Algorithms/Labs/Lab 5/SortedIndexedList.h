#pragma once
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
class ListIterator;
typedef int TComp;
typedef bool (*Relation)(TComp, TComp);
typedef bool(*Condition)(TComp);
#define NULL_TCOMP -11111
struct node { 
	TComp info; 
	node* left; 
	node* right; 
	int nrLeft; 
};

class SortedIndexedList {
private:
	friend class ListIterator;
private:
	node* root;
	Relation R;
	int sizeBST;
public:
	// constructor

	SortedIndexedList(Relation r);

	// returns the size of the list
	int size() const;

	//checks if the list is empty
	bool isEmpty() const;

	// returns an element from a position
	//throws exception if the position is not valid
	TComp getElement(int pos) const;

	// adds an element in the sortedList (to the corresponding position)
	void add(TComp e);

	// removes an element from a given position
	//returns the removed element
	//throws an exception if the position is not valid
	TComp remove(int pos);

	// searches for an element and returns the first position where the element appears or -1 if the element is not in the list
	int search(TComp e) const;

	//returns the successor of a given element
	TComp successor(TComp e);

	//returns the parent of a given element
	TComp parent(TComp e);

	//modifies the position of the elements after the deletion of a node
	void decrease(int i) const;

	//returns the difference between the maximum and the minimum element (assume integer values)
	//if the SortedList is empty the range is -1
	int getRange() const;

	// returns an iterator set to the first element of the list or invalid if the list is empty
	ListIterator iterator();

	//destructor
	~SortedIndexedList();

	void filter(Condition cond);
};