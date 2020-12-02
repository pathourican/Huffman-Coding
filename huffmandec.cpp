/*
  Patrick Hourican
  pjh4as
  11/10/2020
  huffmanec.cpp

  Sources: 
  - Professor Mark Floryan's recorded lecture from 11/9/2020.
  - provided inlab-skeleton.cpp for input of encoded files code in main method.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "huffmanNode.h"

using namespace std;


void createTree(huffmanNode*& curr, char c, string prefix, int i);

huffmanNode* root = NULL;

int main(int argc, char** argv) {
   // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
	char c;
	
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

	
	
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
	
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;

	
	c = character[0];
	
	createTree(root, c, prefix, 0);
    }


    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
    
    string output = "";
    
    huffmanNode* curr = root;
    
    for(int i = 0; i < allbits.length()+1; i++) {
      if(curr->right==NULL && curr->left==NULL) {
	output+=curr->charVal;
	curr = root;
      }
      if(allbits[i] == '0')
	curr = curr->left;
      else if(allbits[i]=='1')
	curr = curr->right;
    }

    cout << output << endl;
}


void createTree(huffmanNode*& curr, char c, string prefix, int i) {
  if(curr==NULL) 
    curr = new huffmanNode();

  if(i==prefix.length()) {
    curr->charVal = c;
    return;
      }
  if(prefix[i] == '0')
    createTree(curr->left, c, prefix, i+1);
  else if(prefix[i] == '1')
    createTree(curr->right, c, prefix, i+1);
}
