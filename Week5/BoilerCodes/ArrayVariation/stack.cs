public class Stack
{
    private const int MAX = 50;
    private int[] items;
    private int top;

    public Stack()
    {
        items = new int[MAX];
        top = -1;
    }

    public bool IsEmpty()
    {
        return top == -1;
    }

    public bool IsFull()
    {
        return top == MAX - 1;
    }

    public bool Push(int item)
    {
        if (IsFull())
        {
            Console.WriteLine($"Stack Overflow! Cannot push {item}");
            return false;
        }
        items[++top] = item;
        return true;
    }

    public int Pop()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Stack Underflow! Cannot pop from empty stack");
            return -1;
        }
        return items[top--];
    }

    public int Peek()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Stack is empty! Cannot peek");
            return -1;
        }
        return items[top];
    }
}