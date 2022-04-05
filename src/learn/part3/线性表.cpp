
/*
线性表静态分配，缺点是需要提前定义其类型，并且编译前就要设置大小
*/
#define MaxSize 100 // 最大空间
typedef struct {
	int data[MaxSize];	// 线性表存储的类型，一维数组存储
	int length;			// 顺序表的长度，指元素个数，而 MaxSize 才是数组长度
}Static_SqList;


/*
线性表动态分配
*/
typedef struct {
	int* elem;		// 元素类型
	int length;		// 指元素个数， MaxSize 才是当前最大容量
}Dynamic_Sqlist;


/// <summary>
/// 插入一个元素到线性表中
/// </summary>
/// <param name="L">线性表</param>
/// <param name="i">要插入的位置，非索引，使用 1 开始，而不是 0</param>
/// <param name="e">要插入的元素</param>
/// <returns></returns>
bool ListInsert_Sq(Dynamic_Sqlist& L, int i, int e) {			// &表示引用，例如 C# 中的 ref 
	if (i<1 || i>L.length + 1) return false;	// i 值不合法

	if (L.length == MaxSize) return false;		// 空间已经满了，元素不能再向后移动了

	for (int j = L.length - 1; j >= i - 1; j--)		// 插入一个元素时，从最后一个元素开始后移，直到被插入位置的元素后移完成
	{
		L.elem[j + 1] = L.elem[j];
	}

	L.elem[i - 1] = e;		// 被插入位置赋值
	L.length++;				// 元素个数 +1
	return true;
}

/// <summary>
/// 删除指定位置的元素并返回给调用者
/// </summary>
/// <param name="L">线性表</param>
/// <param name="i">删除的位置</param>
/// <param name="e">返回指定位置的值</param>
/// <returns></returns>
bool ListDelete_Sq(Dynamic_Sqlist& L, int i, int& e) {
	if (i<1 || i>L.length) return false;
	e = L.elem[i - 1];			// 取出被删除位置的值

	for (int j = i; j < L.length - 1; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}

	L.length--;
	return true;
}