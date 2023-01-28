/*
Project Description: This program creates a templated linked list from scratch. The linked list 
contains the following methods: a constructor, destructor, a method that creates a node 
containing data that adds the data to the front of the list, a method that creates a 
node containing data that adds the data to the back of the list, a method that creates a
node containing data and adds it to the list at a given index, a method that removes
the first item and returns its contents, a method that removes the last item and returns
its contents, a method that finds the first instance of data and removes it, a method 
that finds each instance of data and removes it, a method that returns a T/F if given 
data exists in the list, a method that searches for data in the list and returns a 
pointer to its node, a method that returns an index of the item in the list, a method 
that returns the data contained in the first node, a method that returns the data 
contained in the last node, a method that returns the data contained in a node given an 
index, a method that creates an array from the contents of the list, a method that empties
out the list, and a method that displays how many elements are in the list. The node 
class contains a constructor, destructor, getters & setters. 
*/

#ifndef LIST_H
#define LIST_H
#include <iostream>

template <class T> class Node {
    private:
    template<class U>friend class linkedList;
    public:
    T data;
    Node<T>* next;
    Node() {
        this->next = NULL;
    }
};

template <class T> class linkedList {
    public:
    Node<T> *head, *tail;
    int listLength;
   
    linkedList(){
        this->head = NULL;
    };

  void AddToFront(T data);

  void AddToEnd(T item);

  bool AddAtIndex(T data, int index);

  T RemoveFromFront();
  T RemoveFromEnd();

  void RemoveTheFirst(T data);

  void RemoveAllOf(T data);

  bool ElementsExist(T data);

  Node<T>* Find(T data);
  int IndexOfT(T data);
  T RetrieveFront();

  T RetrieveEnd();

  T Retrieve(int index);

  T* ToArray();

  void Empty();
  int Length();

  void Display();
};
#endif
