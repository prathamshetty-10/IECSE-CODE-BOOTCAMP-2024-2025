class Stack:
    def __init__(self):
        self.MAX = 50
        self.items = [0] * self.MAX
        self.top = -1

    def is_empty(self):
        return self.top == -1

    def is_full(self):
        return self.top == self.MAX - 1

    def push(self, item):
        if self.is_full():
            print(f"Stack Overflow! Cannot push {item}")
            return False
        self.top += 1
        self.items[self.top] = item
        return True

    def pop(self):
        if self.is_empty():
            print("Stack Underflow! Cannot pop from empty stack")
            return -1
        item = self.items[self.top]
        self.top -= 1
        return item

    def peek(self):
        if self.is_empty():
            print("Stack is empty! Cannot peek")
            return -1
        return self.items[self.top]