#include "function.h"

node* getNode(int value)
{
	node* p = new node;
	if (p == NULL)
	{
		return NULL;
	}
	p->key = value;
	p->next = NULL;
	return p;
}

stack initStack()
{
	stack st;
	st.pHead = NULL;
	return st;
}
bool isEmpty(stack st)
{
	if (st.pHead == NULL)
	{
		return true;
	}
	else return false;
}
void push(stack& st, int value)
{
	node* p = getNode(value);
	if (st.pHead == NULL)
	{
		st.pHead = p;
	}
	else
	{
		p->next = st.pHead;
		st.pHead = p;
	}
}
int pop(stack& st)
{
	if (st.pHead == NULL)
	{
		return -1;
	}
	else
	{
		node* tempNode = st.pHead;
		st.pHead = st.pHead->next;
		int tempKey = tempNode->key;
		delete tempNode;
		tempNode = NULL;
		return tempKey;
	}
}

void input(stack& st)
{
	st = initStack();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		push(st, value);
	}
}
void output(stack st)
{
	node* p = st.pHead;
	while (p != NULL)
	{
		cout << p->key << " ";
		p = p->next;
	}
}