package stack

import "sort"

// InitSequenceStack 初始化顺序栈
func InitSequenceStack(n int) *SequenceStack {
	return &SequenceStack{
		stack:  make([]int, n),
		length: n,
	}
}

func InitLinkStack() *LinkStack {
	return &LinkStack{}
}

func containsDuplicate(nums []int) bool {
	sort.Ints(nums)
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] == nums[i+1] {
			return true
		}
	}
	return false
}
