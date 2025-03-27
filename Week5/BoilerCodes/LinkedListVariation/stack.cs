public class LinkedListStack<T>
{
    private LinkedList<T> list;
    
    public LinkedListStack()
    {
        list = new LinkedList<T>();
    }
    
    public void Push(T element)
    {
        list.AddFirst(element);
    }
    
    public T Pop()
    {
        if (IsEmpty())
        {
            throw new InvalidOperationException("Stack is empty");
        }
        
        T element = list.First.Value;
        list.RemoveFirst();
        return element;
    }
    
    public T Peek()
    {
        if (IsEmpty())
        {
            throw new InvalidOperationException("Stack is empty");
        }
        
        return list.First.Value;
    }
    
    public bool IsEmpty()
    {
        return list.Count == 0;
    }
    
    public int Size()
    {
        return list.Count;
    }
}