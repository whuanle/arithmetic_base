#include <cstddef>
#include <stdio.h>

typedef struct  BTNode {
	int data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;


// 从根节点往下，从上向下输出

/// <summary>
/// 先序遍历
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
/// 中序遍历
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
/// 后序遍历
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
/// 先序遍历非递归算法
/// </summary>
/// <param name="bt"></param>
void preorderNorecursion(BTNode* bt) {
	if (bt != NULL) {
		// 自定义栈，避免递归
		BTNode* Stack[maxSize];
		int top = -1;
		BTNode* p;
		Stack[++top] = bt;
		while (top != -1)
		{
			// 出栈
			p = Stack[top--];
			Visit(p);

			// 入栈 ，可能出现多个入栈
			if (p->rchild != NULL) {
				Stack[++top] = p->rchild;
			}

			if (p->lchild != NULL) {
				Stack[++top] = p->lchild;
			}
		}
	}
}

// 线索二叉树

void Visit(BTNode* p) {
	printf("%d", p->data);
}