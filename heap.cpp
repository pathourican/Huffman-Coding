
#include <iostream>
#include "heap.h"
using namespace std;

/*
  Patrick Hourican
  pjh4as
  11/9/2020
  heap.cpp
 
  I used the binary_heap.cpp file from the class slides, and changed it to work with the 
  huffmanNode class I created. I kept Professor Bloomfields name on my file above
  as my citation.
*/

// default constructor
/*binary_heap::binary_heap() : heap_size(0) {
    heap.push_back(0);
}

// builds a heap from an unsorted vector
binary_heap::binary_heap(vector<huffmanNode*> vec) : heap_size(vec.size()) {
    heap = vec;
    heap.push_back(heap[0]);
    heap[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}
*/

heap::heap() {
  heap_size = 0;
  huffmanNode* newNode = new huffmanNode();
  huffHeap.push_back(newNode);
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode* x) {
    // a vector push_back will resize as necessary
    huffHeap.push_back(x);

    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    huffmanNode* x = huffHeap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->freq < huffHeap[hole/2]->freq); hole /= 2) {
        huffHeap[hole] = huffHeap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    huffHeap[hole] = x;
}

huffmanNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffmanNode* ret = huffHeap[1];
    // move the last inserted position into the root
    huffHeap[1] = huffHeap[heap_size--];
    // make sure the vector knows that there is one less element
    huffHeap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
     }
    // return the old root node
    return ret;
}

void heap::percolateDown(int  hole) {
    // get the value to percolate down
    huffmanNode* x = huffHeap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (huffHeap[child+1]->freq < huffHeap[child]->freq)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->freq > huffHeap[child]->freq) {
            huffHeap[hole] = huffHeap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    huffHeap[hole] = x;
}

huffmanNode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return huffHeap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    huffHeap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << huffHeap[0]->charVal << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << huffHeap[i]->charVal << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}
