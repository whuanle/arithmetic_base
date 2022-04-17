package main

import (
	"bytes"
	"encoding/binary"
	"fmt"
)

type hashNode struct {
	key   string
	value string
	next  *hashNode
}

// HashTable 哈希表
type HashTable struct {
	table  []*hashNode
	length int
}

func InitHashTable(n int) *HashTable {
	return &HashTable{
		table:  make([]*hashNode, n),
		length: n,
	}
}

func (hash *HashTable) GetHashCode(key string) int {
	bytebuff := bytes.NewBuffer([]byte(key))
	var data int64
	binary.Read(bytebuff, binary.BigEndian, &data)
	return int(data)
}

// Set 插入一个元素
func (hash *HashTable) Set(key string, value string) (bool, string) {
	index := hash.GetHashCode(key)

	// 位置还没有元素
	if hash.table[index] == nil {
		hash.table[index] = &hashNode{
			key:   key,
			value: value,
		}
	} else {
		node := hash.table[index]
		for {
			// 如果 key 相同，则覆盖，并返回旧值
			if node.key == key {
				tmp := node.value
				node.value = value
				return true, tmp
			}
			// 可以插入元素
			if node.next == nil {
				node.next = &hashNode{
					key:   key,
					value: value,
				}
				return false, ""
			}
			// 下一次检索
			node = node.next
		}
	}
	return false, ""
}

// Get 获取一个元素
func (hash *HashTable) Get(key string) (bool, string) {
	index := hash.GetHashCode(key)
	if hash.table[index] == nil {
		return false, ""
	}

	node := hash.table[index]
	for {
		if node.key == key {
			return true, node.value
		}
		if node.next == nil {
			return false, ""
		}
		node = node.next
	}
}

// 判断数组的元素是否有重复
func containsDuplicate(nums []string) bool {
	hash := InitHashTable(len(nums))

	for i := 0; i < len(nums); i++ {
		if exist, _ := hash.Set(nums[i], ""); exist {
			return exist
		}
	}
	return false
}

func main() {
	fmt.Println(containsDuplicate([]string{"1", "2", "3", "1"}))
}
