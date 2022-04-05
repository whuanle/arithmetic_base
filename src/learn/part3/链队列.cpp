#include <cstddef>

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode, * Qptr;

typedef struct {
	QNode* front;		// 头部
	QNode* rear;		// 尾部
}LinkQueue;

/*
头部出，尾部入
*/


void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;	// 此时头指针和尾指针都是同一个，且 next 都是空；头指针和尾指针指向头节点；
	Q.front->next = NULL;			// 头部不存放数据，只存放指针
}

/// <summary>
/// 入队
/// </summary>
/// <param name="Q">头部指针</param>
/// <param name="e"></param>
void EnQueue(LinkQueue& Q, int e) {
	Qptr s;
	s = new QNode;	// 新的节点
	s->data = e;
	s->next = NULL;

	Q.rear->next = s;		// 插入尾部，尾部变成了 s，上一个元素的 next 指向 S
	Q.rear = s;
}

/// <summary>
/// 出队
/// </summary>
/// <param name="Q">头部指针</param>
/// <param name="e"></param>
/// <returns></returns>
bool DeQueue(LinkQueue& Q, int& e) {
	if (Q.front == Q.rear) return false;	// 栈为空

	// 获取队列第一个数据项值    [front] [1]
	Qptr p = Q.front->next;					// 头部不存放数据，只存放指针，因此其实下一个元素才是第一个数据项; p = [1]
	e = p->data;

	// 移除这个节点
	Q.front->next = p->next;   // [front] ...

	// 判断在移除节点前，是否只有一个数据元素，如果是的话， Q.rear == p,且 Q.front.next = p
	if (Q.rear == p) {
		Q.rear = Q.front;  // 删除最好的数据元素后，变成 [front] ，头指针和尾指针指向头节点
	}
	delete p;
	return true;
}

/// <summary>
/// 取队列头部元素
/// </summary>
/// <param name="Q"></param>
/// <returns></returns>
int GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)	// 如果队列不为空
		return Q.front->next->data;		// 取出头指针后后一个元素的值
	return -1;
}