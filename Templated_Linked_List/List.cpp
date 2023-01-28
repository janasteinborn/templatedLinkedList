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

#include <iostream>
#include "List.h"
using namespace std;


template <class T>
void linkedList<T>::AddToFront(T data) {  
    // create a new node with the data from the user         
    Node<T> *newNode = new Node<T>();
    newNode->data=data;
    newNode->next=NULL;
    // if head is null, head will be the new node
    if (head == NULL) {
        head = newNode;
    }
    // if head is not null, set a new head
    else {
        Node<T> *temp = new Node<T>(); 
        temp = head; // here, temp stores the old head
        head = newNode; 
        head->next = temp; // the head's next node is set to temp
    }
    listLength++; // since an item is being added to the list, increase the length
}

template <class T>
void linkedList<T>::AddToEnd(T item) {  
    // create a new node with the data from the user                
    Node<T>* node = new Node<T>[1];
    node->data = item;
    // if head is null, head will be the new node
    if(head == NULL){
        head = node;
        return;
    } 
    // if head is not null, traverse through the list until the final node is reached, then add item after the last node
    Node<T>* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    listLength++; // since an item is being added to the list, increase the length
}

template <class T>
bool linkedList<T>::AddAtIndex(T data, int index) { 
    // create new nodes to traverse through the list
    Node<T> *prev = new Node<T>();
    Node<T> *current = new Node<T>();
    Node<T> *temp = new Node<T>();

    current = head; // set the current node equal to the head of the list

    // traverse through the list until the index is reached
    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }

    // set nodes to account for the traversal
    temp->data = data;
    prev->next = temp;
    temp->next = current;

    listLength++; // since an item is being added to the list, increase the length
    return true;
}

template <class T>
T  linkedList<T>::RemoveFromFront() {        
    // warn the user if the list is empty
    if(head == NULL) { 
        std::cout << "The list is empty." << std::endl;
        return -1;
    }

    // the following if statement accounts for a one-item list
    if(head->next == NULL) {
        T data= head->data;
        head = NULL;
        std::cout<< "Item has been removed. Updated list:" << std::endl;
        return data;
    }

    // otherwise the list contains more than one item. The following code addresses this case
    T data = head->data;
    head = head->next;
    return data;
}

template <class T>
T linkedList<T>::RemoveFromEnd() { 
    // warn user if there are no items in the list      
    if(head == NULL){
        std::cout<< "There are no items in the list." << std::endl;
        return -1;
    }

    // the following if statement accounts for a one-item list
    if(head->next == NULL) {
        T data= head->data;
        head = NULL;
        std::cout << "Item has been removed. Updated list:" << std::endl;
        return data;
        }

    // otherwise the list contains more than one item. The following code addresses this case
    Node<T>* temp = head;
    while(temp != NULL) {
        if(temp->next->next == NULL) {
            T data = temp->next->data;
            temp->next = NULL;
            std::cout << "Item has been removed. Updated list:" << std::endl;
            return data;
        }
        temp = temp->next;
    }
    return -1;
}

template <class T>
void linkedList<T>::RemoveTheFirst(T data) {    
    // create new nodes to traverse through the list         
    Node<T> *current = new Node<T>();
    Node<T> *prev = new Node<T>();
    current = head;

    // if the list is empty, return
    if (head == NULL) { 
        return;
    }

    // traverse through the list
    while (!(current->data == data) && (current->next != NULL )) {
        prev = current;
        current = current->next;
        }  
        if (current->data == data) { // if the current data is equal to T data, move the head and delete the current data
        if (current == head) {
            head = current-> next;
            delete current;
        }
        else { // otherwise continue traversing through the list
            prev->next = current->next;
            delete current;
        }
        listLength--; // since an item was removed, decrement the listLength
    }  
}

template <class T>
void linkedList<T>::RemoveAllOf(T data) {  
    // the following loops move the head pointer until the head data equals T data. If the pointer equals T data, the data is removed
    while (head && head->data == data) 
        head = head->next;
        Node<T> *curr = head, *prev = nullptr;
        
    while (curr) {
        if (curr->data == data)
            prev->next = curr->next;
        else
            prev = curr;
        curr = curr->next;
    }
}

