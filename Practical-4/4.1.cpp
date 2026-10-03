#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);

        newNode->next = front;
        front = newNode;


        if (rear == nullptr) {
            rear = newNode;
        }
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (front == nullptr) {
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }


    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);


        if (position <= 1) {
            insertFront(value);
            delete newNode;
            return;
        }

        Node* temp = front;


        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }


        if (temp == nullptr) {
            cout << "Invalid position! Insertion not possible.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

                if (newNode->next == nullptr) {
            rear = newNode;
        }
    }


    void display() {
        Node* temp = front;

        cout << "Queue: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.insertEnd(10);
    q.display();

    q.insertEnd(20);
    q.display();

    q.insertFront(5);
    q.display();

    q.insertAtPosition(15, 3);
    q.display();

    q.insertAtPosition(50, 10);
    q.display();

    return 0;
}
