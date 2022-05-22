#include <cstddef>
#include <stdio.h>

#define MaxVnum 100
typedef char VexTpe; // 节点类型
typedef int EdgeType;  // 权值的数据类型

typedef struct  {
	VexTpe Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum, edgenum;
}AMGraph;

