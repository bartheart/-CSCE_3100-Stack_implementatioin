#include "stack.hpp"

using namespace std;

template<class T>
void Stack<T>::push(T c){
  //always push the node on the top of the stack/linked-list
  //dinalically allocate for the new node and set the member varaibles
  Node<T>* newNode = new Node<T>();
  newNode->item = c;
  newNode->next = top;
  //assign the top pointer to the new node
  top = newNode;
  //incerement list size
  list_size++;

}

template<class T>
T Stack<T>::pop(){
  if (isEmpty()){
     cout<<"Cannot pop. Stack empty."<<endl;
  }
  // Store the item at the top of the stack
  T popped = top->item;
  
  // Move the top of the stack to the next element
  Node<T>* old_top = top;
  top = top->next;
  
  // Deallocate memory for the old top element
  delete old_top;
  
  // Decrease the size of the stack by 1
  list_size--;
  
  // Return the item that was popped
  return popped;
}

template<class T>
bool Stack<T>::isEmpty(){
  //list is empty if top doesnt exist
  return top == NULL;
}

/* less efficient
bool Stack<T>::isEmpty(){
  bool empty = true;
  if (list_size > 0){
    empty = false;
  }
  return empty;
}*/

template<class T>
T Stack<T>::peek(){
  if(isEmpty()){
    cout<<"Cannot peek. Stack empty."<<endl;
  }
  
  return top->item;
}

template<class T>
int Stack<T>::size(){
  return list_size;
}

template<class T>
void Stack<T>::display(){
  Node<T> *head = top;
  while(head != NULL){
    head = head->next;
    cout << head->item << ", ";
  }
  cout<<endl;
}

template class Stack<char>;
template class Stack<int>;
