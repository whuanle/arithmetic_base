
// ������

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * Linklist;


bool ListInsert_L(Linklist& L, int i, int e) {
	int j;
	Linklist p, s;
	p = L;
	j = 0;

	// ���� i-1 λ�õĽڵ㣬���ҽڵ㲻Ϊ��
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}

	if (!p || j > i - 1) return false;

	// �����µĽڵ㲢����
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;

	return true;
}

bool ListDelete_L(Linklist& L, int i) {
	Linklist p, q;
	int j;
	p = L;
	j = 0;

	while ((p->next) && (j < i - 1)) {
		p = p->next;
		j++;
	}

	if (!(p->next) || (j > i - 1)) return false;

	q = p->next;
	p->next = q->next;
	delete q;
	return true;
}