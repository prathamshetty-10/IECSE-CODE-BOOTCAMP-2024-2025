#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>

template <typename T>
class VectorStack {
private:
    std::vector<T> elements;

public:
    void push(const T& value) {
        elements.push_back(value);
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack underflow");
        }
        T value = elements.back();
        elements.pop_back();
        return value;
    }

    T& top() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }

    void clear() {
        elements.clear();
    }
};