//sanil hattangadi. header for the RBT that creates the variables and methods
#include "Node.h"

class RBT{
 public://all the methods
  RBT();//constructor
  ~RBT();//deconstructor
  void rotateRight(Node* current);
  void rotateLeft(Node* current);
  void print(Node* current, int indent = 0);
  void add(Node* current, int data);
  void fixTree(Node* current, Node* &head);
  Node* getHead();
 private://the variables
  Node* head;
};
