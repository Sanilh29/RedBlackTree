
class RBT{
 public:
  RedBlackTree();
  ~RedBlackTree();
  rotateRight();
  rotateLeft();
  print(Node* current, int indent = 0);
  add(Node* current, int data);
  Node* getHead();
 private:
  Node* head;
  

}
