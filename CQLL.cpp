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

class Queue
{
private:
    node *rear, *front;

public:
    Queue()
    {
        front = rear = NULL; 
    }

    void Enqueue(int data)
    {
        node *p = new node(data);

        if(rear == NULL)
        {
            p->next = p;    
            rear = p;
            front = p;      
        }
        else
        {
            p->next = rear->next;  
            rear->next = p;        
            rear = p;            
            front = rear->next;   
        }
    }

    void Dequeue()
    {
        if(rear == NULL)
        {
            cout << "Empty List" <<endl;
            return;
        }

        node *temp = rear->next;   

        cout<< "Dequeued: " << temp->data <<endl;

        if(rear == temp)   
        {
            rear = front = NULL;
        }
        else
        {
            rear->next = temp->next;  
            front = rear->next;       
        }

        delete temp;
    }

    void display()
    {
        if(rear == NULL)
        {
            cout << "Empty List" <<endl;
            return;
        }

        node *temp = rear->next; 

        do
        {
            cout<< temp->data << " ";
            temp = temp->next;
        } while(temp != rear->next);

        cout << endl;
    }
};

int main(void)
{
    Queue q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.display();

    q.Dequeue();
    q.Dequeue();
    q.display();

    q.Enqueue(20);
    q.Enqueue(30);

    q.display();
}