template <class T>
bool linkedList<T>::ElementsExist(T data) { 
    // create new node to traverse through the list. If the element exists return true, otherwise return false. 
    Node<T> *temp = new Node<T>();
    temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
Node<T>* linkedList<T>::Find(T data) {
    // create new node to traverse through the list 
    Node<T> *temp = new Node<T>();
    temp = head;
    // the following loop traverses through the loop until the end is reached. If T data is found, a pointer to it is returned.
    while (temp != NULL) {
            if (temp->data == data) {
                return temp;
            }
            else {
                temp = temp->next;
            }
    }
    return nullptr;
}          

template <class T>
int linkedList<T>::IndexOfT(T data) {  
    int index = 0;
    // create new node to traverse through the list
    Node<T> *temp = new Node<T>();
    temp = head;

    // the following loop traverses through the loop until the end is reached. If T data is found, its index is returned

    while (temp != NULL) {
        if (temp->data == data) {
            return index;
        }
        else {
            index++;
            temp = temp->next;
            }
            }
    return -1;
}

template <class T>
T linkedList<T>::RetrieveFront() {
    // return the head of the list
    return head->data;
}

template <class T>
T linkedList<T>::RetrieveEnd() {
    // return the tail of the list                 
    return tail->data;
}

template <class T>
T linkedList<T>::Retrieve(int index) {
    // create new node to traverse through the list
    Node<T> *temp = new Node<T>();
    temp = head;

    // the following for loop traverses through the list until the given index is reached
    for (int i = 0; i < index; i++) {
        temp = temp->next;
        }
    return temp->data;
}

template <class T>
T* linkedList<T>::ToArray() {
    // create new node to traverse through the list                      
    Node<T>* temp = new Node<T>();
    temp = head;

    int i=0;
    // create an array the size of the list length
    T* array = new T[listLength];

    // fill the array with data from the list
    while (temp!= NULL) {
        array[i] = temp->data;
        temp=temp->next;
        i++;
        }
        return array;
}

template <class T>
void linkedList<T>::Empty() { 
    // create new node to traverse through the list
    Node<T>* current = head;
    Node<T>* next = NULL;

    // while the list is not empty, traverse through the list and delete elements
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

template <class T>
int linkedList<T>::Length() {          
    // create new node to traverse through the list                                              
    Node<T> *temp = new Node<T>();
    int count = 0;
    temp = head;

    // traverse through the list to count the elements
    while(temp != NULL) {
        count +=1;
        temp=temp->next;
    }
    return count;
}

template <class T>
void linkedList<T>::Display(){ // this function was created to display the elements contained in the list
    Node<T>* temp=head;
    while(temp!=NULL){
        std::cout<< temp->data << " -> ";
        temp=temp->next;
    }
    std::cout<<"\n";
}



int main() {  
    linkedList<int> list;
    int userOption, index, data;
    bool programOff = false;
    do {
    std::cout << "Linked list operations: " << std::endl;
    std::cout << "1 – Add data to front of list" << std::endl;
    std::cout << "2 – Add to end of list" << std::endl;
    std::cout << "3 - Add data at given index" << std::endl;
    std::cout << "4 - Remove data from front of list" << std::endl;
    std::cout << "5 - Remove data from end of list" << std::endl;
    std::cout << "6 - Remove the first instance of X data from the list" << std::endl;
    std::cout << "7 - Remove all of X data from the list" << std::endl;
    std::cout << "8 - Check whether an element exist in the list" << std::endl;
    std::cout << "9 - Find data in a list and return a pointer to its node" << std::endl;
    std::cout << "10 - Find an index of an item in the list" << std::endl;
    std::cout << "11 - Retreive the first item in the list but don't delete it" << std::endl;
    std::cout << "12 - Retrieve the last item in the list but don't delete it" << std::endl;
    std::cout << "13 - Retrieve data contained in node # index" << std::endl;
    std::cout << "14 - Convert the list to an array" << std::endl;
    std::cout << "15 - Empty the list and delete everything" << std::endl;
    std::cout << "16 - Find how many elements are in the list" << std::endl;
    std::cout << "17 - End the program" << std::endl;
    std::cout << "Please choose an option: ";
    std::cin>>userOption;
    switch(userOption) {
    case 1:
        std::cout << "Enter item to insert: " << std::endl;
        std::cin >> data;
        list.AddToFront(data);
        list.Display();
        break;
    case 2:
        std::cout << "Enter item to insert: " << std::endl;
        std::cin >> data;
        list.AddToEnd(data);
        list.Display();
        break;
    case 3:
        std::cout << "Enter item to insert: " << std::endl;
        std::cin >> data;
        std::cout << "Enter the index: " << std::endl;
        std::cin >> index;
        list.AddAtIndex(data, index);
        list.Display();
        break;
    case 4:
        list.RemoveFromFront();
        list.Display();
        break;
    case 5:
        list.RemoveFromEnd();
        list.Display();
        break;
    case 6:
        std::cout << "Enter the item you wish to remove at its first instance from the list: " << std::endl;
        std::cin >> data;
        list.RemoveTheFirst(data);
        list.Display();
        break;
    case 7:
        std::cout << "Enter the item you wish to remove at all instances from the list: " << std::endl;
        std::cin >> data;
        list.RemoveAllOf(data);
        list.Display();
        break;
    case 8:
        std::cout << "Enter the item you're searching for: " << std::endl;
        std::cin >> data;
        if (list.ElementsExist(data) == 1) {
            std::cout << "The element exists in the list." << std::endl;
        }
        else std::cout << "The element does not exist in the list." << std::endl;
        break;
    case 9:
        std::cout << "Enter the item you're searching for: " << std::endl;
        std::cin >> data;
        list.Find(data);
        break;
    case 10:
        std::cout << "Enter the item you want the index of: " << std::endl;
        std::cin >> data;
        std::cout << list.IndexOfT(data)<< std::endl;
        break;
    case 11:
        std::cout<< list.RetrieveFront() << std::endl;
        break;
    case 12:
        std::cout << list.RetrieveEnd() << std::endl;
        break;
    case 13:
        std::cout << "Enter an index: " << std::endl;
        std::cin >> index;
        list.Retrieve(index);
        break;
    case 14:
        list.ToArray();
        break;
    case 15:
        list.Empty();
        break;
    case 16:
        std::cout<< list.Length() << std::endl;
        break;
    case 17:
        std::cout << "The program has been ended." << std::endl;
        programOff=true;
        break;
    default:
        std::cout << "Please choose from the given options." << std::endl;
        break;
    }
    }
    while (!programOff);
    return 0;

}