package tree

import "fmt"

// StackTree 栈遍历树
type StackTree struct {
	Tree
	// 树的节点数量
	count int
}

// preorderNorecursion 二叉树非递归中序遍历算法
func (tree *StackTree) preorderNorecursion() {
	if tree.root == nil {
		return
	}
	count := tree.count/2 + tree.count%2
	nodes := make([]*treeNode, count)
	top := 0
	var node *treeNode
	nodes[top] = tree.root

	for top != -1 {
		// 出栈
		top--
		node = nodes[top]
		fmt.Println(node.data)

		// 入栈 ，可能出现多个入栈
		if node.lchild != nil {
			top++
			nodes[top] = node.lchild
		}
		if node.rchild != nil {
			top++
			nodes[top] = node.rchild
		}
	}
}
