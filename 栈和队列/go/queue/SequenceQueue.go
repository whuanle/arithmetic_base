package queue

// 顺序队列使用数组存储，并且是循环的

// SequenceQueue 顺序队列
type SequenceQueue struct {
	base   []int // 队列空间
	front  int   // 队头，数组索引
	rear   int   // 队尾，数组索引
	length int   // 容量
}


// IsEmpty 判断队列元素数量是否为空
func (queue *SequenceQueue) IsEmpty() bool {
	if queue == nil {
		return false
	}
	// 注意，队列元素为空，不代表 front、rear 都在 0 的位置上
	//        在同一位置
	//         front
	//         rear
	//  |  |  |  |  |  | |
	return queue.front == queue.rear
}

// isFull 队列是否已满
func (queue *SequenceQueue) isFull() bool {
	return (queue.rear+1)%queue.length == queue.front
}

// 两种情况，
// front 在 rear 前面
// front                 rear
// 0 | 1 | 2 | 3 | 4 | 5 | |
// rear 在 front 前面，避免假溢出
//    rear    front
// 0 |   |   | 3 | 4 | 5 | 6 |

// 如果队列为空，则 rear 指向 0，
// 如果队列不为空，则 rear 指向空元素的位置，即队列尾元素的下一位。
// front         rear
// 0 | 1 | 2 | 5| | | |

// EnQueue 入队
func (queue *SequenceQueue) EnQueue(value int) bool {
	// 队列已满
	// 判断队列是否已经满，如果元素指向最大容量的最后一位
	// 下面即表示队列已满
	//         rear front
	// 0 | 1  |   | 3 | 4 | 5 | 6 |
	// 牺牲队列最后一位，
	// 使用 queue.front == queue.rear 判断队列是否为空，
	// 如果 (queue.rear+1)%cap(queue.base)，判断是否已满
	if (queue.rear+1)%queue.length == queue.front {
		return false
	}
	queue.base[queue.rear] = value
	queue.rear = (queue.rear + 1) % queue.length // 不能直接 +1
	return true
}

// DeQueue 出队
func (queue *SequenceQueue) DeQueue() (int, bool) {
	// 队列为空
	if queue.front == queue.rear {
		return 0, false
	}
	value := queue.base[queue.front]
	queue.front = (queue.front + 1) % queue.length
	return value, true
}

// Front 从队首获取元素
func (queue *SequenceQueue) Front() (int, bool) {
	// 队列为空
	if queue.front == queue.rear {
		return 0, false
	}
	return queue.base[queue.front], true
}

// Rear 获取队尾元素
func (queue *SequenceQueue) Rear() (int, bool) {
	// 队列为空
	if queue.front == queue.rear {
		return 0, false
	}
	if queue.rear == 0 {
		return queue.base[queue.length], true
	}

	index := (queue.rear - 1) % queue.length
	return queue.base[index], true
}