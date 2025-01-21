#include <iostream>

//node class

class Node {
	friend class List;
public:
	Node(const int &);     // constructor
	int getData() const;   // get function returns data in node


private:
	int data; //data (number)
	Node *next; //pointer to next node
};

//list class
class List {

public:
	List(); //constructor
	~List(); //destructor
	void addNode(const int &); //add node to list (push_Back)
	void push_front(const int &data); //pushes to front of list 
	bool empty(); //checks if list is empty
	void printList(); //prints elements of list
	List add(List& l1,List& l2); //takes two lists and adds them and returns list with sum
private:
	Node *head;                // pointer first element in the list
	Node *creatNode(const int &);  // creates a new node
};

