#include "list.h"
using namespace std;

//constructor

List::List() {

	head=NULL;


}

//destructor


List::~List() {
	if(!empty()) {
		Node *ptr=head;

		while(ptr!=NULL) {
			Node *next=ptr->next;
			delete ptr;
			ptr=next;

		}
	}
}



//checks if list is empty
bool List::empty() {

	return head==NULL;

}
//push_back adds nodes into back of the list 
void List::addNode(const int &data) {
	Node *addedNode  = creatNode(data); //creat node 

	if (empty()) { // create a new node
		head = addedNode; //head of list points to added node
	}
	else {
		Node *temp = head; //temp pointer
		while (temp->next != NULL) { // loop over list

			temp = temp->next;
		}
		temp->next = addedNode;

		addedNode->next = NULL;//puts node in the back and makes its next null
	}
}

Node *List::creatNode(const int &value) {
	return new Node(value); //creats node and puts data into it
}

//Node constructor
Node::Node(const int&info) {
	data=info;
	next=NULL;
}
//gets data in the node
int Node::getData() const {
	return data;
}
//adds two lists returns list of sum

List List::add(List& l1,List &l2) {
	List linkedList; //list instance
	Node* temp1 = l1.head; //point to head of lists 
	Node* temp2 = l2.head;
	int carry = 0; 

	while (temp1 != NULL || temp2 != NULL) { //while one or the other is not empty 
		int first = 0;
		int sec = 0;
		if (temp1 != NULL) {

			first = temp1->getData();
			temp1 = temp1->next; // Move to next node in list 1
		}
		if (temp2 != NULL) {
			sec = temp2->getData();
			temp2 = temp2->next; // Move to next node in list 2
		}

		int result = first + sec + carry; // Add values
		if (result > 9) {
			carry = 1; // Set carry to 1 if result is greater than 9

			result -= 10; // subtract result by 10 to get the correct digit
		} else {
			carry = 0; // No carry if result is 9 or less
		}
		linkedList.push_front(result); // Add to list by pushfront to print correctly 
	}
	if (carry != 0) {

		linkedList.push_front(carry); // Add carry if there's any
	}
	return linkedList;       // Return the resulting list
}

void List::push_front(const int &data) {
	Node *newNode  = creatNode(data);
	if (empty()) { // create a new node
		head = newNode;
	} else {
		newNode->next=head; //puts node in the front and its next becomes the head
		head=newNode;
	}


}

void List::printList() {
	Node *temp = head; // Start from the first node
	while (temp != NULL) { // loop over list
		cout << temp->getData(); // Print the data of the current node
		temp = temp->next;// Move to the next node

	}
	cout<<endl;
}
