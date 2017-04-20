#include "RBT.h"
#include <iostream>

using namespace std;

RBT::RBT(){
  head = NULL;
}

RBT::~RBT(){

}

void RBT::fixTree(Node* current, Node* &head){
  if ()
}

void RBT::rotateRight(){
  Node* nhead = current->getLeft();
  if (current == head ){
    head = nhead;
  }
  else if (current->isRight()){
    current->getParent()->setRight(nhead);
  }
  else{
    current->getParent()->setLeft(nhead);
  }
  current->setLeft(nhead->getRight());
  nhead->setRight(current);
}

void RBT::rotateLeft(){
  Node* nhead = current->getRight();
  if (current == head){
    head = nhead;
  }
  else if(current->isRight()){
    current->getParent()->setRight(nhead);
  }
  else{
    current->getParent()->setLeft(nhead);
  }
  current->setRight(nhead->getLeft());
  nhead->setLeft(current);
}

void RBT::add(Node* current, int indent){
  if (head == NULL){  
    head = new Node(number);
    head->setRed(false);
  }
  else{
    if (number < current->getData()){
      if (current->getLeft()){
	add(current->getLeft(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setLeft(newNode);
	//	fix(newNode,head);
      }
    }
    if (number > current->getData()){
      if (current->getRight()){
	add(current->getRight(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setRight(newNode);
	//	fix(newNode,head);
      }
    }
  }
}
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
