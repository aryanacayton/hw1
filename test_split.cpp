/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

  //create in 
   Node* n9 = new Node(9, NULL);
   Node* n8 = new Node(8, n9);
   Node* n7 = new Node(7, n8);
   Node* n6 = new Node(6, n7);
   Node* n5 = new Node(5, n6);
   Node* n4 = new Node(4, n5);
   Node* n3 = new Node(3, n4);
   Node* n2 = new Node(2, n3);
   Node* n1 = new Node(1, n2);

  //create odds and evens 
  Node* odds = nullptr; 
  Node* evens = nullptr; 

  //set in
  Node* in = n1; 


  //call split 
  split(in, odds, evens);


  //print out odds 
  cout << "Odds: ";

  Node* temp = odds;
  
  while (temp != NULL)
  {
    cout << temp->value << ", "; 
    temp = temp->next;
  }

  cout << endl; 


  //print out evens 
  cout << "Evens: ";

  Node* t = evens;
  
  while (t != NULL)
  {
    cout << t->value << ", "; 
    t = t->next;
  }

  cout << endl; 


  bool inNull = false; 

  if (in == NULL)
  {
    inNull = true;
  }

  cout << inNull << endl;



  //Delete odds 
  while (odds != NULL)
  {
    Node* nO = odds; 
    odds = odds->next;
    delete nO;
  }


  //Delete evens 
  while (evens != NULL)
  {
    Node* nE = evens; 
    evens = evens->next;
    delete nE;
  }

  return 0;

}
