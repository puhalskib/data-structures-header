#pragma once


//the queue


template <typename T>
class queue {
private:
	struct node {
		T data;	//void ptr to make it ADT
		node* next;	//ptr to next struct
	};
	node* back = NULL;
	node* front = NULL;
public:
	queue() {	//constructor
		back = NULL;
		front = NULL;
	}
	queue(T a) {	//constructor
		enqueue(a);
	}
	~queue() { //destructor
		while (!isEmpty()) {
			dequeue();
		}
	}
	void enqueue(T a) {	//put a new node into the queue
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
	T getFront() {
		if (front == NULL) {
			return NULL;
		}
		else {
			return front->data;
		}
	}
	T dequeue() {	//take off the front and return value
		if (front == NULL) { //if queue is empty
			return NULL;
		}
		else {
			T ret = front->data;
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
	//display() function needs the << operator to be overloaded to work correcty with new class types
	/*
	void display(const std::string &listName) {
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
	*/

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



class minHeap {
private:
	int* root;
public:
	minHeap(unsigned int size) {
		root = new int[size];
	}
	void set(int v, int i) {
		root[i] = v;
	}
	int get(int i) {
		return root[i];
	}
};