#include<iostream>
using namespace std;

class Queue
{
      private:
      int queue[100];
      int front, rear;
      int size;

      public:
      Queue(int size)
      {
            this->size = size;
            rear = front = -1;
            queue[size]; 
      }

      void Enqueue(int data)
      {
           if((rear+1)%size == front)
           {
               cout << "Queue is Full" <<endl; return;
           }
           if(front == -1 && rear == -1)
           {
               front = rear = 0;
           }
           else
           {
                rear = (rear+1)%size;
           }
           queue[rear] = data;
      }

      void Dequeue()
      {
           if(front == -1 || front>rear)
           {
              cout << "Empty List"; return;
           }
           if(front == rear)
           {
              front = rear = -1;
           }
           cout << "Dequeued: "<< queue[front] <<endl;
           front = (front+1)%size;
      }

      void display()
{
        if(front == -1)
      {
        cout << "Queue is Empty" << endl;
        return;
      }

        for(int i = front; ; i = (i + 1) % size)
      {
        cout << queue[i] << " ";
        if(i == rear) break;
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
    q.display();

    q.Dequeue();
    q.Dequeue();
    q.display();

    q.Enqueue(20);
    q.Enqueue(30);

    q.display();
}