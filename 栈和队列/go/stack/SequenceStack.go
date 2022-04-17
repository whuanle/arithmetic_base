package stack

// SequenceStack 顺序栈
type SequenceStack struct {
	stack  []int
	length int
	base   int // 栈底索引
	top    int //  栈顶索引
}

//  base                top
// | 0 | 1 | 2 | 3 | 4 |

// Push 入栈
func (stack *SequenceStack) Push(value int) bool {
	// 栈满
	// top 值大于数组索引 4，或等于数组长度 5
	// stack.top-stack.base == stack.length
	if stack.top == stack.length {
		return false
	}
	stack.stack[stack.top] = value
	stack.top++
	return true
}

// Pop 入栈
func (stack *SequenceStack) Pop(value int) (int, bool) {
	// 空栈
	if stack.top == stack.base {
		return 0, false
	}
	// 下退一个位置
	stack.top--
	return stack.stack[stack.top], true
}

