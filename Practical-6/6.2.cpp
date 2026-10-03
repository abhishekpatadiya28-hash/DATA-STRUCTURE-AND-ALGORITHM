#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string page;
    Node* next;
};

Node* top = NULL;

void visit(string page)
{
    Node* newNode = new Node;

    newNode->page = page;
    newNode->next = top;

    top = newNode;

    cout << "Current page: " << top->page << endl;
}

void back()
{
    if (top == NULL)
    {
        cout << "No history left. Cannot go back." << endl;
        return;
    }

    Node* temp = top;

    top = top->next;

    delete temp;

    if (top == NULL)
        cout << "No page left." << endl;
    else
        cout << "Current page: " << top->page << endl;
}

int main()
{
    int choice;
    string page;

    while (true)
    {
        cout << "\n1. Visit page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter page name: ";
            cin >> page;

            visit(page);
        }

        else if (choice == 2)
        {
            back();
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

