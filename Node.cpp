
#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(int newdata){
  data = newdata;
  left = NULL;
  right = NULL;
  parent= NULL;
  red = true;
}

Node::Node(){
  cout << "What's the data of the node?" << endl;
  cin >> data;
  red = true;
}

Node::~Node(){
  delete &data; 
}

Node* Node::getLeft(){
  return left;
}

Node* Node::getRight(){
  return right;
}

Node* Node::getParent(){
  return parent;
}

int Node::getData(){
  return data;
}

void Node::setLeft(Node* node){//sets the left node
  left = node;
  if (left!= NULL){
    left->setIsRight(false);
    left->setParent(this);
  }  
}

void Node::setRight(Node* node){//sets the right node
  right = node;
  if (right != NULL){
    right->setIsRight(true);
    right->setParent(this);
  }
 }

void Node::setParent(Node* node){
  parent = node;
}

Node* Node::getUncle(){
  if (parent != NULL){
    if (parent->getParent() != NULL){
      if (parent->getParent()->checkRight()){
	return parent->getParent()->getRight();
      }
      else{
	return parent->getParent()->getLeft();
      }
    }
  }
  else {
    return NULL;
  }
}

bool Node::checkRed(){
  return red;
}

void Node::setRed(bool isRed){
  red = isRed;
}

bool Node::checkRight(){
  return rightChild;
}

void Node::setIsRight(bool isRight){
  rightChild = isRight;
}
