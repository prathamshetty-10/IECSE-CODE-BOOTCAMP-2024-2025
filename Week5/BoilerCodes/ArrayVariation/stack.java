package ArrayVariation;
class Stack {
    private static final int MAX = 50;
    private int[] items;
    private int top;
    public Stack() {
        items = new int[MAX];
        top = -1;
    }
    public boolean isEmpty() {
        return top == -1;
    }
    public boolean isFull() {
        return top == MAX - 1;
    }
    public boolean push(int item) {
        if (isFull()) {
            System.out.printf("Stack Overflow! Cannot push %d%n", item);
            return false;
        }
        items[++top] = item;
        return true;
    }
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow! Cannot pop from empty stack");
            return -1;
        }
        return items[top--];
    }
    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty! Cannot peek");
            return -1;
        }
        return items[top];
    }
}