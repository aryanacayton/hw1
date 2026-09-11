#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val)
{

  if (head_ == NULL)
  {
    head_ = new Item();
    tail_ = head_;

    tail_->val[0] = val;
  }

  else if (tail_->last < ARRSIZE)
  {
    tail_->val[tail_->last] = val; 
  }

  else
  {
    Item* newItem = new Item();
    newItem->prev = tail_;
    tail_->next = newItem; 
    tail_ = newItem; 
    tail_->val[0] = val;
  }

  tail_->last++; 
  size_++;

}


/**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back()
{

  if (head_ == NULL)
  {
    return;
  }

  tail_->last--;
  size_--;

  if (tail_->first == tail_->last)
  {
    Item* temp = tail_;

    if (tail_ == head_)
    {
      head_ = nullptr; 
      tail_ = nullptr; 
    }

    else
    {
      tail_ = tail_->prev;
      tail_->next = nullptr; 
    }

    delete temp; 
  }

}

 /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val)
{

  if (head_ == nullptr)
  {
    head_ = new Item();
    tail_ = head_; 

    head_->val[0] = val;
    head_->last++;

  }

  else if(head_->first > 0)
  {
    head_->first--;
    head_->val[head_->first] = val;
  }

  else
  {
    Item* newItem = new Item();
    newItem->next = head_; 
    head_->prev = newItem;
    head_ = newItem;

    head_->val[0] = val; 
    head_->last++;
  }

  size_++;
}


 /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front()
{
  if (head_ == NULL)
  {
    return;
  }

  head_->first++;
  size_--;

  if (head_->first == head_->last)
  {
    Item* temp = head_;

    if (tail_ == head_)
    {
      head_ = nullptr; 
      tail_ = nullptr; 
    }

    else
    {
      head_ = head_->next;
      head_->prev = nullptr; 
    }

    delete temp; 
  }

}


 /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}


std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}


//getValAtLoc is a private helper function which will 
//return a pointer to the i-th value in the entire list 
//(not just in a single Item’s array) and is used in 
//several other member functions. If a non-existent 
//location provided to getValAtLoc should cause it to 
//return NULL.
std::string* ULListStr::getValAtLoc(size_t loc) const
{

  if (loc >= size_)
  {
    return NULL;
  }

  Item* temp = head_;
  size_t count = 0;

  while (temp != nullptr)
  {
    size_t diff = temp->last - temp->first;

    if (loc < count + diff)
    {
      return &(temp->val[temp->first + (loc-count)]);
    }

    count += diff;
    temp = temp->next; 
  }

  return NULL; 
  
}
  

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
