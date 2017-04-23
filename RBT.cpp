#include "RBT.h"
#include <iostream>

using namespace std;

RBT::RBT(){
  head = NULL;
}

RBT::~RBT(){

}

void RBT::fixTree(Node* current, Node* &head){
  if (current->getParent() != NULL){//case 4
    cout << "gdf" << endl;
    if(current->isRed() && current->getParent()->isRed()){
      if (current->getParent()->isRight() && !current->isRight()){
	rotateRight(current->getParent(), head);
      }
      if (!current->getParent()->isRight() && current->isRight()){
	rotateLeft(current->getParent(), head);
      }
      if(!current->getUncle()){
	if(current->isRight()){
	  if(current->getParent()->isRight()){
	    current->getParent()->getParent()->setRed(true);
	    current->getParent()->setRed(false);
	    rotateLeft(current->getParent()->getParent(),head);
	    // rotateLeft(current);
	  }
	  else{
	    current->getParent()->getParent()->setRed(true);
	    current->getParent()->setRed(false);
	    rotateRight(current->getParent()->getParent(), head);
	    fixTree(current->getLeft(), head);
	  }
	}
	else{
	  if(current->getParent()->isRight()){
	    current->getParent()->getParent()->setRed(true);
	    current->getParent()->setRed(false);
	    rotateRight(current->getParent()->getParent(),head);
	  }
	  else{
	    current->getParent()->getParent()->setRed(true);
	    current->getParent()->setRed(false);
	    rotateLeft(current->getParent()->getParent(), head);
	    fixTree(current->getLeft(), head);
	  }
	}
      }
      else{
	cout << "ello" << endl;
	if (!current->getParent()->isRed()){
	  if(current->isRight()){
	    if(current->getParent()->isRight()){
	      current->getParent()->getParent()->setRed(true);
	      current->getParent()->setRed(false);
	      rotateLeft(current->getParent()->getParent(),head);
	      // rotateLeft(current);
	    }
	    else{
	      current->getParent()->getParent()->setRed(true);
	      current->getParent()->setRed(false);
	      rotateRight(current->getParent()->getParent(), head);
	      fixTree(current->getLeft(), head);
	    }
	  }
	  else{
	    cout << "hello" << endl;
	    if(current->getParent()->isRight()){
	      current->getParent()->getParent()->setRed(true);
	      current->getParent()->setRed(false);
	      rotateRight(current->getParent()->getParent(),head);
	      // rotateLeft(current);
	    }
	    else{
	      cout << "hi" << endl;
	      current->getParent()->getParent()->setRed(true);
	      current->getParent()->setRed(false);
	      rotateLeft(current->getParent()->getParent(), head);
	      fixTree(current->getLeft(), head);
	    }
	  }
	}
	else{
	  cout << "hi" << endl;
	  current->getParent()->getParent()->setRed(true);
	  current->getParent()->setRed(false);
	  current->getUncle()->setRed(false);
	  cout << "boo" << endl;
	  fixTree(current->getParent()->getParent(), head);
	  cout << "bee" << endl;
	}
      }
    }
    //here
  }
  head->setRed(false);
}

void RBT::rotateRight(Node* current ,Node* &head){
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

void RBT::rotateLeft(Node* current, Node* &head){
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

void RBT::add(Node* current, int number){
  if (head == NULL){  
    head = new Node(number);
    head->setRed(true);
    fixTree(head, head);
  }
  else{
    if (number < current->getData()){
      if (current->getLeft()){
	add(current->getLeft(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setLeft(newNode);
	fixTree(newNode, head);
      }
    }
    if (number > current->getData()){
      if (current->getRight()){
	add(current->getRight(),number);
	//fixTree(current, 
      }
      else{
	Node* newNode = new Node(number);
	current->setRight(newNode);
	fixTree(newNode, head);
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
  cout << current->getData() << " " << current->isRed() << endl;
  if(current->getLeft()){
    print(current->getLeft(), indent+1);
  }
}

Node* RBT::getHead(){
  return head;
}
