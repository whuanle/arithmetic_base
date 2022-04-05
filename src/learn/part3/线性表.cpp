
/*
���Ա�̬���䣬ȱ������Ҫ��ǰ���������ͣ����ұ���ǰ��Ҫ���ô�С
*/
#define MaxSize 100 // ���ռ�
typedef struct {
	int data[MaxSize];	// ���Ա�洢�����ͣ�һά����洢
	int length;			// ˳���ĳ��ȣ�ָԪ�ظ������� MaxSize �������鳤��
}Static_SqList;


/*
���Ա�̬����
*/
typedef struct {
	int* elem;		// Ԫ������
	int length;		// ָԪ�ظ����� MaxSize ���ǵ�ǰ�������
}Dynamic_Sqlist;


/// <summary>
/// ����һ��Ԫ�ص����Ա���
/// </summary>
/// <param name="L">���Ա�</param>
/// <param name="i">Ҫ�����λ�ã���������ʹ�� 1 ��ʼ�������� 0</param>
/// <param name="e">Ҫ�����Ԫ��</param>
/// <returns></returns>
bool ListInsert_Sq(Dynamic_Sqlist& L, int i, int e) {			// &��ʾ���ã����� C# �е� ref 
	if (i<1 || i>L.length + 1) return false;	// i ֵ���Ϸ�

	if (L.length == MaxSize) return false;		// �ռ��Ѿ����ˣ�Ԫ�ز���������ƶ���

	for (int j = L.length - 1; j >= i - 1; j--)		// ����һ��Ԫ��ʱ�������һ��Ԫ�ؿ�ʼ���ƣ�ֱ��������λ�õ�Ԫ�غ������
	{
		L.elem[j + 1] = L.elem[j];
	}

	L.elem[i - 1] = e;		// ������λ�ø�ֵ
	L.length++;				// Ԫ�ظ��� +1
	return true;
}

/// <summary>
/// ɾ��ָ��λ�õ�Ԫ�ز����ظ�������
/// </summary>
/// <param name="L">���Ա�</param>
/// <param name="i">ɾ����λ��</param>
/// <param name="e">����ָ��λ�õ�ֵ</param>
/// <returns></returns>
bool ListDelete_Sq(Dynamic_Sqlist& L, int i, int& e) {
	if (i<1 || i>L.length) return false;
	e = L.elem[i - 1];			// ȡ����ɾ��λ�õ�ֵ

	for (int j = i; j < L.length - 1; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}

	L.length--;
	return true;
}