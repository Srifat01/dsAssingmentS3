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


void sort(node *&head)
{
     bool sorted = true;
     while(sorted)
     {
           sorted = false;
           while(head->next != NULL)
           {
                if(head->data > head->next->data)
                {
                    int data = head->data;
                    head->data = head->next->data;
                    head->next->data = data;
                }
                head = head->next;
                sorted = true;
           }
     }
}

int main(void)
{  
    
    node *head = NULL;
    node *tail = NULL;

    head = createSLL(head, tail, 2);
    head = createSLL(head, tail, 6);
    head = createSLL(head, tail, 4);
    head = createSLL(head, tail, 10);
    head = createSLL(head, tail, 8);

    node *temp = head;
    sort(head);

    while(temp!=NULL)
    {
        cout <<" " << temp->data;
        temp = temp->next;
    }

 
}
