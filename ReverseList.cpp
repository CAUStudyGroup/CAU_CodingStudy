#include <iostream>
class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

SinglyLinkedListNode * Reverse(SinglyLinkedList * list) {
	SinglyLinkedListNode * tail = NULL;
	SinglyLinkedListNode * n = tail;
	SinglyLinkedListNode * cur = list->head;
	while (NULL != cur) {
		n = tail;
		tail = cur;
		cur = cur->next;
		tail->next = n;
	}
	return tail;
}

int main() {
	SinglyLinkedList * head = new SinglyLinkedList();
	head->insert_node(1);
	head->insert_node(2);
	head->insert_node(3);
	head->insert_node(4);
	head->insert_node(5);
	Reverse(head);
	return 0;
}