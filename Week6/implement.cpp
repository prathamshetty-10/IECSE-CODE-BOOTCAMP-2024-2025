#include <iostream>

using namespace std;

class Queue
{
private:
    const static int MAX = 101; 
    int arr[MAX];              
    int front, rear, size;      

public:

    Queue()
    {
        front = 0;
        rear = -1;
        size = 0;
    }

    
    bool isFull()
    {
        return size == MAX;
    }

    
    bool isEmpty()
    {
        return size == 0; 
    }

    
    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "Queue overflow!\n";
        }
        else
        {
            arr[rear] = element;
            rear++;
            cout << "Enqueued: " << element << endl;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!\n";
            return -1;
        }
        else
        {
            int element = arr[front];
            front--;
            cout << "Dequeued: " << element << endl;
            return element;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        else
        {
            return arr[front];
        }
    }


    int getSize()
    {
        return size;
    }


    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
        }
        else
        {
            cout << "Queue elements: ";
            for (int i = 0; i < size; i++)
            {
                cout << arr[(front + i) % MAX] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue q;
    int choice, value;
    cout << "\nQueue Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Front Element\n5. Queue Size\n6. Exit\n";
    do
    {

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Front element: " << q.getFront() << endl;
            break;
        case 5:
            cout << "Current queue size: " << q.getSize() << endl;
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
