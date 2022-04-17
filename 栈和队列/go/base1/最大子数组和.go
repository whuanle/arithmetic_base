package main

import "fmt"

func maxSubArray(nums []int) int {
	max := nums[0] // 目前最大子数组之和
	sum := nums[0] // 子数组之和
	var temp int   // 临时值

	for i := 1; i < len(nums); i++ {
		temp  = sum + nums[i]
		if temp > nums[i] { // 加上后一个元素后，还可以更大
			sum = temp
		} else { // 没法更大
			sum = nums[i]
		}
		if sum > max {
			max = sum
		}
	}
	return max
}

func main() {
	nums := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	max := maxSubArray(nums)
	fmt.Println(max)
}
