#include <iostream>
using namespace std;

// implementing the dynamic List ADT using Linked List

class Node {

private:
	int data;
	Node* nextNodePtr;

public:
	Node() {}

	void setData(int d) {
		data = d;
	}

	int getData() {
		return data;
	}

	void setNextNodePtr(Node* nodePtr) {
		nextNodePtr = nodePtr;
	}

	Node* getNextNodePtr() {
		return nextNodePtr;
	}

};

class List {

private:
	Node* headPtr;

public:
	List() {
		headPtr = new Node();
		headPtr->setNextNodePtr(0);
	}

	Node* getHeadPtr() {
		return headPtr;
	}

	bool isEmpty() {

		if (headPtr->getNextNodePtr() == 0)
			return true;

		return false;
	}


	void insert(int data) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;

		while (currentNodePtr != 0) {
			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();
		}

		Node* newNodePtr = new Node();
		newNodePtr->setData(data);
		newNodePtr->setNextNodePtr(0);
		prevNodePtr->setNextNodePtr(newNodePtr);

	}

	void insertAtIndex(int insertIndex, int data) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;

		int index = 0;

		while (currentNodePtr != 0) {

			if (index == insertIndex)
				break;

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();
			index++;
		}

		Node* newNodePtr = new Node();
		newNodePtr->setData(data);
		newNodePtr->setNextNodePtr(currentNodePtr);
		prevNodePtr->setNextNodePtr(newNodePtr);

	}


	int read(int readIndex) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		int index = 0;

		while (currentNodePtr != 0) {

			if (index == readIndex)
				return currentNodePtr->getData();

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();

			index++;

		}

		return -1; // an invalid value indicating 
		// index is out of range

	}

	void modifyElement(int modifyIndex, int data) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		int index = 0;

		while (currentNodePtr != 0) {

			if (index == modifyIndex) {
				currentNodePtr->setData(data);
				return;
			}

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();

			index++;
		}


	}


	void deleteElement(int deleteIndex) {

		Node* currentNodePtr = headPtr->getNextNodePtr();
		Node* prevNodePtr = headPtr;
		Node* nextNodePtr = headPtr;
		int index = 0;

		while (currentNodePtr != 0) {

			if (index == deleteIndex) {
				nextNodePtr = currentNodePtr->getNextNodePtr();
				break;
			}

			prevNodePtr = currentNodePtr;
			currentNodePtr = currentNodePtr->getNextNodePtr();

			index++;
		}

		prevNodePtr->setNextNodePtr(nextNodePtr);

	}


	void IterativePrint() {

		Node* currentNodePtr = headPtr->getNextNodePtr();

		while (currentNodePtr != 0) {
			cout << currentNodePtr->getData() << " ";
			currentNodePtr = currentNodePtr->getNextNodePtr();
		}

		cout << endl;

	}


};

int main() {

	int listSize;

	cout << "Enter the number of elements you want to insert: ";
	cin >> listSize;

	List integerList; // Create an empty list

	for (int i = 0; i < listSize; i++) {

		int value;
		cout << "Enter element # " << i << " : ";
		cin >> value;

		integerList.insertAtIndex(i, value);
	}

	cout << "Contents of the List: ";
	integerList.IterativePrint();

	// to read an element at a particular index (before delete)

	int readIndex;
	cout << "Enter an index to read (before delete): ";
	cin >> readIndex;
	cout << "Value at " << readIndex << " is: " << integerList.read(readIndex) << endl;

	// to delete an element at a particular index

	int deleteIndex;
	cout << "Enter an index to delete: ";
	cin >> deleteIndex;
	integerList.deleteElement(deleteIndex);

	cout << "Contents of the List: ";
	integerList.IterativePrint();

	// to read an element at a particular index (after delete)

	cout << "Enter an index to read (after delete): ";
	cin >> readIndex;
	cout << "Value at " << readIndex << " is: " << integerList.read(readIndex) << endl;



	// to insert an element at a particular index
	int insertIndex, insertValue;
	cout << "Enter an index to insert: ";
	cin >> insertIndex;
	cout << "Enter a value to insert: ";
	cin >> insertValue;
	integerList.insertAtIndex(insertIndex, insertValue);

	cout << "Contents of the List: ";
	integerList.IterativePrint();

	// to read an element at a particular index (after insert)

	cout << "Enter an index to read (after insert): ";
	cin >> readIndex;
	cout << "Value at " << readIndex << " is: " << integerList.read(readIndex) << endl;


	// to insert at the end of the list
	cout << "Enter the element you want to insert at the end of the list: ";
	cin >> insertValue;
	integerList.insert(insertValue);

	cout << "Contents of the List: ";
	integerList.IterativePrint();

	return 0;
}
