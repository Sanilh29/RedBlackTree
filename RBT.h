#include "Node.h"

class RBT{
 public:
  RBT();
  ~RBT();
  void rotateRight();
  void rotateLeft();
  void print(Node* current, int indent = 0);
  void add(Node* current, int data);
  void fixTree(Node* current, Node* &head);
  Node* getHead();
 private:
  Node* head;
};
