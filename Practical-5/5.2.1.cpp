#include <iostream>
using namespace std;

struct Node
{
    int data;
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
        return;
    }

    Node* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void removeStudent(int value)
{
    if (head == NULL)
    {
        cout << "Circle is empty!" << endl;
        return;
    }

    if (head->next == head)
    {
        if (head->data == value)
        {
            delete head;
            head = NULL;
        }
        return;
    }

    if (head->data == value)
    {
        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = head->next;

        Node* deleteNode = head;
        head = head->next;

        delete deleteNode;
        return;
    }

    Node* temp = head;

    while (temp->next != head &&
           temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == head)
    {
        cout << "Student not found!" << endl;
        return;
    }

    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;
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
