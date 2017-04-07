
#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(int newdata){
  data = newdata;
  left = NULL;
  right = NULL;
  parent= NULL;
  //red = true;
}

Node::Node(){

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
}

void Node::setRight(Node* node){//sets the right node
  right = node;
}

void Node::setParent(Node* node){
  parent = node;
}
