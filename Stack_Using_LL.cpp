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
class Stack
{
    public:
    node *tos; int size = 0; int Msize;
    Stack(int Msize)
    {
       this->Msize = Msize;
       tos = NULL;
    }
void Push(int data)
{
     if(size == Msize)
     {
        cout <<"Overflow" <<endl; return;
     }
     node *p = new node(data);
     cout <<"Pushed: ";
     size++;
     if(tos == NULL)
     {
        tos = p;
     }
     else
     {
        p->next = tos;
        tos = p;
     }
}

void Pop()
{
     if(tos == NULL)
     {
        cout <<"Stack UnderFlow"; return;
     }
     else
     {
        node *temp = tos;
        cout << "Popped "<< tos->data <<endl;
        tos = tos->next;
        delete temp;
     }
}

void display()
{
     if(tos == NULL)
     {
        cout << "Underflow" <<endl; return;
     }
     node *temp = tos;
     while(temp != NULL)
     {
           cout<< " " << temp->data;
           temp = temp->next;
     }
     cout << endl;
}
};

int main(void)
{
    Stack s(5);
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Push(50);

    s.display();

    s.Pop();
    s.Pop();

    s.display();



}