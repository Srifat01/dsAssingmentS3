#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void Loop(node *head)
{
    node *slow = head;
    node *fast = head;
    bool found = false;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast)
        {
            cout << "Loop Found" << endl;
            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "No Loop" << endl;
    }
}

int main(void)
{
    node *a = new node(1); 
    node *b = new node(2);
    node *c = new node(3);
    node *d = new node(4);
    node *e = new node(5);
    node *f = new node(6);

    a->next = b; 
    b->next = c; 
    c->next = d; 
    d->next = e; 
    e->next = f; 
    f->next = c;   

    node *head = a;

    Loop(head);
}