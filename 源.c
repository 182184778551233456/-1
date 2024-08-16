#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
typedef struct Node {

	DataType data;
	struct Node* next;
}Node;

Node* creat_list() {
	Node* headNode = (Node*)calloc(1, sizeof(Node));
	assert(headNode);
	return headNode;
}

Node* creat_node(DataType data) {
	Node*newNode= (Node*)calloc(1, sizeof(Node));
	assert(newNode);
	newNode->data = data;
	return newNode;
}

void print_list(Node* headNode) {
	assert(headNode);
	Node* pmove = headNode->next;
	while (pmove != NULL) {
		printf("%d ", pmove->data);
		pmove = pmove->next;
	}
	printf("\n");
}

void push_front(Node* headNode, DataType data) {
	assert(headNode);
	Node* newNode = creat_node(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

void push_back(Node* headNode, DataType data) {

	assert(headNode);
	Node* newNode = creat_node(data);
	Node* pmove = headNode;
	while (pmove->next != NULL) {
		pmove = pmove->next;
	}
	pmove->next = newNode;
}



int main() {
	Node* list = creat_list();
	push_front(list, 1);
	push_front(list, 5);
	push_front(list, 1);
	push_front(list, 1);
	push_back(list, 9);
	print_list(list);

}