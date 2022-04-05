#define MaxSize  100  // Ԥ����ռ�


typedef struct SqStack {
	int* base;		// ջ��ָ��
	int* top;		// ջ��ָ��
}SqStack;


/// <summary>
/// ��ʼ��˳��ջ
/// </summary>
/// <param name="S"></param>
/// <returns></returns>
bool InitStack(SqStack& S) {
	S.base = new int[MaxSize];
	if (!S.base) return false;

	S.top = S.base;		// ��ʼ����ջʱ��ջ����ջ�׵�ַ����ͬһ������ base �����ٶ���top ָ���λ�ñض�Ϊ��Ԫ��
	return true;
}

// ��ջ��ջ�����ڲ��� top
// base ��    ... ... top
// [] [] [] [] [] [] ->

/// <summary>
/// ��ջ
/// </summary>
/// <param name="S"></param>
/// <param name="e"></param>
/// <returns></returns>

bool Push(SqStack& S, int e) {
	if (S.top - S.base == MaxSize)  return false;	// ջ��
	*S.top = e;		// ��Ԫ�أ�top ָ���λ�ñض�Ϊ��Ԫ��
	S.top++;		// top++��top++ ����ܻ�ָ�� 101 ��λ�ã�ջ��
}


/// <summary>
/// ��ջ
/// </summary>
/// <param name="S"></param>
/// <param name="e"></param>
/// <returns></returns>
bool Pop(SqStack& S, int& e) {
	if (S.base == S.top) return;	// ջ��
	S.top--;						// ջ����һλ
	e = *S.top;
	return true;
}

/// <summary>
/// ȡջ��Ԫ��
/// </summary>
/// <param name="S"></param>
/// <returns></returns>
int GetTop(SqStack S) {
	if (S.top != S.base) {
		return *(S.top - 1);		// top ָ��һ����Ԫ�أ��������ݵ�Ԫ����һλ
	}
	else {
		return -1;
	}
}