/*
  Patrick Hourican
  pjh4as
  11/8/20
  huffmanNode.h

  Referenced my AVLNode from lab 5 in for the structure of huffmanNode.h class.
*/

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

class huffmanNode {
 public:
  huffmanNode();
  //~huffmanNode();

  char charVal;
  int freq;
  huffmanNode* left;
  huffmanNode* right;

  friend class heap;

};

#endif
