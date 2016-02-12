#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

Node* insert(Node* head, int val, int pos) 
{
    Node* point = head;
    Node* new_node = new Node(val);
    for(int i=1; i<pos; i++)
        point = point->getNext();
    if(pos==0)
    {
        new_node->setNext(head);
        return new_node;
    }
    else
    {
        new_node->setNext(point->getNext());
        point->setNext(new_node);
        return head;
    }
}

Node* remove(Node* head, int pos)
{
    Node *pointing = head;
    for(int i=1; i<pos; i++)
    {
        pointing = pointing->getNext();
    }
    if (pos==0)
    {
        pointing = head->getNext();
        free(head);
        return pointing;
    }
    else
    {
        Node *temp_node = pointing->getNext();
        pointing->setNext(temp_node->getNext());
        free(temp_node);
        return head;
    }
}

int size(Node* head)
{
	Node *next_up = head;
	int count=0;
	while(next_up!=NULL)
	{
		next_up = next_up->getNext();
        count++;
	}
	return count;	
}


Node* reverse(Node* head)
{
   if (head==NULL)
   {
       return NULL;
   }
   else
   {
       Node *pointer = head;
       Node *head_2 = new Node(pointer->getVal());
       for (int i=0; i<size(head)-1; i++)
       {
           pointer = pointer->getNext();
           head_2 = insert(head_2, pointer->getVal(), 0);
       }
       return head_2;
   }
}

int cycle_size(Node* head)
{
	int cnt_1=0;
	int cnt_2=0;
	int flag = 0;
	Node *p= head; 
	Node *q=head;
	while(p->getNext()!=0)
	{
		p =(p->getNext());
		cnt_1++;
		q = head;
		cnt_2 = 0;
		while(q!=p && p->getNext()!=q)
		{
			q=q->getNext();
			cnt_2++;
			if (p->getNext()==q)
			{
				flag++;
			}	
		}
		if (flag>0)
		{
			break;
		}
	}
	if (flag==0)
	{
		return 0;
	}
	else {return cnt_1-cnt_2+1;}
}



