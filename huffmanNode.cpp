/*
  Patrick Hourican
  pjh4as
  11/8/2020
  huffmanNode.cpp

  Referenced my AVLNode class in lab 5 for the structure of huffmanNode class.
*/

#include "huffmanNode.h"
#include <string>
using namespace std;

huffmanNode::huffmanNode() {
  charVal='\u0000';
  freq=0;
  left=NULL;
  right=NULL;
}

/*huffmanNode::~huffmanNode() {
  delete left;
  delete right;
  left=NULL;
  right=NULL;
}
*/
