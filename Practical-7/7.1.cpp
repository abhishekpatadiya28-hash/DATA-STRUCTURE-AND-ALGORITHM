#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter queue size: ";
    cin >> n;

    int queue[100];

    int front = 0;
    int rear = -1;
    int count = 0;

    int choice, value;

    while (true)
    {
        cout << "\n1. Join" << endl;
        cout << "2. Serve" << endl;
        cout << "3. Display Front" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (count == n)
            {
                cout << "Error: Queue is full!" << endl;
            }
            else
            {
                cout << "Enter token number: ";
                cin >> value;

                rear = (rear + 1) % n;
                queue[rear] = value;

                count++;

                cout << "Token added." << endl;

                if (count > 0)
                    cout << "Front token: " << queue[front] << endl;
            }
        }

        else if (choice == 2)
        {
            if (count == 0)
            {
                cout << "Error: Queue is empty!" << endl;
            }
            else
            {
                cout << "Token " << queue[front]
                     << " is served." << endl;

                front = (front + 1) % n;

                count--;

                if (count == 0)
                {
                    // Reset queue
                    front = 0;
                    rear = -1;

                    cout << "Queue is now empty." << endl;
                }
                else
                {
                    cout << "Front token: "
                         << queue[front] << endl;
                }
            }
        }

        else if (choice == 3)
        {
            if (count == 0)
                cout << "Queue is empty!" << endl;
            else
                cout << "Front token: "
                     << queue[front] << endl;
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

