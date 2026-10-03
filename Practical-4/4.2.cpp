#include <iostream>
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

    void insertFront(int value) {
        Node* newNode = new Node(value);

        newNode->next = front;
        front = newNode;

        if (rear == nullptr) {
            rear = newNode;
        }
    }

    void insertAtPosition(int value, int position) {

        if (position <= 1) {
            insertFront(value);
            return;
        }

        Node* temp = front;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position! Insertion not possible.\n";
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr) {
            rear = newNode;
        }
    }

    void deleteByValue(int value) {

        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        if (front->data == value) {
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;

            cout << value << " deleted.\n";
            return;
        }

        Node* current = front;

        while (current->next != nullptr &&
               current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << value << " not found.\n";
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;

        if (temp == rear) {
            rear = current;
        }

        delete temp;

        cout << value << " deleted.\n";
    }

    void displayForward() {
        Node* temp = front;

        cout << "Queue from front to back: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayReverse(Node* temp) {

        if (temp == nullptr) {
            return;
        }

        displayReverse(temp->next);

        cout << temp->data << " ";
    }

    void reversePrint() {
        cout << "Queue from back to front: ";

        displayReverse(front);

        cout << endl;
    }

    Node* getFront() {
        return front;
    }
};

int main() {

    Queue q;

    q.insertEnd(10);
    q.insertEnd(20);
    q.insertEnd(30);
    q.insertEnd(40);
    q.insertEnd(50);

    q.displayForward();

    q.deleteByValue(30);

    q.displayForward();

    q.reversePrint();

    q.displayForward();

    return 0;
}

