

#define MaxSize 100

// 顺序队列

typedef struct SqQueue {
	int* base;
	int front, rear;
}SqQueue;

void InitQueue(SqQueue& S) {
	S = SqQueue{};
	S.front = S.rear = 0;		// 两个保存的都是索引
}

/*
使用的是牺牲最后一位空间，当 front == rear 时，说明队列空；如果 (rear+1)%MaxSize = front 时，说明队列满
*/

/// <summary>
/// 判断队列是否为空
/// </summary>
/// <param name="S"></param>
/// <returns></returns>
bool QueueIsEmpty(SqQueue& Q) {
	Q.base = new int[MaxSize];
	if (!Q.base) return false;
	Q.front = Q.rear = 0;
	return true;
}

/// <summary>
/// 入队列
/// </summary>
/// <param name="Q"></param>
/// <param name="e"></param>
/// <returns></returns>
bool EnQueue(SqQueue Q, int e) {
	if ((Q.rear + 1) % MaxSize == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

/// <summary>
/// 出队列
/// </summary>
/// <param name="Q"></param>
/// <param name="e"></param>
/// <returns></returns>
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) return false;

	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MaxSize;

	return true;
}

int  GetHead(SqQueue Q) {
	if (Q.front != Q.rear) return Q.base[Q.front];
	return -1;
}