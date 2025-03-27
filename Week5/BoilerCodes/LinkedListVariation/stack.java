package LinkedListVariation;

import java.util.*;

public class stack<T>{
    private ArrayList<T> list;
    
    public stack() {
        list = new ArrayList<>();
    }
    
    public void push(T element) {
        list.add(element);
    }
    
    public T pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return list.remove(list.size() - 1);
    }
    
    public T peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return list.get(list.size() - 1);
    }
    
    public boolean isEmpty() {
        return list.isEmpty();
    }
    
    public int size() {
        return list.size();
    }
}