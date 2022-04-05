#include <cstddef>


typedef struct SNode {
	int data;
	struct SNode* next;
} SNode, * LinkStack;

/// <summary>
/// ��ʼ��ջ
/// </summary>
/// <param name="S"></param>
/// <returns></returns>
bool InitStack(LinkStack& S) {
	// ��ջ�У�S Ϊ NULL ����ʾû��Ԫ��
	S = NULL;
	//S = LinkStack{

	//};
	return true;
}


bool Push(LinkStack& S, int e) {
	LinkStack p;
	p = new SNode;
	p->data = e;
	p->next = S;

	S = p;
	return true;
}

bool Pop(LinkStack& S, int e) {
	LinkStack p;
	if (S == NULL) return false;

	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return true;
}

int GetTop(LinkStack S) {
	if (S != NULL) return S->data;
	return -1;
}