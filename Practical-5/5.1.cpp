#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void addBeginning(string name)
{
    Node* newNode = new Node;

    newNode->song = name;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;
}

void addEnd(string name)
{
    Node* newNode = new Node;

    newNode->song = name;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode;

    tail = newNode;
}

void insertAfter(string existingSong, string newSong)
{
    Node* temp = head;

    while (temp != NULL && temp->song != existingSong)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Song not found!" << endl;
        return;
    }

    Node* newNode = new Node;

    newNode->song = newSong;

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;
}

void removeFirst()
{
    if (head == NULL)
    {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    delete temp;
}

int countSongs()
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void display()
{
    Node* temp = head;

    cout << "Playlist: ";

    while (temp != NULL)
    {
        cout << temp->song << " ";
        temp = temp->next;
    }

    cout << endl;
    cout << "Total songs: " << countSongs() << endl;
}

int main()
{
    addBeginning("Song A");
    display();

    addEnd("Song B");
    display();

    addEnd("Song C");
    display();

    insertAfter("Song B", "Song X");
    display();

    removeFirst();
    display();

    insertAfter("Song Z", "Song Y");
    display();

    return 0;
}

