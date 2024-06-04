#include "function.h"

void inputList(list& l)
{
	int n;
	cin >> n;
	l = initList();
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		addLast(l, value);
	}
}
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
void printList(list l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->key << " ";
		p = p->next;
	}
}
void addHead(list& l, int value)
{
	node* p = getNode(value);
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		p->next = l.pHead;
		l.pHead = p;
	}
}
int sizeList(list l)
{
	int cnt = 0;
	node* p = l.pHead;
	while (p != NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}
void insertNode(list& l, int value, int position)
{
	if (position < 0 || position > sizeList(l))
	{
		return;
	}
	node* p = getNode(value);
	
	int i = 0;
	if (position == 0)
	{
		p->next = l.pHead;
		return;
	}
	node* cur = l.pHead;
	node* prev = NULL;
	while ( i < position)
	{
		i++;
		prev = cur;
		cur = cur->next;
	}
	prev->next = p;
	p->next = cur;
}
void deleteNode(list& l, int position)
{
	if (position < 0 || position >= sizeList(l))
	{
		return;
	}
	if (position == 0)
	{
		delete l.pHead;
		l.pHead = NULL;
	}
	else
	{
		node* cur = l.pHead;
		node* prev = NULL;
		int i = 0;
		while (i < position)
		{
			i++;
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		delete cur;
		cur = NULL;
	}
}
void printListReverse(node* pHead)
{
	if (pHead->next == NULL)
	{
		cout << pHead->key << " ";
	}
	else
	{
		printListReverse(pHead->next);
		cout << pHead->key << " ";
	}
}
void reverseList(list& l)
{
	if (l.pHead->next == NULL)
	{
		return;
	}
	node* prev = NULL, * cur = l.pHead, * next = NULL;
	while (cur != NULL)
	{
		next = cur->next;

		cur->next = prev;


		prev = cur;
		cur = next;

	}
	l.pHead = prev;
}
bool compareLists(list l1, list l2)
{
	node* p1 = l1.pHead, * p2 = l2.pHead;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->key != p2->key)
		{
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1 == NULL && p2 == NULL;
}
list mergeList(list l1, list l2)
{
	list l0 = initList();
	node* p1 = l1.pHead, * p2 = l2.pHead;
	if (l1.pHead == NULL)
	{
		return l2;
	}
	else if (l2.pHead == NULL)
	{
		return l1;
	}
	else
	{
		//Nếu thêm thì nhảy
		while (p1 != NULL && p2 != NULL)
		{
			if (p1->key < p2->key)
			{
				addLast(l0, p1->key);
				p1 = p1->next;
			}
			else
			{
				addLast(l0, p2->key);
				p2 = p2->next;
			}
		}

		//Thêm vào các node thừa nếu có
		while (p1 != NULL)
		{
			addLast(l0, p1->key);
			p1 = p1->next;
		}
		while (p2 != NULL)
		{
			addLast(l0, p2->key);
			p2 = p2->next;
		}

		return l0;
	}
}
int getNodeValue(list l, int position)
{
	if (position < 0 || position >= sizeList(l))
	{
		return -1;
	}
	else if (l.pHead == NULL)
	{
		return -1;
	}
	else
	{
		node* p = l.pHead;
		for (int i = 0; i < position; i++, p = p->next);
		return p->key;
	}
}
list removeDuplicates(list l)
{
	list l0 = initList();
	node* p = l.pHead;
	l0.pHead = getNode(p->key);
	
	while (p != NULL)
	{
		bool isExist = false;
		node* p0 = l0.pHead;
		while (p0 != NULL)
		{
			if (p0->key == p->key)
			{
				isExist = true;
				break;
			}
			p0 = p0->next;
		}
		if (isExist == false)
		{
			addLast(l0, p->key);
		}

		p = p->next;
	}
	return l0;
}
bool hasCycle(list l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		node* q = p->next;
		while (q != NULL)
		{
			if (q->key == p->key)
			{
				return true;
			}
			q = q->next;
		}
		p = p->next;
	}
	return false;
}
//int findMergeNode(list l1, list l2);
void sortedInsert(list& l, int value)
{
	node* p = getNode(value);
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else if(value <= l.pHead->key)
	{
		p->next = l.pHead;
		l.pHead = p;
	}
	else
	{
		node* cur = l.pHead, * prev = NULL;
		while (cur->key < value)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = p;
		p->next = cur;
	}
}
list initList()
{
	list l;
	l.pHead = NULL;
	return l;
}
void swapNode(node*& node1, node*& node2)
{
	int temp = node1->key;
	node1->key = node2->key;
	node2->key = temp;
}
void sortList(list& l)
{
	if (l.pHead == NULL || l.pHead->next == NULL)
	{
		return;
	}

	node* p = l.pHead;
	while (p != NULL)
	{
		node* q = p->next;
		node* minNode = p;
		while (q != NULL)
		{
			if (q->key < minNode->key)
			{
				minNode = q;
			}
			q = q->next;
		}
		swapNode(p, minNode);
		p = p->next;
	}
}
void addLast(list& l, int value)
{
	node* p = getNode(value);
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		node* q = l.pHead;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
	}
}