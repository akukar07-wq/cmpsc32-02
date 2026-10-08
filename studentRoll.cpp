#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node* newNode = new Node();
  newNode->s = new Student(s);
  newNode->next = nullptr;
  if (head == nullptr) 
  {
    head = tail = newNode;
  } 
  else 
  {
    tail->next = newNode;
    tail = newNode;
  }
}

std::string StudentRoll::toString() const {
  std::string str = "[";
  Node* current = head;
  while (current != nullptr) {
    str+= current->s->toString();
    current = current->next;
    if(current !=nullptr)
    {
      str+=",";
    }
   }
   str+="]";
  return str;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
  head = nullptr;
  tail = nullptr;
    Node* current = orig.head;

    while (current != nullptr) {
        insertAtTail(*(current->s));
        current = current->next;
    }
}

StudentRoll::~StudentRoll() {
   Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->s;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;  
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->s;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;

  Node* curr = right.head;

    while (curr != nullptr) {
        insertAtTail(*(curr->s));
        curr = curr->next;
    }


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





