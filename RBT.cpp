
using namespace std;

void RBT::print(Node* current, int indent){
  if(current->getRight()){
    print(current->getRight(), indent+1);
  }
  for (int i = 0; i < indent; i++){
    cout << "  ";
  }
  cout << current->getData() << endl;
  if(current->getLeft()){
    print(current->getLeft(), indent+1);
  }
}

Node* RedBlackTree::getHead(){
  return head;
}
