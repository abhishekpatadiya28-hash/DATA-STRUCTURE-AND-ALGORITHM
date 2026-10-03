#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter stack size: ";
    cin >> n;

    int stack[100];
    int top = -1;

    int choice, value;

    while (true)
    {
        cout << "\n1. Place (Push)" << endl;
        cout << "2. Take (Pop)" << endl;
        cout << "3. Display Top" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (top == n - 1)
            {
                cout << "Error: Stack is full!" << endl;
            }
            else
            {
                cout << "Enter tray number: ";
                cin >> value;

                top++;
                stack[top] = value;

                cout << "Tray placed successfully." << endl;
                cout << "Top tray: " << stack[top] << endl;
            }
        }

        else if (choice == 2)
        {
            if (top == -1)
            {
                cout << "Error: Stack is empty!" << endl;
            }
            else
            {
                cout << "Tray " << stack[top] << " taken." << endl;

                top--;

                if (top == -1)
                    cout << "Stack is now empty." << endl;
                else
                    cout << "Top tray: " << stack[top] << endl;
            }
        }

        else if (choice == 3)
        {
            if (top == -1)
                cout << "Stack is empty!" << endl;
            else
                cout << "Top tray: " << stack[top] << endl;
        }

        else if (choice == 4)
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

