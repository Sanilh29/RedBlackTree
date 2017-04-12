#include "RBT.h"
#include <iostream>

using namespace std;

RBT::RBT(){
  head = NULL;
}

RBT::~RBT(){

}

void RBT::rotateRight(){

}

void RBT::rotateLeft(){

}

void RBT::add(Node* current, int indent){

}

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

Node* RBT::getHead(){
  return head;
}
