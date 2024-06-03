#pragma once

#include <iostream>
using namespace std;

struct node
{
	int key;
	node* next;
};

struct list
{
	node* pHead;
};

node* getNode(int value);
void printList(list l);
void addHead(list &l, int value);
void insertNode(list& l, int value, int position);
void deleteNode(list& l, int position);
void printListReverse(list l);
void reverseList(list& l);
bool compareLists(list l1, list l2);
list mergeList(list& l1, list& l2);
int getNodeValue(list l, int position);
list removeDuplicates(list l);
bool hasCycle(list l);




