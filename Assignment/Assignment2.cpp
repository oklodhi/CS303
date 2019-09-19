#include <iostream>\
#include <string>

using namespace std; 

// 5a and 5b
void insert_before (Node<string>* head, Node<string>* given, string data){
  Node * new_ptr = head; 
  head = new Node("Bill");
  head->next = new_ptr;

  return; 
}

// 5c and 5d
void remove (Node<string>* head, Node<string>* given) {
  if (head->next == given){
    Node<string>* itr = head; 
    head = head->next; 
    delete itr; 
    return;
  } 

  Node<string>* curr = head;
  while (curr->next != NULL){
    if (curr->next->next == given){
      Node<string>* del = curr->next;
      curr->next = curr->next->next;
      delete del;
      return; 
    }
    curr = curr->next; 
  }
}

int main() {
  cout << "Hello World!\n";
}

