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

int maximum(stack st)
{
	if (st.pHead == NULL)
	{
		return -1;
	}
	int max = st.pHead->key;
	node* p = st.pHead->next;
	while (p != NULL)
	{
		if (p->key > max)
		{
			max = p->key;
		}
		p = p->next;
	}
	return max;
}

int sumStack(stack st)
{
	if (st.pHead == NULL)
	{
		return 0;
	}
	int sum = 0;
	node* p = st.pHead;
	while (p != NULL)
	{
		sum += p->key;
		p = p->next;
	}
	return sum;
}



int equalStack(stack st1, stack st2, stack st3)
{
	int sum1 = sumStack(st1), sum2 = sumStack(st2), sum3 = sumStack(st3);
	while (sum1 != 0)
	{
		if (sum1 == sum2 && sum2 == sum3)
		{
			return sum1;
		}
		else
		{
			if (sum1 > sum2 && sum1 > sum3)
			{
				pop(st1);
				sum1 = sumStack(st1);
			}
			else if (sum2 > sum1 && sum2 > sum3)
			{
				pop(st2);
				sum2 = sumStack(st2);
			}
			else
			{
				pop(st3);
				sum3 = sumStack(st3);
			}
		}
	}
	return 0;
}


int sizeStack(stack st)
{
	
	if (st.pHead == NULL)
	{
		return NULL;
	}
	int cnt = 0;
	node* p = st.pHead;
	while (p != NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

bool isBalance(stack st)
{
	int size = sizeStack(st), n = size / 2;
	if (size == 0 || size == 1)
	{
		return false;
	}
	stack tempStack = initStack();
	node* p = st.pHead;

	for (int i = 0; i < n; i++, p = p->next)
	{
		push(tempStack, p->key);
	}

	if (size % 2 == 0)
	{
		node* q = tempStack.pHead;
		while (q != NULL)
		{
			if (p->key != q->key)
			{
				return false;
			}
			p = p->next;
			q = q->next;
		}
	}
	else
	{
		node* q = tempStack.pHead;
		p = p->next;
		while (q != NULL)
		{
			if (p->key != q->key)
			{
				return false;
			}
			p = p->next;
			q = q->next;
		}
	}
	return true;
}

int maxSelection(int maxSum, stack st1, stack st2)
{
	int sum = 0, cnt = 0;
	while (sum < maxSum)
	{
		if (!isEmpty(st1) && (st1.pHead->key < st2.pHead->key))//Nên để điều kiện isEmpty trước vì cái tính chất gì đó mà thầy Thanh có nói
		{													   //nếu như trong điều kiện && đã có 1 cái sai thì nó sẽ không check cái còn lại	
			sum += pop(st1);
			cnt++;
		}
		else if (!isEmpty(st2))
		{
			sum += pop(st2);
			cnt++;
		}
		else break;
	}
	cnt--;
	return cnt;
}