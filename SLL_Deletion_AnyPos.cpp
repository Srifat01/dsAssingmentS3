#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertN(node*& head, int val);
void deletionAt(node*& head, int pos);
void display(node* head);

  int main(void)
  {
    node* head = NULL;
    int n, val, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertN(head, val);
    }

    cout << "Original list: "<<endl;
    display(head);

    cout << "Enter position to delete (0-based index): ";
    cin >> pos;

    deletionAt(head, pos);

    cout << "Updated list: " <<endl;
    display(head);
   }




void insertN(node*& head, int val)
   {
      node* newNode = new node(val);

      if (head == NULL)
      {
          head = newNode;
          return;
      }

      node* temp = head;
      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      temp->next = newNode;
   }


void deletionAt(node*& head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty" <<endl;
        return;
    }

    node* temp = head;

    if (pos == 0) // deleting head
    {
        head = temp->next;
        delete temp;
        cout << "Deleted node at position 0" <<endl;
        return;
    }

    node* prev = NULL;
    int i = 0;

    while (temp != NULL && i < pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        cout << "Position out of range"<<endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Deleted node at position " << pos << endl;
}

void display(node* head)
    {
         if (head == NULL)
         {
              cout << "List is empty" << endl;
              return;
         }

         node* temp = head;
         while (temp != NULL)
        {
              cout << temp->data << " ";
              temp = temp->next;
        }
              cout << endl;
}
