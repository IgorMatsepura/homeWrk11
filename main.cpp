#include <iostream>

using namespace std;

class Node {
public:
	Node* next;
	int data;

    Node (int data) {
        this->data = data;
        next = NULL;
    }
};

class LinkedList{
public:
	Node* firstNode = NULL;     //first element in LinkList
	Node* previous = NULL;      //previous element in LinkList
	Node* current = NULL;       //current element in LinkList
	Node* lastNode = NULL;      // tail in LinkedList
	int sizeNode = 0;
// size of LinkedList
void countIndexNode(Node* node) {
        if (node == NULL) {
            return;
        }
        countIndexNode(node->next);
        sizeNode++;
        cout<<" - "<<node->next <<endl;
        cout<<"Its number index - "<<sizeNode<<endl;
     //   return sizeNode;
}
// function add node in linkedlist
void addNode(int n, Node* node = NULL) {
        if (firstNode == NULL) {
            firstNode = new Node(n) ;
            return;
        }
        if (node->next != NULL) {
            addNode(n, node->next);
            return;
        }
        Node* newNode = new Node(n);
        if (firstNode->next == NULL) {
            firstNode->next = newNode;
            return;
        }
        node->next = newNode;
}

//The method of adding values by index to LinkedList: the beginning, the end of the list, and the middle
void indexAddNode(int n, int sizeNode, Node* node = NULL) {
    if (sizeNode < 0) {
        cout<<"Out of range - The index is less than zero"<<endl;
        return;
    }
    if (sizeNode == 0) {
        // todo insert
        Node* newNode = new Node( n );
        // add first element in empty ListLinked
        if (firstNode == NULL) {
            firstNode = newNode ;
            return;
        }
        //add first element if LinkedList not empty
		if (node == firstNode) {
            firstNode = newNode ;
            firstNode->next = node;
            return;
        }
        // add last element in LinkedList
        if (node->next == NULL) {
            node->next = newNode;
            return;
        }
        //add element in middle LinkedList
        previous = node;
        current = node->next;
        node = newNode;
        previous->next = newNode;
        node->next = current;
        return;
    }
    if (node->next == NULL) {
        cout<<"Out of range - The index is greater than the maximum value"<<endl;
        return;
    }
    previous=node;
    current=node->next;
    indexAddNode(n, --sizeNode, node->next);
}
//remove element of LinkedList
void remove(int n, int counter = 0){
    if (counter == 0){
        current = firstNode;
    }
    if (n == 0){
        firstNode = firstNode->next;
        return;
    }
    else if (counter == n-1){
        previous = current;
    }
    if (counter == n){
        previous->next = current->next;
        delete current;
        return;
    }
    if (current->next == NULL){
        return;
    }
    current = current->next;
    counter++;
    remove(n, counter);
}
// function Show LinkedList
void show(Node* n){
    cout<<n->data<<endl;
    if (n->next != NULL) {
        show(n->next);
    }
}
// function get number of element LinkedList
void getNode(int currentIndex, Node* node) {
    if (currentIndex < 0) {
        cout<<"Out of range - The index is less than zero"<<endl;
        return;
    }
    if (currentIndex == 0) {
    	cout<<"Get Data Node - > "<<node->data<<endl;
        return;
    }
    if (node->next == NULL) {
        cout<<"Out of range - The index is greater than the maximum value"<<endl;
        return;
    }
    getNode(--currentIndex, node->next);
}

};

int main() {
	LinkedList link;
	cout<<"Add node to LinkedList"<<endl;
	link.addNode(23, link.firstNode);
	link.addNode(2, link.firstNode);
	link.addNode(78, link.firstNode);
	link.addNode(55, link.firstNode);
	link.addNode(99, link.firstNode);
	link.show(link.firstNode);
	cout<<"Remove Node in LinkedList"<<endl;
	link.remove(2);
	link.show(link.firstNode);
    cout<<"Add node to LinkedList for Index"<<endl;
    link.indexAddNode(0, 1, link.firstNode);
    link.indexAddNode(220, 0, link.firstNode);
    link.indexAddNode(999, 5, link.firstNode);
    link.show(link.firstNode);
    cout<<"Get Node in LinkedList"<<endl;
    link.getNode(1, link.firstNode);
}
