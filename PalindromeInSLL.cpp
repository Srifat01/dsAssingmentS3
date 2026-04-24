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

node *reverse(node *head);

bool isPalindrome(node *head)
{
    node *fast = head;
    node *slow = head;

   
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

   
    node *secondHalf = reverse(slow);
    node *temp1 = head;
    node *temp2 = secondHalf;

    
    while(temp2 != NULL)
    {
        if(temp1->data != temp2->data)
        {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
}

node *reverse(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main(void)
{
    node *a = new node(3);
    node *b = new node(7);
    node *c = new node(7);
    node *d = new node(3);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    node *head = a;

    if(isPalindrome(head))
    {
        cout << "It is a Palindrome";
    }
    else
    {
        cout << "Not a Palindrome";
    }
}