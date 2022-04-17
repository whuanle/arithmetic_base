package queue

// LinkQueueNode 链队列节点
type linkQueueNode struct {
	data int
	next *linkQueueNode
}

// 链队列的头部不存储数据，只存储 next 指向下一个节点，
// 链队列的尾部存储数据，next 为 nil。

// LinkQueue 链队列
type LinkQueue struct {
	front *linkQueueNode
	rear  *linkQueueNode
}

// IsEmpty 判断队列元素数量是否为空
func (queue *LinkQueue) IsEmpty() bool {
	if queue == nil {
		return false
	}
	// queue.front queue.rear 都是 nil
	return queue.front == queue.rear
}

// EnQueue 入队
func (queue *LinkQueue) EnQueue(value int) bool {
	// 新的节点
	next := &linkQueueNode{
		data: value,
	}
	// 直接在后面插入新的节点即可
	queue.rear.next = next
	queue.rear = next
	return true
}

// DeQueue 出队
func (queue *LinkQueue) DeQueue() (int, bool) {
	// 队列为空
	if queue.front == queue.rear {
		return 0, false
	}

	current := queue.front.next
	queue.front.next = current.next

	// 如果队列只有一个元素，则删除后想要修改队尾指针
	// 即，队尾元素，就是 front 的 next，说明出队这个元素后队列为空
	if queue.rear == current {
		queue.rear = queue.front
	}
	// 回收 current
	return current.data, true
}

// Front 从队首获取元素
func (queue *LinkQueue) Front() (int, bool) {
	// 队列为空
	if queue.front == queue.rear {
		return 0, false
	}
	return queue.front.next.data, true
}

// Rear 获取队尾元素
func (queue *LinkQueue) Rear() (int, bool) {
	// 队列为空
	if queue.front == queue.rear {
		return 0, false
	}
	return queue.rear.data, true
}
