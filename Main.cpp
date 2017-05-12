//sanil hattangadi, main function that allows users to input file or add numbers manually
#include <iostream>
#include <fstream>
#include <cstring>
//#include "Node.h"
#include "RBT.h"

using namespace std;

void checkInput(ifstream &stream, bool &isFile){ //checks if the input is file or input
  char input[128];
  isFile = false;
  cout << "Do you want to read from a file or input your own text?(file or input)" << endl;//check how it will be inputted
  cin.getline(input,128);
  if (0== strcmp(input, "file")){//if file and input are equal
    char name[128];
    cout << "What file?" << endl;
    cin.getline(name, 128);//get the name of the file
    stream.open(name);//try to open it
    if(stream.is_open()){//if it opends, there is a file
      isFile = true;
      cout << "Thanks. Enter a command above." << endl;
    }
    else {
      cout << "The file could not be opened" << endl;
    }
  }
  if (0==strcmp(input, "input")){
    cout << "Enter the numbers please." << endl;
  }
}
void addNumbers(istream &from, RBT* tree){
  //goes through a stream and adds them to the heap
  int newInput;
  from >> newInput;
  tree->add(tree->getHead(), newInput);
  while(from.peek() != '\n' && !from.eof()){
    if(isdigit(from.peek())){
      from >> newInput;
      tree->add(tree->getHead(),newInput);
    }
    else{
      from.ignore();
    }
  }
}



int main(){
  //main program loop
  RBT* tree = new RBT();
  char input[128];
  bool running = true;
  while(running == true){//while program is running
    cout << "Enter a command: add, delete, print, search, or quit." << endl;
    cin.getline(input, 128);
    if(0==strcmp(input, "add")){//see if input is add
      ifstream stream;//initialize variables
      bool isFile;
      checkInput(stream, isFile);
      addNumbers(isFile ? stream : cin, tree);//add the numbers       
      if(isFile) stream.close();
      cin.ignore();
    }
    else if(0==strcmp(input, "print")){//if print is inputted, 
      tree->print(tree->getHead());//print at the head
    } 
    else if(0==strcmp(input, "quit")){//end the program
      running = false;
    }
    else if (0==strcmp(input, "delete")){
      if (tree->getHead() == NULL){
        cout << "There is nothing in the list!" << endl;
      }
      else{
        cout << "What do you want me to delete?" << endl;
        int number;
        cin >> number;
	cin.ignore();
	Node* deleted = tree->search(number);
	if(deleted){
	  tree->remove(deleted);
	}
        else{
	  cout << "The number: " << number << " is not in the tree." << endl;
	}
      }
    }
    else if (0==strcmp(input, "search")){
      if(tree->getHead()==NULL){
	cout << "It's an empty list" << endl;
      }
      else {
	cout << "What number are you looking for?" << endl;
	int number;
	cin >> number;
	cin.ignore();
	if(tree->search(number)){
	  cout << "The number: " << number << " is in the tree" << endl;
	}
	else{
	  cout << "The number: " << number << " is not in the tree." << endl;
	}
      }
    }
  }
}
