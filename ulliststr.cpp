#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

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

void ULListStr::Item::addFront(const std::string& e){
    if(size == ARRSIZE)
        return;
    else{
        first = first==0 ? ARRSIZE-1 : first-1;
        val[first] = e;
    }
    size ++;
}

void ULListStr::Item::addBack(const std::string& e){
    if(size == ARRSIZE)
        return;
    else{
        val[last] = e;
        last = last+1==ARRSIZE ? 0 : last + 1;
    }
    size ++;
}

void ULListStr::Item::removeFront(){
    if(size == 0) return;
    first = first+1==ARRSIZE ? 0 : first + 1;
    size --;
}

void ULListStr::Item::removeBack(){
    if(size == 0) return;
    last = last==0 ? ARRSIZE-1 : last - 1; 
    size --;
}

void ULListStr::push_back(const std::string& val){
    if(empty()){
        head_ = tail_ = new Item();
        tail_->addBack(val);
        size_ ++;
        return;
    }

    if(tail_->size == ARRSIZE){
        Item* newitem = new Item();
        tail_->next = newitem;
        newitem->prev = tail_;
        tail_ = tail_->next;
    }

    tail_->addBack(val);
    size_ ++;
}

void ULListStr::pop_back(){
    if(empty())
        return;
    else if(size() == 1){
        delete head_;
        head_ = tail_ = NULL;
    }
    else{
        if(tail_->size == 1){
            tail_ = tail_->prev;
            delete tail_->next;
            tail_->next = NULL;
        }
        else
            tail_->removeBack();
    }

    size_ --;
}

void ULListStr::push_front(const std::string& val){
    if(empty()){
        head_ = tail_ = new Item();
        head_->addFront(val);
        size_ ++;
        return;
    }

    if(head_->size == ARRSIZE){
        Item* newitem = new Item();
        head_->prev = newitem;
        newitem->next = head_;
        head_ = head_->prev;
    }

    head_->addFront(val);
    size_ ++;
}

void ULListStr::pop_front(){
    if(empty())
        return;
    else if(size() == 1){
        delete head_;
        head_ = tail_ = NULL;
    }
    else{
        if(head_->size == 1){
            head_ = head_->next;
            delete head_->prev;
            head_->prev = NULL;
        }
        else
            head_->removeFront();
    }

    size_ --;
}

const std::string & ULListStr::front() const{
    return head_->val[head_->first];
}

const std::string & ULListStr::back() const{
    return tail_->val[tail_->last == 0 ? ARRSIZE-1 : tail_->last-1];
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

std::string* ULListStr::getValAtLoc(size_t loc) const{
    if(loc >= size())
        return NULL;

    Item* curr = head_;

    while(loc >= curr->size){
        loc -= curr->size;
        curr = curr->next;
    }

    // pointer arithmetic, use offset to find the correct position
    return curr->val + ((curr->first + loc) % ARRSIZE); 
}