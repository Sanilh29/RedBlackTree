//sanil hattangadi , creates the algorithm that runs the methods
#include "RBT.h"
#include <iostream>

using namespace std;

RBT::RBT(){//constructor
  head = NULL;
}

RBT::~RBT(){//deconstructor

}

Node* RBT::search(int number, Node* current){
  if (!current){
    current  = head;
  }
  if(number < current->getData()){
    if (current->getLeft()){
      return search(number, current->getLeft());
    }
    else return NULL;
  }
  else if(number > current->getData()){
    if (current->getRight()){
      return search(number, current->getRight());
    }
    else return NULL;
  }
  else return current;
}

void RBT::fixToBlack(Node* black, Node* parent){

}

void RBT::remove(Node* deleted){
  if (deleted->getLeft() && deleted->getRight()){
    Node* swap = deleted->getRight();
    while(swap->getLeft()){
      swap = swap->getLeft();
    }
    deleted->setData(swap->getData());
    deleted = swap;
  }
  Node* parent = deleted->getParent();
  Node* child = deleted->getRight();
  if (child == NULL){
    child = deleted->getLeft();
  }
  if (deleted == head){
    head = child;
  }
  if (deleted->isRight()){
    parent->setRight(child);
  }
  else{
    parent->setLeft(child);
  }
  if(!deleted->isRed()){
    if(child->isRed()){
      child->setRed(false);
    }
    else {
      // fixToBlack(child, parent);
    }
  }
}

void RBT::fixTree(Node* current, Node* &head){//fix all the methods to balance tree
  if (current != head){//if current is not the head, only node
    if(current->isRed() && current->getParent()->isRed()){//if current and parent is red
      if (current->getParent()->isRight() && !current->isRight()){//if parent is right, but child is not
	rotateRight(current->getParent());
	fixTree(current->getRight(), head);
      }
      else if (!current->getParent()->isRight() && current->isRight()){//if parent is not right, but child is
	rotateLeft(current->getParent());
	fixTree(current->getLeft(), head);
      }
      else if(!current->getUncle()){//if uncle is null
	if(current->isRight()){//if current is right
	  current->getParent()->getParent()->setRed(true);
	  current->getParent()->setRed(false);
	  rotateLeft(current->getParent()->getParent());
	 
	}
	else{//if child is left
	  current->getParent()->getParent()->setRed(true);
	  current->getParent()->setRed(false);
	  rotateRight(current->getParent()->getParent());
	 
	}
      }
      else if (!current->getUncle()->isRed()){//if uncle is red
	if(current->isRight()){//if child is right
	  current->getParent()->getParent()->setRed(true);
	  current->getParent()->setRed(false);
	  rotateLeft(current->getParent()->getParent());
	}
	else{//if the current is left
	  current->getParent()->getParent()->setRed(true);
	  current->getParent()->setRed(false);
	  rotateRight(current->getParent()->getParent());	 
	}
      }
      else{//if parent is red
	current->getParent()->getParent()->setRed(true);
	current->getParent()->setRed(false);
	current->getUncle()->setRed(false);
	print(head);
	fixTree(current->getParent()->getParent(), head);
      }
    }
  }
  head->setRed(false);
}

void RBT::rotateRight(Node* current){ //this rotates the tree to the right
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
  current->setLeft(nhead->getRight());//sets the right and left after rotation
  nhead->setRight(current);
}

void RBT::rotateLeft(Node* current){//rotates the tree to the left
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
  current->setRight(nhead->getLeft());//sets the left and right after rotation
  nhead->setLeft(current);
}

void RBT::add(Node* current, int number){//adds the number like binary search tree
  if (head == NULL){  
    head = new Node(number);
    head->setRed(true);
    fixTree(head, head);
  }
  else{
    if (number < current->getData()){//number is less than data inputted in tree
      if (current->getLeft()){//if its not null
	add(current->getLeft(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setLeft(newNode);
	fixTree(newNode, head);
      }
    }
    if (number > current->getData()){//number is greater than data inputted in tree
      if (current->getRight()){//if right is not null
	add(current->getRight(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setRight(newNode);
	fixTree(newNode, head);
      }
    }
  }
}

void RBT::print(Node* current, int indent){//print the tree
  if(current->getRight()){
    print(current->getRight(), indent+1);
  }
  for (int i = 0; i < indent; i++){
    cout << "  ";
  }
  cout << current->getData() << " " << current->isRed() << endl;
  if(current->getLeft()){
    print(current->getLeft(), indent+1);
  }
}

Node* RBT::getHead(){
  return head;
}
