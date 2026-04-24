#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void insertion(node* &head, int key, int value);
node* createNode(int val);
void display(node* head);

    int main(void)
    {
        node* head = NULL;

        insertion(head, 0, 1); 
        insertion(head, 1, 2);
        insertion(head, 2, 3);
        insertion(head, 3, 4);

        display(head);

        insertion(head, 2, 99);
        display(head);
    }





node* createNode(int val)
{
    node* p = new node;
    p->data = val;
    p->next = NULL;
    return p;
}


void insertion(node* &head, int key, int value)
{
    node *p, *q, *r;

    p = createNode(value);
    q = head;

    
    if(head == NULL)
    {
        head = p;
        return;
    }

    
    while(q != NULL && q->data != key) // traverse to find key
    {
        r = q;
        q = q->next;
    }
    if(q == NULL) // key not found
    {
        r->next = p;
    }
    else
    {
        p->next = q->next;
        q->next = p;
    }
}

 


void display(node* head)
    {
         node* temp = head;
         while(temp != NULL)
    {
         cout << temp->data << " ";
         temp = temp->next;
    }
    cout << endl;
    }

