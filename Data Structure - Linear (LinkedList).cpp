// ConsoleApplication4.cpp : Defines the entry point for the console application.

#include <iostream>
#include "stdafx.h"
using namespace std;

// Create Main Node
class Node{
public:
	int data;
	Node*next;

	Node(){
		//Initialize class properties in constractor
		data = 0;
		next = NULL;
	};
};

//Create Linked-List Class
class LinkedList {
public:
	Node*head;
	LinkedList(){
		head = NULL;
	};


	//1- Check if List is Empty
	bool isEmpty(){
		if (head == NULL){ return true; }
		else{ return false; };
	};


	//2-Insertion First of LinkedList
	void insertFirst(int newValue){
		//If list is empty
		if (isEmpty()){
			Node* newNode = new Node();
			newNode->data = newValue;
			newNode->next = NULL;
			head = newNode;
		}else{
			Node* newNode = new Node();
			newNode->data = newValue;
			newNode->next = head;
			head = newNode;
		};
	};


	// 3- Insert Before Specific Position
	void insertBefore(int item, int newValue){
		//Check if the list is empty
		if (isEmpty()){
			//if the list is empty put the new value as first node
			insertFirst(newValue);
		};
		//Check if the node already exist or not
		if (isFounded(item)){
			// new node
			Node* newNode = new Node();
			newNode->data = newValue;
			// temp pointer equal the head pointer
			Node* temp = head;
			// condition to stop while loop [Traversing]
			while (head != NULL && temp->next->data != item){
				temp = temp->next;
			};
			newNode->next = temp->next;
			temp->next = newNode;
		}else{
			cout << "Item Not Found \n";
		};
	};

	//4- Appending new Node at the last of LinkedList
	void append(int newValue){
		if (isEmpty()){
			insertFirst(newValue);
		}else{
			Node* temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			};
			Node* newNode = new Node();
			newNode->data = newValue;
			temp->next = newNode;
			newNode->next = NULL;
		};
	};


	//5- Delete node from List
	int remove(int item){
		//check if list is empty
		if (isEmpty()){
			cout << "List is Empty! \n";
		};

		//to save the deleted value
		int deletedValue;

		//check if the deleted item equal the head's data
		if (head->data == item){
			Node* delPtr = head;
			head = head->next;
			deletedValue = delPtr->data;
			delete delPtr;
			return deletedValue;
		}else{
			//delete node from list based on send item
			//we have to create two pointers
			//first one for pervious node
			//second one for the specific item wanna delete
			Node* prev = NULL;
			Node* delPtr = head;
			while (delPtr->data != item){
				prev = delPtr;
				delPtr = delPtr->next;
			};
			prev->next = delPtr->next;
			deletedValue = delPtr->data;
			delete delPtr;
			return deletedValue;
		};
	};


	//5- Dsiplay & Traversing Operation
	void display(){
		Node* temp = head;
		//Cause i don't know number of iterations
		while (temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		};
	};


	//6- Counter - Number Of Nodes
	int count(){
		int count = 0;
		Node* temp = head;
		while (temp != NULL){
			count++;
			temp = temp->next;
		};
		return count;
	};


	//7- Search for Some item
	bool isFounded(int theKey){
		bool found = false;
		Node* temp = head;
		while (temp != NULL){
			if (temp->data == theKey){
				found = true;
			};
			temp = temp->next;
		}
		return found;
	};
};


int _tmain()
{
	// Create Instance From LinkedList Class
	LinkedList list;
	if (list.isEmpty()){
		cout << "List is Empty \n";
	}else{
		cout << "The List Contain " << list.count() << endl;
	};
	////////////////////////////////////////////////////////////////
	int nums;
	cout << "how many items you wanna add to list?";
	cin >> nums;
	int *arr = new int[nums];
	for (int i = 0; i < nums; i++){
		cout << "Enter the item number " << i+1 << " to insert in the list \n";
		cin >> arr[i];
		list.insertFirst(arr[i]);
		list.display();
		cout << endl;
	};
	cout << "The List Contain " << list.count() << " items" << endl;
	////////////////////////////////////////////////////////////////
	int item;
	cout << "Enter item to search for? \n";
	cin >> item;
	if (list.isFounded(item)){
		cout << "Item Found. \n";
	}else{
		cout << "Item Not Found \n";
	};
	////////////////////////////////////////////////////////////////
	int newValue;
	cout << "enter the item and new Value to insert in list \n";
	cin >> item;
	cin >> newValue;
	list.insertBefore(item, newValue);
	list.display();
	////////////////////////////////////////////////////////////////
	int newVal;
	cout << "enter item to insert in the tail of list \n";
	cin >> newVal;
	list.append(newVal);
	list.display();
	////////////////////////////////////////////////////////////////
	int delVal;
	cout << "enter value to delete from list \n";
	cin >> delVal;
	cout << "removed value is " <<list.remove(delVal) << endl;
	list.display();
	////////////////////////**End of Program**//////////////////////
	system("pause");
	return 0;
}

