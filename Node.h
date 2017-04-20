B
class Node{
 public:
  Node(int newdata);
  Node();
  ~Node();
  Node* getParent();
  Node* getLeft(); //returns the next node
  Node* getRight();
  Node* getUncle();
  int getData(); //returns the student the node points to
  void setLeft(Node* node); //sets the pointer to the next node
  void setRight(Node* node);
  void setParent(Node* node);
  bool checkRed();
  void setRed(bool isRed);
  bool isRight();
  void setIsRight(bool isRight);
 private:
  int data;
  Node* left;
  Node* right; 
  Node* parent;
  bool red;
  bool rightChild;

};
