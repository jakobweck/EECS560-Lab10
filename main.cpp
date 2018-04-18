#include <iostream>
#include <fstream>
#include "LeftistHeap.h"
#include "SkewHeap.h"

int main(int argc, char** argv){
  ConcatHeap* heap;
  std::ifstream file;

  file.open("data.txt");
  int curr;
  bool initialized = false;
  std::cout<<"\nPlease choose a heap implementation: \n";
  std::cout<<"1- Leftist Heap\n";
  std::cout<<"2- Skew Heap\n";
  int heapChoice = 0;
  while (heapChoice != 1 && heapChoice != 2){
    std::cin>>heapChoice;
  }
  while (file >> curr){
    if (!initialized&&(heapChoice == 1)){
      heap = new LeftistHeap(curr);
      initialized = true;
    }
    else if (!initialized&&(heapChoice == 2)){
      heap = new SkewHeap(curr);
      initialized = true;
    }
    else{
      heap = heap->insert(curr);
    }
  }
  file.close();
  bool keepRunning = true;
  while(keepRunning){
    int choice = 0;
    std::cout<<"\nPlease choose one of the following commands: \n";
    std::cout<<"1- Insert\n";
    std::cout<<"2- DeleteMin\n";
    std::cout<<"3- Preorder\n";
    std::cout<<"4- Inorder\n";
    std::cout<<"5- Levelorder\n";
    std::cout<<"6- Exit\n";

    std::cin>>choice;
    if (std::cin.good()){
      switch(choice) {
      case 1 :{
        std::cout<<"Enter a number to be inserted:";
        int newVal = 0;
        std::cin>>newVal;
	      if (std::cin.good()){
          heap = heap->insert(newVal);
        }
	    else{
		      std::cout << "Invalid input.\n";
      		std::cin.clear();
      		std::cin.ignore(999999999, '\n');
	    }
	    break;
      }
      case 2 :{
        heap = heap->deleteMin();
        break;
      }
      case 3:{
        std::cout<<"Preorder\n";
        heap->preorder();
        break;
      }
      case 4:{
        std::cout<<"Inorder:\n";
        heap->inorder();
        break;
      }
      case 5:{
        std::cout<<"Level order:\n";
        heap->levelorder();
        break;
      }
      case 6:{
        keepRunning = false;
        break;
      }
      default:
        std::cout << "Try again.\n";
        break;
    }
  }
}
heap->recFree(heap);
}
