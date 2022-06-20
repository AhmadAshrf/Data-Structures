// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class Node{
public:
	int data;
	Node* next;

	Node(){
		data = 0;
		next = NULL;
	};
};

class Stack{
	Node *top;

public:
	//Initialize Constractor
	Stack(){
		top = NULL;
	};

	//****Stack Operations****
	//-1 Check if stack is empty or nah
	bool isEmpty(){
		if (top == NULL)return true;
		else
			return false;
	};


	//2- Check if stack is full or nah
	bool isFull(){
		Node *ptr = new Node();
		if (ptr == NULL){
			cout << "Stack is Full! \n";
			return true;
		};
	};


	//-3 Push Method - add items to stack
	void push(int item){
		if (isEmpty()){
			//Check if node is empty 
			Node * newNode = new Node();
			newNode->data = item;
			newNode->next = NULL;
			top = newNode;
		}else{
			//if node has items on stack
			Node *newNode = new Node();
			newNode->data = item;
			newNode->next = top;
			top = newNode;
		}
	};


	//4- delete item from stack and return that removed item
	int pop(){
		Node* delPtr = top;

		//to store removed item
		int removedItem = top->data;
		top = top->next;
		delete delPtr;
		return removedItem;
	}
	

	//5- Display Stack items (Traversing)
	void display(){
		Node *temp = top;
		while (temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	//6- Peek Method - Return the current value in stack (top value) 
	int peek(){
		return top->data;
	};

	//7- Counter - Return Numbers of Stack items  
	int counter(){
		int counter = 0;
		Node*temp = top; 
		while (temp != NULL){
			counter++;
			temp = temp->next;
		};
		return counter;
	};

	//8- isFound Method - Check on specific value that founded on stack 
	bool isFound(int value){
		bool found = false;
		Node*temp = top;
		while (temp != NULL){
			if (temp->data == value){
				found = true;
			};
			temp = temp->next;
		};
		return found;
	};
};



int _tmain()
{
	//create objecj from stack class
	Stack stack;
	int items;
	for (int i = 0; i < 3; i++){
		cout << "enter items number " << i+1 << " to push? \n";
		cin >> items;
		stack.push(items);
		stack.display();
	};


	cout << stack.pop() << " removed from stack! \n";
	stack.display();

	int found;
	cout << "enter item to search for ? \n";
	cin >> found;
	if (stack.isFound(found)){
		cout << "item is found \n";
	}else{
		cout << "item not found \n";
	};
	cout << "stack has " <<stack.counter() << " items" << endl;

	system("pause");
	return 0;
}

