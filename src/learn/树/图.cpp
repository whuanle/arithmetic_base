#include <cstddef>
#include <stdio.h>

#define MaxVnum 100
typedef char VexTpe; // �ڵ�����
typedef int EdgeType;  // Ȩֵ����������

typedef struct  {
	VexTpe Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum, edgenum;
}AMGraph;

