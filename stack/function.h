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
int sumStack(stack st);
int equalStack(stack st1, stack st2, stack st3);
int sizeStack(stack st);
bool isBalance(stack st);
int maxSelection(int maxSum, stack st1, stack st2);
//Còn 5 bài cuối căng quá làm sau

