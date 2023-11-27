
#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)
class MultiMapIterator;

class Node
{
public:
	TElem data;
	Node* next;
	Node(TElem& data, Node* next)
	{
		this->data = data;
		this->next = next;
	};
	Node()
	{
		this->data = NULL_TELEM;
		this->next = nullptr;
	};

	Node& operator = (const Node& node)
	{
		this->data = node.data;
		this->next = node.next;
		return *this;
	};

	TElem getData() const { return this->data; };
	Node* getNext() const { return this->next; };

	void setData(TElem& newData) { this->data = newData; };
	void setNext(Node* next) { this->next = next; };
};

class MultiMap
{
	friend class MultiMapIterator;

private:
	//TODO - Representation
	int numberOfElements;
	int capacity;
	Node** elements;

	int hash(TKey key) const;

public:
	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//descturctor
	~MultiMap();

	vector<TValue> removeKey(TKey key);

};

