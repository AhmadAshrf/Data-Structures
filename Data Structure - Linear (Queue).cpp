// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "stdafx.h"
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

class Queue{
public:
	Node*front;
	Node*tail;
	Queue(){
		front = tail = NULL;
	};

	//Queue Operation 
	//1- isEmpty()
	bool isEmpty(){
		if (front == NULL &&tail == NULL)
			return true;
		else 
		return false;
	}

	//2- Enqueue() - add new items to queue
	void enqueue(int newVal){
		Node* newNode = new Node();
		if (isEmpty()){
			//if queue is empty so that head & tail are equal the new node
			newNode->data = newVal;
			front = tail = newNode;
		}else{
			newNode->data = newVal;
			tail->next = newNode;
			tail = newNode;
		}
	};

	//3- Display() - Traversing on Queue
	void display(){
		if (isEmpty()){
			cout << "Queue is Empty! \n";
		}else{
			Node*temp;
			temp = front;
			while (temp != NULL){
				cout << temp->data << " ";
				temp = temp->next;
			};
			cout << endl;
		};
	};

	//4- Dequeue(); - Remove element from Queue
	int dequeue(){
		int saveDeletedValue = -1;
		if (isEmpty()){
			//if queue has no items
			cout << "Queue is Empty! \n";
		}else if (front == tail){
			//if queue has the last item
			delete front;
			front = tail = NULL;
		}else{
			//if queue has more than one item
			Node*delPtr;
			delPtr = front;
			front = front->next;

			//to store removed value before delete it from memory
			saveDeletedValue = delPtr->data;
			delete delPtr;
		};
		return saveDeletedValue;
	};

	//5- getFront() - return the first item in queue
	int getFront(){
		return front->data;
	};

	//6- getTail() - return the last item in queue
	int getTail(){
		return tail->data;
	};
	//7- counter() - return the number of items in queue
	int counter(){
		int count = 0;
		Node*temp = front;
		while (temp!=NULL){
			count++;
			temp = temp->next;
		};
		return count;
	};

	//8- search() - check if item is found in queue
	bool search(int val){
		bool found = false;
		Node*temp = front;
		while (temp!=NULL){
			if (temp->data == val)
				found = true;
			temp = temp->next;
		};
		return found;
	};

	//9- clear() - remove all queue items
	void clear(){
		while (!isEmpty()){
			dequeue();
		};
	};

};

int _tmain()
{
	///////////////////////////////////////////////////////////////////
	Queue LinkedQueue;
	for (int i = 0; i < 4; i++){
		int val;
		cout << "enter item number " << i+1 <<" to enqueue: \n";
		cin >> val;
		LinkedQueue.enqueue(val);
	};
	LinkedQueue.display();
	cout << "Queue has " << LinkedQueue.counter() << " items\n";
	///////////////////////////////////////////////////////////////////
	for (int i = 0; i < 2; i++){
		cout << LinkedQueue.dequeue() << " removed from queue! \n";
	};
	cout << "After Dequeue \n";
	LinkedQueue.display();
	///////////////////////////////////////////////////////////////////
	cout << "Clear all Queue Items \n";
	LinkedQueue.clear();
	LinkedQueue.display();
	////////////////////////**Program End**////////////////////////////
	system("pause");
	return 0;
}

