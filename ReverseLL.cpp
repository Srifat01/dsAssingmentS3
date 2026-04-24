#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int data)
    {
        this->data= data;
        next = NULL;
    }
};

node *createSLL(node *head, node *&tail, int val)
{
    
     node *p = new node(val);
     if(head == NULL && tail == NULL)
     {
        head = tail = p;
     }
     else
     {
        tail->next= p;
        tail = p;
     }
     return head;
}

void display(node *head)
{
    node *temp = head;
    while (temp!=NULL)
    {
           cout << " " << temp->data;
           temp = temp->next;
    }
}

node *reverse(node *&head);
int main(void)
{  
    
    node *head = NULL;
    node *tail = NULL;

    head = createSLL(head, tail, 2);
    head = createSLL(head, tail, 3);
    head = createSLL(head, tail, 4);
    head = createSLL(head, tail, 5);
    head = createSLL(head, tail, 6);

    display(head);

    node *temp = reverse(head);
    display(temp);


    
}

node *reverse(node *&head)
{
     node *prev = NULL;
     node *curr = head;
     node *next = NULL;

     while (curr != NULL)
     {
           next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
     }
     head = prev;
     return head;
}