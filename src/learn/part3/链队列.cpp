#include <cstddef>

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode, * Qptr;

typedef struct {
	QNode* front;		// ͷ��
	QNode* rear;		// β��
}LinkQueue;

/*
ͷ������β����
*/


void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;	// ��ʱͷָ���βָ�붼��ͬһ������ next ���ǿգ�ͷָ���βָ��ָ��ͷ�ڵ㣻
	Q.front->next = NULL;			// ͷ����������ݣ�ֻ���ָ��
}

/// <summary>
/// ���
/// </summary>
/// <param name="Q">ͷ��ָ��</param>
/// <param name="e"></param>
void EnQueue(LinkQueue& Q, int e) {
	Qptr s;
	s = new QNode;	// �µĽڵ�
	s->data = e;
	s->next = NULL;

	Q.rear->next = s;		// ����β����β������� s����һ��Ԫ�ص� next ָ�� S
	Q.rear = s;
}

/// <summary>
/// ����
/// </summary>
/// <param name="Q">ͷ��ָ��</param>
/// <param name="e"></param>
/// <returns></returns>
bool DeQueue(LinkQueue& Q, int& e) {
	if (Q.front == Q.rear) return false;	// ջΪ��

	// ��ȡ���е�һ��������ֵ    [front] [1]
	Qptr p = Q.front->next;					// ͷ����������ݣ�ֻ���ָ�룬�����ʵ��һ��Ԫ�ز��ǵ�һ��������; p = [1]
	e = p->data;

	// �Ƴ�����ڵ�
	Q.front->next = p->next;   // [front] ...

	// �ж����Ƴ��ڵ�ǰ���Ƿ�ֻ��һ������Ԫ�أ�����ǵĻ��� Q.rear == p,�� Q.front.next = p
	if (Q.rear == p) {
		Q.rear = Q.front;  // ɾ����õ�����Ԫ�غ󣬱�� [front] ��ͷָ���βָ��ָ��ͷ�ڵ�
	}
	delete p;
	return true;
}

/// <summary>
/// ȡ����ͷ��Ԫ��
/// </summary>
/// <param name="Q"></param>
/// <returns></returns>
int GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)	// ������в�Ϊ��
		return Q.front->next->data;		// ȡ��ͷָ����һ��Ԫ�ص�ֵ
	return -1;
}