// =================================================================
//
// File: heap.h
// Authors: Daniel Emilio Fuentes Portaluppi -  A01708302
//          José Diego Llaca Castro - A01704793
//		    Ivan Ricardo Paredes Aviles - A01705083
//
// Description: This file contains the implementation of TDA Heap
//				(in this case is MIN-HEAP).
//
// =================================================================

#ifndef MINHEAP_H
#define MINHEAP_H

#include <climits>
#include <sstream>
#include <cmath>
#include <vector>

typedef unsigned int uint;
// =================================================================
// Definition of the MinHeap class
// =================================================================
template <class T>
class MinHeap {
private:
	std::vector<T> data;

	uint parent(uint) const;
	uint left(uint i) const;
	uint right(uint i) const;

	void swap(uint, uint);

public:
	MinHeap() {};

	uint size() const;
	bool empty() const;

	void heapify(uint);

	T top() const;
	void push(const T);
	int pop();

	std::string toString() const;
	std::string byLevel() const;
};

// =================================================================
// Returns the position of the parent of an element in the heap
//
// @complexity: O(1)
// @param i position of the element in the heap
// @returns position of the parent of the element in the heap
// =================================================================
template <class T>
uint MinHeap<T>::parent(uint i) const {
	return (i - 1) / 2;
}

// =================================================================
// Returns the position of the left child of an element in the heap
//
// @complexity: O(1)
// @param i position of the element in the heap
// @returns position of the left child of the element in the heap
// =================================================================
template <class T>
uint MinHeap<T>::left(uint i) const {
	return 2 * i + 1;
}

// =================================================================
// Returns the position of the right child of an element in the heap
//
// @complexity: O(1)
// @param i position of the element in the heap
// @returns position of the right child of the element in the heap
// =================================================================
template <class T>
uint MinHeap<T>::right(uint i) const {
	return 2 * i + 2;
}

// =================================================================
// Returns if the heap is empty or not.
//
// @complexity O(1)
// @returns True is the amount of elements is 0 (empty). False,
//			otherwise.
// =================================================================
template <class T>
bool MinHeap<T>::empty() const {
	return data.empty();
}

// =================================================================
// Returns the number of elements in the heap
//
// @complexity O(1)
// @returns the number of elements in the heap.
// =================================================================
template <class T>
uint MinHeap<T>::size() const {
	return data.size();
}

// =================================================================
// Swap the content of two locations.
//
// @complexity O(1)
// @param i, j, indeces to be swapped.
// =================================================================
template <class T>
void MinHeap<T>::swap(uint i, uint j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

// =================================================================
// Place the item in the correct position. In this case, since it is
// a min-heap, its children must be greater than the element.
//
// complexity O(log n)
// @param pos, position to be checked.
// =================================================================
template <class T>
void MinHeap<T>::heapify(uint pos) {
	uint le = left(pos);
	uint ri = right(pos);
	uint min = pos;

	if ((le < data.size()) && (data[le] < data[min])) {
		min = le;
	}
	if ((ri < data.size()) && (data[ri] < data[min])) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

// =================================================================
// Returns the top element of the heap.
//
// @complexity O(1)
// @returns the top element of the heap.
// =================================================================
template <class T>
T MinHeap<T>::top() const {
	if (empty()) {
		return INT_MAX;
	}
	else {
		return data[0];
	}
}

// =================================================================
// Inserts a new element in the heap.
//
// @complexity O(log n)
// @param value, the value to be inserted.
// =================================================================
template <class T>
void MinHeap<T>::push(const T item) {
	data.push_back(item);
	uint pos = data.size() - 1;
	while ((pos > 0) && (data[parent(pos)] > data[pos])) {
		swap(pos, parent(pos));
		pos = parent(pos);
	}
}

// =================================================================
// Removes the top element of the heap.
//
// @complexity O(log n)
// @returns the top element of the heap.
// =================================================================
template <class T>
int MinHeap<T>::pop() {
	if (empty()) {
		return INT_MAX;
	}
	else {
		T item = data[0];
		data[0] = data[data.size() - 1];
		data.pop_back();
		heapify(0);
		return item;
	}
}

// =================================================================
// Return a string representation of the heap.
//
// @returns, a string with the elements of the heap.
// =================================================================
template <class T>
std::string MinHeap<T>::toString() const {
	std::stringstream aux;
	for (uint i = 0; i < data.size(); i++) {
		aux << data[i] << " ";
	}
	return aux.str();
}

// =================================================================
// Return a string representation of the heap by level.
//
// @returns, a string with the elements of the heap.
// =================================================================
template <class T>
std::string MinHeap<T>::byLevel() const {
	std::stringstream aux;
	uint level = 0;
	uint count = 0;
	uint max = 1;
	for (uint i = 0; i < data.size(); i++) {
		aux << data[i] << " ";
		count++;
		if (count == max) {
			aux << std::endl;
			level++;
			count = 0;
			max = pow(2, level);
		}
	}
	return aux.str();
}

#endif
