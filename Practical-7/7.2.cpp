#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string patient;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void arrive(string name)
{
    Node* newNode = new Node;

    newNode->patient = name;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Patient arrived." << endl;
    cout << "Front patient: " << front->patient << endl;
}

void attend()
{
    if (front == NULL)
    {
        cout << "Error: No patients waiting!" << endl;
        return;
    }

    Node* temp = front;

    cout << "Patient " << front->patient
         << " is being attended." << endl;

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
        cout << "No patients waiting." << endl;
    }
    else
    {
        cout << "Front patient: "
             << front->patient << endl;
    }

    delete temp;
}

int main()
{
    int choice;
    string name;

    while (true)
    {
        cout << "\n1. Arrive" << endl;
        cout << "2. Attend" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter patient name: ";
            cin >> name;

            arrive(name);
        }

        else if (choice == 2)
        {
            attend();
        }

        else if (choice == 3)
        {
            break;
        }

        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

