#define MaxSize  100  // 预分配空间


typedef struct SqStack {
	int* base;		// 栈底指针
	int* top;		// 栈顶指针
}SqStack;


/// <summary>
/// 初始化顺序栈
/// </summary>
/// <param name="S"></param>
/// <returns></returns>
bool InitStack(SqStack& S) {
	S.base = new int[MaxSize];
	if (!S.base) return false;

	S.top = S.base;		// 初始化空栈时，栈顶和栈底地址都是同一个，且 base 不会再动，top 指向的位置必定为空元素
	return true;
}

// 出栈入栈都是在操作 top
// base ↓    ... ... top
// [] [] [] [] [] [] ->

/// <summary>
/// 入栈
/// </summary>
/// <param name="S"></param>
/// <param name="e"></param>
/// <returns></returns>

bool Push(SqStack& S, int e) {
	if (S.top - S.base == MaxSize)  return false;	// 栈满
	*S.top = e;		// 新元素，top 指向的位置必定为空元素
	S.top++;		// top++，top++ 后可能会指向 101 的位置，栈满
}


/// <summary>
/// 出栈
/// </summary>
/// <param name="S"></param>
/// <param name="e"></param>
/// <returns></returns>
bool Pop(SqStack& S, int& e) {
	if (S.base == S.top) return;	// 栈空
	S.top--;						// 栈下移一位
	e = *S.top;
	return true;
}

/// <summary>
/// 取栈顶元素
/// </summary>
/// <param name="S"></param>
/// <returns></returns>
int GetTop(SqStack S) {
	if (S.top != S.base) {
		return *(S.top - 1);		// top 指向一个空元素，在有内容的元素下一位
	}
	else {
		return -1;
	}
}