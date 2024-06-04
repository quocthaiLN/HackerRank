#pragma once

#include <iostream>
using namespace std;

struct node
{
	int key;
	node* next;
};

struct stack
{
	node* pHead;
};

node* getNode(int value);
stack initStack();
bool isEmpty(stack st);
void push(stack &st, int value);//addHead
int pop(stack& st);//removeHead
void input(stack& st);
void output(stack st);
int maximum(stack st);


