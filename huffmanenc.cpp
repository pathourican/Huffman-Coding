/*
  Patrick Hourican
  pjh4as
  11/9/2020
  huffmanenc.cpp

  Source: Professor Mark Floryan's 11am recorded lecture from 11/6/2020. 
*/

#include "heap.h"
#include "huffmanNode.h"

#include <iostream>
#include <fstream>

#include <unordered_map>

using namespace std;

void getPrefixCodes(huffmanNode* curr, string code);

unordered_map<char, int> wordFreq;

unordered_map<char, string> preCodes;

int size = 0;

string compressedString = "";

int main(int argc, char** argv) {
  
  if(argc != 2) {
    exit(1);
  }

  // BUILD HASHMAP------------------------------------------------

  ifstream file(argv[1]);

  char c;
    
    while(file.get(c)) {
     if(c>=32 && c<=126) {
       size++;
       if(wordFreq.find(c) == wordFreq.end()) {
	 wordFreq[c]=1;
       } else {
	 wordFreq[c]++;
       }
     } 
   }
  

  // BUILD HEAP---------------------------------------------------------
  
  heap huffmanHeap;
  
  unordered_map<char, int>::iterator itr;

  for(itr = wordFreq.begin(); itr != wordFreq.end(); itr++) {
    huffmanNode* newNode = new huffmanNode();

    newNode->charVal = itr->first;
    newNode->freq = itr->second;

    huffmanHeap.insert(newNode);
  }

  wordFreq.clear();


  // BUILD PRIORITY QUEUE ------------------------------------------------
  while(huffmanHeap.size() > 1) {
    
    huffmanNode* node1 = huffmanHeap.deleteMin();
    huffmanNode* node2 = huffmanHeap.deleteMin();

    huffmanNode* parent = new huffmanNode();
    parent->charVal = '-';
    parent->left=node1;
    parent->right=node2;
    parent->freq=(node1->freq+node2->freq);
  
    huffmanHeap.insert(parent);
  }

  // PUT PREFIX CODES IN A HASHMAP --------------------------------------
  getPrefixCodes(huffmanHeap.findMin(), "");

  /*
  // PRINT OUT PREFIX CODES ---------------------------------------------
  unordered_map<char, string>::iterator itr2;

  for(itr2 = preCodes.begin(); itr2 != preCodes.end(); itr2++) {
    cout << itr2->first;
    cout << " ";
    cout << itr2->second << endl;
  }
  */

   cout << "----------------------------------------" << endl;
   
   ifstream file2(argv[1]);
   
   char c2;

   while(file2.get(c2)) {
     if(c2>=32 && c2<=126) {
       compressedString+=preCodes[c2];
       cout << preCodes[c2] << " " ;
     }
   }

   cout << endl;

   cout << "----------------------------------------" << endl;

   float bits = size*8;
   float compBits = compressedString.length();
   float compRatio = bits/compBits;
   float costBits = compBits/size;

   cout << "There are a total of " << size  << " symbols that are encoded." << endl;
   cout << "There are " << preCodes.size()  << " distinct symbols used." << endl;
   cout << "There were " << bits << " bits in the original file." << endl;
   cout << "There were " << compBits  << " bits in the compressed file." << endl;
   cout << "This gives a compression ratio of " << compRatio  << "." << endl;
   cout << "The cost of the Huffman tree is " << costBits  << " bits per character." << endl;
  
}
void getPrefixCodes(huffmanNode* curr, string code) {
  if(curr->left==NULL && curr->right==NULL) {
    cout << curr->charVal << " " << code << endl;
    preCodes[curr->charVal] = code;
  } else {
    getPrefixCodes(curr->left, code + "0");
    getPrefixCodes(curr->right, code + "1");
  }
}
