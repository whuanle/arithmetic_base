package stack


type linkStackNode struct {
	data int
	next *linkStackNode
}

// LinkStack 链栈
type LinkStack struct {
	top *linkStackNode
}

// Push 入栈
func (stack *LinkStack) Push(value int) bool {
	top := &linkStackNode{
		data: value,
		next: stack.top,
	}
	stack.top = top
	return true
}

// Pop 入栈
func (stack *LinkStack) Pop(value int) (int, bool) {
	if stack.top == nil {
		return 0, false
	}
	next := stack.top
	stack.top = next.next
	return next.data, true
}
