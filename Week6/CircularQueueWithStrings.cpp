#include <iostream>
#include <string>
using namespace std;

class CircularQueue
{
private:
    int front, rear, size;
    int capacity;
    string queue[4];

public:
    CircularQueue(int cap)
    {
        capacity = cap;
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void insert(const string &value)
    {
        if (isFull())
        {
            cout << "Queue is full!"<< endl;
            return;
        }

        rear = (rear + 1) % capacity;
        queue[rear] = value;
        if (front == -1)
        {
            front = 0;
        }
        size++;
        cout << "Inserted: " << value << endl;
    }

    void deleteItem()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Deleted: " << queue[front] << endl;
        front = (front + 1) % capacity;
        size--;

        if (isEmpty())
        {
            front = -1;
            rear = -1;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue cq(5);
    int choice;
    string value;
    cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
    do
    {

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a string to insert: ";
            cin >> value;
            cq.insert(value);
            break;
        case 2:
            cq.deleteItem();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
