package queue


// InitSequenceQueue 初始顺序队列
func InitSequenceQueue(n int) *SequenceQueue {
	return &SequenceQueue{
		base:   make([]int, n),
		front:  0,
		rear:   0,
		length: n,
	}
}

// InitLinkQueue 初始链队列
func InitLinkQueue(n int) *LinkQueue {
	return &LinkQueue{
		front: nil,
		rear:  nil,
	}
}
