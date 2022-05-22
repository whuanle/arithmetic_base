package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	top := make([][]int, 0) // 全部
	if root == nil {
		return top
	}
	// 顶层
	level := 0
	currentQueue := make([]*TreeNode, 0)
	currentQueue = append(currentQueue, root)

	for 0 < len(currentQueue) {
		top = append(top, make([]int, 0))
		lastQueue := make([]*TreeNode, 0)

		for _, value := range currentQueue {
			top[level] = append(top[level], value.Val)
			if value.Left != nil {
				lastQueue = append(lastQueue, value.Left)
			}
			if value.Right != nil {
				lastQueue = append(lastQueue, value.Right)
			}
		}
		currentQueue = lastQueue
		// 如果还有下一层
		if len(lastQueue) != 0 {
			level++
		}
	}
	return top
}

// 获取二叉树的深度
func GetLevel(root *TreeNode) int {
	if root == nil {
		return 0
	}
	level := 0
	currentQueue := make([]*TreeNode, 0)
	currentQueue = append(currentQueue, root)
	for 0 < len(currentQueue) {
		lastQueue := make([]*TreeNode, 0)

		for _, value := range currentQueue {
			if value.Left != nil {
				lastQueue = append(lastQueue, value.Left)
			}
			if value.Right != nil {
				lastQueue = append(lastQueue, value.Right)
			}
		}
		currentQueue = lastQueue
		// 如果还有下一层
		if len(lastQueue) != 0 {
			level++
		}
	}
	return level + 1
}

// 对称二叉树
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	// 顶层
	level := 0
	currentQueue := make([]*TreeNode, 0)
	currentQueue = append(currentQueue, root)

	for 0 < len(currentQueue) {
		lastQueue := make([]*TreeNode, 0)

		// 生成这一层的节点
		for _, value := range currentQueue {
			if value.Left != nil {
				lastQueue = append(lastQueue, value.Left)
			}
			if value.Right != nil {
				lastQueue = append(lastQueue, value.Right)
			}
		}
		// 检查是否对称
		if len(lastQueue)%2 != 0 {
			return false
		}
		length := len(lastQueue) - 1
		for i := 0; i < length-1; i++ {
			if lastQueue[i].Val != lastQueue[length-i].Val {
				return false
			}
		}
		currentQueue = lastQueue
		// 如果还有下一层
		if len(lastQueue) != 0 {
			level++
		}
	}
	return true
}

//// GetLevelR  递归方法获取二叉树的深度
//func GetLevelR(root *TreeNode) {
//	if root == nil {
//		return
//	}
//	count := 1
//	_GetLevelR(root, &count)
//
//}
//
//func _GetLevelR(root *TreeNode, count *int) {
//	if root == nil {
//		return
//	}
//	*count++
//	_GetLevelR(root.Left, count)
//	_GetLevelR(root.Right, count)
//}
