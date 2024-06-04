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



void inputList(list& l);
list initList();
node* getNode(int value);
void printList(list l);
void addHead(list &l, int value);
void addLast(list& l, int value);
int sizeList(list l);
void insertNode(list& l, int value, int position);
void deleteNode(list& l, int position);
void printListReverse(node* pHead);
void reverseList(list& l);
bool compareLists(list l1, list l2);
void swapNode(node*& node1, node*& node2);
void sortList(list &l);
list mergeList(list l1, list l2);
int getNodeValue(list l, int position);
list removeDuplicates(list l);
bool hasCycle(list l);
//int findMergeNode(list l1, list l2);
void sortedInsert(list& l, int value);



