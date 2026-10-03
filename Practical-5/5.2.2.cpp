#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void addStudent(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;

        newNode->next = head;
        newNode->prev = head;

        return;
    }

    Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;
}

void removeStudent(int value)
{
    if (head == NULL)
    {
        cout << "Circle is empty!" << endl;
        return;
    }

    Node* temp = head;

    do
    {
        if (temp->data == value)
            break;

        temp = temp->next;
    }
    while (temp != head);

    if (temp->data != value)
    {
        cout << "Student not found!" << endl;
        return;
    }

    if (temp->next == temp)
    {
        delete temp;
        head = NULL;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == head)
    {
        head = temp->next;
    }

    delete temp;
}

void display()
{
    if (head == NULL)
    {
        cout << "Circle is empty!" << endl;
        return;
    }

    Node* temp = head;

    cout << "Circle: ";

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while (temp != head);

    cout << endl;
}

int main()
{
    addStudent(1);
    display();

    addStudent(2);
    display();

    addStudent(3);
    display();

    addStudent(4);
    display();

    cout << "\nStudent 2 leaves:" << endl;
    removeStudent(2);
    display();

    cout << "\nStudent 1 leaves:" << endl;
    removeStudent(1);
    display();

    return 0;
}

