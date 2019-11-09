#pragma once
#include <string>
#include <iostream>

//the queue
template <typename A>
class queue {
private:
	struct node {
		A data;	//void ptr to make it ADT
		node* next;	//ptr to next struct
	};
	node* back = NULL;
	node* front = NULL;
public:
	queue() {	//constructor
		back = NULL;
		front = NULL;
	}
	queue(A v) {	//constructor
		enqueue(v);
	}
	~queue() { //destructor
		while (!isEmpty()) {
			dequeue();
		}
	}
	void enqueue(A a) {	//put a new node into the queue
		node* temp = new node;
		temp->data = a;
		temp->next = NULL;
		if (back == NULL) {	//if queue is empty
			back = temp;
			front = temp;
		}
		else {
			back->next = temp;
			back = temp;
		}
	}
	A getFront() {
		if (front == NULL) {
			return NULL;
		}
		else {
			return front->data;
		}
	}
	A dequeue() {	//take off the front and return value
		if (front == NULL) { //if queue is empty
			return A();
		}
		else {
			A ret = front->data;
			node* tmp = front;
			if (back == front) {
				front = NULL;
				back = NULL;
				delete tmp;
				return ret;
			}
			else {
				front = front->next;
				delete tmp;
				return ret;
			}
		}
	}
	bool isEmpty() {	//check if queue is empty
		if (front == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
};


template <typename T>
class BinaryTree {
private:
	struct node {
		node* left;
		node* right;
		T data;
	};
	node* root;

public:
	BinaryTree() {
		root = nullptr;
	}
	BinaryTree(T d) {
		node* myNode = new node();
		myNode->data = d;
		root = myNode;
	}
	void addNode(const T &d) { //calls recursive add node
		if (root == nullptr) {
			node* myNode = new node();
			myNode->data = d;
			root = myNode;
		}
		else {
			addNode(d, root);
		}
	}
	void inOrder() {
		inOrder(root);
	}
	void preOrder() {
		preOrder(root);
	}
	void postOrder() {
		postOrder(root);
	}
	void printTree() {
		printTree(root, 0);
	}

private:
	node* findNode(T d, node* t) {
		if (d < t->data) {
			if (t->left == nullptr) {
				return nullptr;
			}
			else {
				return findNode(d, t->left);
			}
		}
		else if (d > t->data) {
			if (t->right == nullptr) {
				return nullptr;
			}
			else {
				return findNode(d, t->right);
			}
		}
		else {
			return t;
		}
	}

	void printTree(node* r, int tabs) {
		if (r->right != nullptr) {
			printTree(r->right, tabs + 1);
		}
		for (int i = 0; i < tabs; i++) {
			std::cout << "\t";
		}
		std::cout << r->data << "\n";
		if (r->left != nullptr) {
			printTree(r->left, tabs + 1);
		}
	}

	void addNode(const T &d, node* &t) { //adds node recursively
		if (d < t->data) {
			if (t->left == nullptr) {
				//create node on left of t
				node* myNode = new node();
				myNode->data = d;
				t->left = myNode;
			}
			else {
				addNode(d, t->left);
			}
		}
		else if (d > t->data) {
			if (t->right == nullptr) {
				//create node on right of t
				node* myNode = new node();
				myNode->data = d;
				t->right = myNode;
			}
			else {
				addNode(d, t->right);
			}
		}
	}
	void inOrder(node* treePtr) {
		if (treePtr != NULL) {
			inOrder(treePtr->left);
			std::cout << treePtr->data << " ";
			inOrder(treePtr->right);
		}
	}
	void preOrder(node* treePtr) {
		//if tree is not empty, then traverse
		if (treePtr != NULL) {
			std::cout << treePtr->data << " ";
			preOrder(treePtr->left);
			preOrder(treePtr->right);
		}
	}
	void postOrder(node* treePtr) {
		//if tree is not empty, then traverse
		if (treePtr != NULL) {
			postOrder(treePtr->left);
			postOrder(treePtr->right);
			std::cout << treePtr->data << " ";
		}
	}

};


template <typename l>
//a singley linked list
class linkedList {
private:
	struct node {
		l data;
		node* next;
	};
	node *head, *tail;
public:
	//constructor
	linkedList() {
		head = NULL;
		tail = NULL;
	}

	//push a value to the back of the list
	void pushBack(const l &value) {
		//create temp node; set tmp's data to n; set its pointer to NULL
		node *tmp = new node;
		tmp->data = value;
		tmp->next = NULL;

		//if head doesnt exist then this is the first and only node
		if (head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			//set current tail's pointer to point to the temp node; then reset the tail to the temp
			tail->next = tmp;
			tail = tail->next;
		}
	}

	//get the data at an index
	l at(const int &index) {
		int counter = 0;
		node *tmp;
		tmp = head;
		while (tmp != NULL && (index > counter)) {
			tmp = tmp->next;
			counter++;
		}
		return tmp->data;
	}
	
	void display(std::string &listName) {
		//create temporary node pointer then set the pointer to point to the head of list
		node *tmp;
		tmp = head;
		std::cout << listName << ": {\n";
		//go through the list with the tmp pointer by keep setting the tmp to the next pointer
		int counter = 0;
		while (tmp != NULL) {
			std::cout << "[" << counter << "] " << tmp->data << "\n";
			tmp = tmp->next;
			counter++;
		}
		std::cout << "}\n";
	}

	//insert data at an index
	void insert(const int &index, const l &value) {
		//if they index at value zero, place the node at the head
		if (head == NULL) {
			pushBack(value);
		}
		else if (index < 1) {
			front(value);
		}
		else {
			node* tmp;
			tmp = head;
			//loop through 1 less as many times as they index to use our after function to place the node
			//if the index at the end then our pointer will point to a node whose pointer points to NULL
			for (int i = 0; (i < index - 1) && (tmp->next != NULL); i++) {
				tmp = tmp->next;
			}
			if (tmp->next == NULL) {
				pushBack(value);
			}
			else {
				after(tmp, value);
			}
		}
	}

	//delete entry at an index
	void deleIndex(const int &index) {
		if (index < 1) {
			deleHead();
		}
		else {
			node* temp;
			temp = head;
			for (int i = 0; i < index - 1; i++) {
				temp = temp->next;
			}
			dele(temp);
		}
	}
private:
	void after(node* &a, const l &value) {
		node* p = new node;
		p->data = value;
		p->next = a->next;
		a->next = p;
	}
	void dele(node* &beforeDel) {
		node* temp;
		temp = beforeDel->next;
		beforeDel->next = temp->next;
		delete temp;
	}
	void front(const l &n) {
		node *tmp = new node;
		tmp->data = n;
		tmp->next = head;
		head = tmp;
	}
	void deleHead() {
		node* temp;
		temp = head;
		head = head->next;
		delete temp;
	}
};

//linked map
template <typename key, typename val>
class linkedMap {
private:
	struct node {
		key k;
		val data;
		node* next;
	};
	node *head, *tail;
public:
	//constructor
	linkedMap() {
		head = NULL;
		tail = NULL;
	}

	//push a value to the back of the list
	void pushBack(const key &index, const val &value) {
		//create temp node; set tmp's data to n; set its pointer to NULL
		node *tmp = new node;
		tmp->data = value;
		tmp->next = NULL;
		tmp->k = index;

		//if head doesnt exist then this is the first and only node
		if (head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			//set current tail's pointer to point to the temp node; then reset the tail to the temp
			tail->next = tmp;
			tail = tail->next;
		}
	}

	//get the data at an index
	val& at(const key &index) const {
		int counter = 0;
		node *tmp;
		tmp = head;
		while (tmp != NULL && index != tmp->k) {
			tmp = tmp->next;
			counter++;
		}
		return tmp->data;
	}

	void display(const std::string &listName) {
		//create temporary node pointer then set the pointer to point to the head of list
		node *tmp;
		tmp = head;
		std::cout << listName << ": {\n";
		//go through the list with the tmp pointer by keep setting the tmp to the next pointer
		int counter = 0;
		while (tmp != NULL) {
			std::cout << "<key: " << tmp->k << "> " << tmp->data << "\n";
			tmp = tmp->next;
			counter++;
		}
		std::cout << "}\n";
	}

	//insert data at an index
	void insert(const key &index, const val &value) {
		//if they index at value zero, place the node at the head
		if (head == NULL) {
			pushBack(index, value);
		}
		else if (index == head->k) {
			front(index, value);
		}
		else {
			node* tmp;
			tmp = head;
			//loop through until at the key or at the end of the list
			for (int i = 0; (index != tmp->k) && (tmp->next != NULL); i++) {
				tmp = tmp->next;
			}
			if (tmp->next == NULL) {
				pushBack(index, value);
			}
			else {
				tmp->data = value;
			}
		}
	}

	//delete entry at an index
	void deleIndex(const key &index) {
		if (index == head->k) {
			deleHead();
		}
		else {
			node* temp;
			temp = head;
			while(index != temp->next->k && (temp->next != NULL)) {
				temp = temp->next;
			}
			if (index != temp->next->k) {
				return;
			}
			else {
				dele(temp);
			}
		}
	}
private:
	void dele(node* &beforeDel) {
		node* temp;
		temp = beforeDel->next;
		beforeDel->next = temp->next;
		delete temp;
	}
	void front(const key &index, const val &n) {
		node *tmp = new node;
		tmp->data = n;
		tmp->k = index;
		tmp->next = head;
		head = tmp;
	}
	void deleHead() {
		node* temp;
		temp = head;
		head = head->next;
		delete temp;
	}
};



class minHeap {
private:
	int* har;
	int max;
	int size;
public:
	minHeap(int s) {
		if (s < 1) {
			s = 1;
		}
		har = new int[s];
		for (int i = 0; i < s; i++) {
			har[i] = NULL;
		}
		max = s;
		size = 0;
	}
	void print() {
		for (int i = 0; i < size; i++) {
			std::cout << har[i] << ((i != size - 1) ? ", " : "\n");
		}
	}
	void add(int v) {
		if (size == max) {
			std::cout << "Overflow heap, could not insert" << v << "\n";
			return;
		}
		//insert v at end
		int i = size;
		har[i] = v;
		size++;

		//if the parent is smaller than v
		while (i != 0 && har[parent(i)] > har[i]) {
			//swap parent and har[i]
			swap(&har[i], &har[parent(i)]);
			//check for har[parent]
			i = parent(i);
		}
	}
	void del(int i) {
		if (i > max || i < 0) {
			return;
		}
		size--;
		har[i] = har[size];
		har[size] = NULL;
		int k;
		//while has right or left child
		while (hasAChild(i)) {
			if (har[left(i)] != NULL && har[right(i)] != NULL) {
				k = (har[left(i)] < har[right(i)]) ? left(i) : right(i);
				if (har[i] < har[k]) {
					//finished while
					return;
				}
				else {
					swap(&har[i], &har[k]);
					i = k;
				}
			}
			else {
				//har[i] has only one child
				k = (har[left(i)] == NULL) ? right(i) : left(i);
				if (har[i] < har[k]) {
					//finished while
					return;
				}
				else {
					swap(&har[i], &har[k]);
					i = k;
				}
			}
		}
	}
private:
	bool hasAChild(int i) {
		if (right(i) < size) {
			if (har[right(i)] != NULL || har[right(i)] != NULL) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (left(i) < size) {
			if (har[left(i)] != NULL) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	void swap(int* x, int* y) {
		int temp = *x;
		*x = *y;
		*y = temp;
	}
	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return (2 * i + 1);
	}
	int right(int i) {
		return (2 * i + 2);
	}
};