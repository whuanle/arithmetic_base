package tree

// treeNode 二叉树节点
type treeNode[T any] struct {
	data T
	// lchild 左孩
	lchild *treeNode
	// 右孩
	rchild *treeNode
}

// Tree 二叉树
type Tree[T any] struct {
	root *treeNode
}
