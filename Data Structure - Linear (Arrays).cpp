// Data Structures (Arrays).cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
using namespace std;

class Array{
private :
	int size;
	int length;
	int *myArr;

public :
	Array(int arrSize){
		size = arrSize;
		length = 0;
		myArr = new int[arrSize];
	};


	//Operations on Arrays
	//1- Fill
	void Fill(){
		int numOfItems;
		cout << "How many items you wanna fill ?\n";
		cin >> numOfItems;
		if (numOfItems > size){
			cout << "Exceeded Array Size!\n";
			return;
		}
		else{
			for (int i = 0; i < numOfItems; i++){
				cout << "Enter Item Number "<< i << endl;
				cin >> myArr[i];
				length++;
			}
		}

	};

	//2- Searching
	int search(int key){
		int index = -1;
		for (int i = 0; i < length; i++){
			if (myArr[i] == key){
				index = i;
				break;
			}
		};
		return index;
	};

	void append(int newItem){
		if (length < size){
			myArr[length] = newItem;
			length++;
		}
		else{
			cout << "Array is Full !\n";
		}
	}

	//3- Insertion
	void insert(int index, int newItem){
		if (index >= 0 && index < size){
			for (int i = length; i > index; i--){
				myArr[i] = myArr[i - 1];
			}
			myArr[index] = newItem;
			length++;
		}
		else{
			cout << "Index Out Of Range !/n";
		}
	};


	//4- Deletion
	void remove(int index){
		if (index >= 0 && index < size){
			for (int i = index; i < length - 1; i++){
				myArr[i] = myArr[i + 1];
				length--;
			}
		}
		else{
			cout << "Index Out Of Range !/n";
		}
	}

	//5- Increase Array Size
	void enLarge(int newIndex){
		if (newIndex <= size){
			cout << "the new size must be larger than current size\n" ;
		}
		else{
			size = newIndex;
			//Store old array in pointer
			int *old = myArr;
			myArr = new int[newIndex];
			for (int i = 0; i < length; i++){
				myArr[i] = old[i];
			};
			delete[]old;
		};
	};

	//6- Merge two Arrays
	void merge(Array other){
		int newSize = size + other.getSize();
		size = newSize;
		int *old = myArr;
		myArr = new int[newSize];
		int i;
		for(i = 0; i < length; i++){
			myArr[i] = old[i]; //Copy old items on old array to New Array
		};
		delete[]old;
		int j = i;
		for (int i = 0; i < other.getLength(); i++){
			myArr[j++] = other.myArr[i];
			length++;
		};
	};

	//7- Display Array Items
	void Diplay(){
		cout << "Display Array Items\n";
		for (int i = 0; i < length; i++){
			cout << myArr[i] << "\t";
		};
		cout << endl;
	};

	//8- Get Array Size
	int getSize(){
		return size;
	};

	//9- Get Array Length
	int getLength(){
		return length;
	};
};

int _tmain()
{
	cout << "Arrays Linear Data Structure Impelementation\n";
	int arraysize;
	cout << "Enter Array Size";
	cin >> arraysize;

	Array arr(arraysize);
	arr.Fill();
	arr.Diplay();
	cout << "Array Size is = " << arr.getSize() << "and Length is = " << arr.getLength() << endl;;
	////////////////////////////////////////////////////////////////
	cout << "Enter the Value you wanna Search for?\n";
	int key;
	cin >> key;
	int result = arr.search(key);
	if (result == -1)
		cout << "Item Not Found\n";
	else
		cout << "Item Founded @Index " << result << endl;
	///////////////////////////////////////////////////////////////
	cout << "Enter the New item to Store in Array?\n";
	int newItem;
	cin >> newItem;
	arr.append(newItem);
	arr.Diplay();
	///////////////////////////////////////////////////////////////
	cout << "Enter the Index and the Item";
	int index;
	cin >> index;
	cin >> newItem;
	arr.insert(index, newItem);
	arr.Diplay();
	cout << "Array Size is = " << arr.getSize() << "and Length is = " << arr.getLength() << endl;;
	///////////////////////////////////////////////////////////////
	cout << "Enter the Index of Item to Remove it\n";
	cin >> index;
	arr.remove(index);
	arr.Diplay();
	cout << "Array Size is = " << arr.getSize() << "and Length is = " << arr.getLength() << endl;;
	///////////////////////////////////////////////////////////////
	cout << "Enter the New Array Size\n?";
	int newSize;
	cin >> newSize;
	arr.enLarge(newSize);
	cout << "Array Size is = " << arr.getSize() << "and Length is = " << arr.getLength() << endl;;
	arr.Diplay();
	///////////////////////////////////////////////////////////////
	Array other(3);
	other.Fill();
	arr.merge(other);
	cout << "Array Size is = " << arr.getSize() << "and Length is = " << arr.getLength() << endl;;
 	arr.Diplay();

	system("pause");
	return 0;
}

