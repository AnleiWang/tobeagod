#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int _data) {
		data = _data;
		next = NULL;
	}
};

class LinkedList {
private:
	Node *head;
public:
	LinkedList() {
		head = NULL;
	}
	~LinkedList() {
		if (head == NULL) {
			return ;
		}
		Node *current_node = head->next;
		head->next = NULL;
		while(current_node != NULL) {
			Node *delete_node = current_node;
			current_node = current_node->next;
			delete delete_node;
		}
	}
	void insert(Node *node, int index) {
		if (head == NULL) {
			if (index != 0) {
				return ;
			}
			head = node;
			head->next = head;
			return ;
		}
		if (index == 0) {
			node->next = head->next;
			head->next = node;
			return;
		}
		Node *current_node = head->next;
		int count = 0;
		while (current_node != NULL && count < index-1) {
			current_node = current_node->next;
			count ++;
		}
		if (count == index - 1) {
			node->next = current_node->next;
			current_node->next = node;
		}
		if (node == head->next) {
			head = node;
		}
	}
	void output(int k, int m) {
		Node *current_node = head;
		head = NULL;
		for (int i = 1; i < k; i++) { 
			current_node = current_node->next;
		}
		while(current_node->next != current_node) {
			for (int i = 0; i < m - 1; i++) {
				current_node = current_node->next;
			}
			Node *delete_node = current_node->next;
			current_node->next = current_node->next->next;
			delete delete_node;
		}
		cout << current_node->data;
	}
};

int main() {
	LinkedList linkedlist;
	int n, k, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		Node *node = new Node(i);
		linkedlist.insert(node, i - 1);
	}
	cin >> k >> m;
	linkedlist.output(k, m);
	return 0;
}
