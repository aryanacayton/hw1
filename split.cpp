#include "split.h"

void split(Node*& in, Node*& odds, Node*& evens)
{

  if (in == nullptr)
  {
    //void function so doesn't return a value 
    return; 
  }

  Node* temp = in; 
  in = in->next; 

  split(in, odds, evens);

  if (temp->value % 2 == 0)
  {
    temp->next = evens;
    evens = temp;
  }

  else
  {
    temp->next = odds;
    odds = temp; 
  }

}


