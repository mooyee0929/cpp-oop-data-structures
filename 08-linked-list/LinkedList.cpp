#include"LinkedList.h"

LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{
	Clear();
}


void LinkedList::Push_back(int x)
{
	//TODO: add a new node to the back of the list with value x
	Node* newNode = new Node(x);   // 配置新的記憶體

	if (head == 0) {
		head = newNode;
		return;
	}

	Node* current = head;
	while (current->next != 0) {
		current = current->next;
	}
	current->next = newNode;

}

void LinkedList::Push_front(int x)
{
	//TODO: add a new node to the front of the list with value x
	Node* newNode = new Node(x);   // 配置新的記憶體
	newNode->next = head;
	head = newNode;
}

void LinkedList::Insert(int index, int x)
{
	//TODO: add a new node at position "index" of the list with value x
	Node* input = new Node(x);
	Node* current = head,
		* previous = NULL;
	int i = 0;
	while (i < index) {
		previous = current;
		current = current->next;
		i++;
	}
	if (head == 0) {
		head = input;
		return;
	}
	else if (current == head) {
		head = input;
		head->next = current;
	}
	else {
		previous->next = input;
		input->next = current;
	}
}

void LinkedList::Delete(int index)
{
	//TODO: delete the node at position "index"
	Node* current = head,
		* previous = NULL;
	int i = 0;
	while (i < index) {
		previous = current;
		current = current->next;
		i++;
	}
	if (current == head) {
		head = current->next;
		delete current;
	}
	else {
		previous->next = current->next;
		delete current;
	}
}

void LinkedList::Reverse()
{
	//TODO: reverse all elements in the list
	if (head == 0 || head->next == 0) {
		// list is empty or list has only one node
		return;
	}
	Node* previous = 0,
		* current = head,
		* preceding = head->next;
	while (preceding != NULL) {
		current->next = previous;
		previous = current;
		current = preceding;
		preceding = preceding->next;
	}

	current->next = previous;
	head = current;
}

void LinkedList::Print()
{
	//TODO: print out all elements in the list
	if (head == 0) {                      // 如果first node指向NULL, 表示list沒有資料
		cout << "List is empty.\n";
		return;
	}

	Node* current = head;             // 用pointer *current在list中移動
	while (current != 0) {                 // Traversal
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
	
}

void LinkedList::Clear() 
{
	//TODO: delete all elements in the list
	while (head != 0) {            // Traversal
		Node* current = head;
		head = head->next;
		delete current;
		current = 0;
	}
}