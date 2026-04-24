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
      node *front , *rear;
      int size = 0; int Msize = 0;

      public:
      Queue(int Msize)
      {
         this->Msize = Msize;
         front = rear = NULL;
      }

      void Enqueue(int data)
      {
           if(Msize == size)
           {
             cout << "Queue is Full "<<endl; return;
           }
           node *p = new node(data);
           if(front == NULL && rear == NULL)
           {
              front = rear = p;
           }
           else
           {
              rear->next = p;
              rear = p;
           }
           cout << "Enqueued: "<< data << endl;
      }

      void Dequeue()
      {
           if(front == NULL)
           {
              cout << "Queue is Empty "<<endl;
           }
           node *temp = front;
           cout << "Dequeued: "<< front->data <<endl;
           front = front->next;
           delete temp;
      }
      void display()
{
        if(front == NULL)
      {
        cout << "Empty Queue" <<endl; return;
      }
        node *temp = front;
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
    Queue q(5);
    
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
//    q.Enqueue(6); Triggers Overflow

    q.display();

    q.Dequeue();
    q.Dequeue();

    q.display();
    
}