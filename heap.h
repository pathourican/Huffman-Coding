/*
  Patrick Hourican
  pjh4as
  11/9/2020
  heap.h
*/

#ifndef HEAP_H
#define HEAP_H

#include "huffmanNode.h"

#include <vector>
using namespace std;

class heap {
public:
    heap();
  ~heap();
  //binary_heap(vector<huffmanNode*> vec);
  //~binary_heap();

    void insert(huffmanNode* x);
    huffmanNode* findMin();
    huffmanNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

    vector<huffmanNode*> huffHeap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
