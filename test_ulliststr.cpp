#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

  ULListStr item1;

  //creating and testing on empty list
  cout << "Empty: " << item1.empty() << endl;
  cout << "Size: " << item1.size() << endl;

  item1.push_back("H");

  cout << "Front: " << item1.front() << " and Back: " << item1.back() << "are the same. " << endl;

  item1.pop_back();
  cout << "Now the list is empty again: " << item1.size() << endl;
  
  //pop_back() on an empty list 
  item1.pop_back();

  item1.push_front("Q");

  cout << "Front: " << item1.front() << " and Back: " << item1.back() << "are the same AGAIN. " << endl;

  item1.pop_front();
  cout << "Now the list is empty again: " << item1.size() << endl;

  //pop_front() on an empty list 
  item1.pop_front();


  ULListStr item2; 

  item2.push_back("L");
  item2.push_back("P");
  item2.push_front("G");
  item2.push_front("F");

  item2.push_back("Y");
  item2.push_back("C");
  item2.push_back("B");
  item2.push_back("M");
  item2.push_front("U");
  item2.push_front("X");
  item2.push_front("R");


  cout << "Front: " << item2.front() << endl;
  cout << "Back: " << item2.back() << endl;
  cout << "Size: " << item2.size() << endl;

  cout << "Index 0: " << item2.get(0) << endl;
  cout << "Index 8: " << item2.get(8) << endl;

  item2.set(0, "Z");

  cout << "Index 0: " << item2.get(0) << endl;
  cout << "Index 5: " << item2.get(5) << endl;

  item2.pop_back();
  item2.pop_front();
  item2.pop_back();
  item2.pop_front();
  item2.pop_back();
  item2.pop_back();
  item2.pop_back();
  item2.pop_back();

  cout << "Now the size is: " << item2.size() << " and it is empty: " << item2.empty() << endl;


  ULListStr item3; 

  for (int i = 0; i < 11; i++)
  {
    item3.push_back("G");
  }

  cout << "Front: " << item3.front() << endl;
  cout << "Back: " << item3.back() << endl;
  cout << "Size: " << item3.size() << endl;

  cout << "Index 10: " << item3.get(10) << endl;

  return 0;

}
