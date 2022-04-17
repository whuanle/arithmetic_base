#include <cstddef>
#include <stdio.h>

typedef struct  BTNode {
	int data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;


// �Ӹ��ڵ����£������������

/// <summary>
/// �������
/// </summary>
/// <param name="p"></param>
void preorder(BTNode* p) {
	if (p != NULL) {
		Visit(p);

		preorder(p->lchild);
		preorder(p->rchild);
	}
}


/// <summary>
/// �������
/// </summary>
/// <param name="p"></param>
void inorder(BTNode* p) {
	if (p != NULL) {
		inorder(p->lchild);
		Visit(p);
		inorder(p->rchild);
	}
}


/// <summary>
/// �������
/// </summary>
/// <param name="p"></param>
void postorder(BTNode* p) {
	if (p != NULL) {
		inorder(p->lchild);
		inorder(p->rchild);
		Visit(p);
	}
}

#define maxSize 10


/// <summary>
/// ��������ǵݹ��㷨
/// </summary>
/// <param name="bt"></param>
void preorderNorecursion(BTNode* bt) {
	if (bt != NULL) {
		// �Զ���ջ������ݹ�
		BTNode* Stack[maxSize];
		int top = -1;
		BTNode* p;
		Stack[++top] = bt;
		while (top != -1)
		{
			// ��ջ
			p = Stack[top--];
			Visit(p);

			// ��ջ �����ܳ��ֶ����ջ
			if (p->rchild != NULL) {
				Stack[++top] = p->rchild;
			}

			if (p->lchild != NULL) {
				Stack[++top] = p->lchild;
			}
		}
	}
}

// ����������

void Visit(BTNode* p) {
	printf("%d", p->data);
}