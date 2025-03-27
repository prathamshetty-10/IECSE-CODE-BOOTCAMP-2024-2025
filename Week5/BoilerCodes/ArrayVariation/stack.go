package main

import "fmt"

const MAX = 50

type Stack struct {
	items [MAX]int
	top   int
}

func NewStack() *Stack {
	return &Stack{
		top: -1,
	}
}

func (s *Stack) IsEmpty() bool {
	return s.top == -1
}

func (s *Stack) IsFull() bool {
	return s.top == MAX-1
}

func (s *Stack) Push(item int) bool {
	if s.IsFull() {
		fmt.Printf("Stack Overflow! Cannot push %d\n", item)
		return false
	}
	s.top++
	s.items[s.top] = item
	return true
}

func (s *Stack) Pop() int {
	if s.IsEmpty() {
		fmt.Println("Stack Underflow! Cannot pop from empty stack")
		return -1
	}
	item := s.items[s.top]
	s.top--
	return item
}

func (s *Stack) Peek() int {
	if s.IsEmpty() {
		fmt.Println("Stack is empty! Cannot peek")
		return -1
	}
	return s.items[s.top]
}
