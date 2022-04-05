
// 单链表

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * Linklist;


bool ListInsert_L(Linklist& L, int i, int e) {
	int j;
	Linklist p, s;
	p = L;
	j = 0;

	// 查找 i-1 位置的节点，并且节点不为空
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}

	if (!p || j > i - 1) return false;

	// 创建新的节点并插入
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