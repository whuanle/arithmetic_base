package tree

import "fmt"

// 通过递归算法遍历树
// 从根节点往下，从上向下输出

// preorder  前序遍历
func (tree *Tree) preorder() {
	_preorder(tree.root)
}

func _preorder(node *treeNode) {
	if node != nil {
		fmt.Println(node.data)
		_preorder(node.lchild)
		_preorder(node.rchild)
	}
}

// 中序遍历
func (tree *Tree) inorder() {
	_preorder(tree.root)
}
func _inorder(node *treeNode) {
	if node == nil {
		return
	}
	_inorder(node.lchild)
	fmt.Println(node.data)
	_inorder(node.lchild)
}

// 后续遍历
func (tree *Tree) postorder() {
	_preorder(tree.root)
}
func _postorder(node *treeNode) {
	if node == nil {
		return
	}
	_inorder(node.lchild)
	_inorder(node.lchild)
	fmt.Println(node.data)
}
