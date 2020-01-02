#include "stdafx.h"
#include "ALGraph.h"
 
 
/* 构造函数:初始化对象
 * 返回值:无
 * 参数:vnum:图中需要的顶点数
 */
ALGraph::ALGraph(int vnum)
: VexNum(vnum), ArcNum(0){
	// 申请邻接表
	AdjList = new VexNode[VexNum + 1];
	// 申请距离表
	Table = new TNode[VexNum + 1];
 
	// 判断是否申请成功
	if (AdjList == NULL || Table == NULL)
		cout << "邻接表申请失败!" << endl;
 
	else {
		for (int i = 0; i < VexNum + 1; i++) {
			// 初始化邻接表
			AdjList[i].Name = i;
			AdjList[i].firstArc = NULL;
 
			// 初始化距离表
			Table[i].Dist = INT_MAX;
			Table[i].Known = false;
			Table[i].Path = 0;
		}
	}
	
}
 
/* 析构函数:对象消亡时回收储存空间
 * 返回值:无
 * 参数:无
 */
ALGraph::~ALGraph()
{
	// 置空所有边
	MakeEmpty();
 
	// 删除邻接表
	delete AdjList;
	AdjList = NULL;
 
	// 删除距离表
	delete Table;
	Table = NULL;
}
 
/* 创建函数:在指定的顶点之间创建有向边
 * 返回值:无
 * 参数:无
 */
void ALGraph::Creat() {
	// 储存此次创建的边数
	// 并更新到总边数中
	int tmp;
	cout << "请输入要建立的边数:";
	cin >> tmp;
	ArcNum += tmp;
 
	// 创建所有新的有向边
	for (int i = 0; i < tmp; i++) {
		// v:有向边的头结点
		// w:有向边的尾节点
		// weight:有向边的权值
		int v, w, weight;
		cout << "请输入要建立有向边的两个顶点(v,w): ";
		cin >> v >> w;
		cout << "请输入其权值:";
		cin >> weight;
 
		// 创建新的阶段
		Position P = new ArcNode();
		if (P == NULL) {
			cout << "有向边创建失败!" << endl;
			return;
		}
 
		// 更新节点信息
		P->adjvex = w;
		P->Weight = weight;
		P->Next = AdjList[v].firstArc;
 
		// 链接到邻接表上
		AdjList[v].firstArc = P;
	}
 
}
 
/* 初始化函数:初始化距离表
 * 返回值:无
 * 参数:无
 */
void ALGraph::InitTable() {
	// 遍历距离表
	for (int i = 0; i < VexNum + 1; i++) {
		// 初始化参数
		Table[i].Dist = INT_MAX;
		Table[i].Known = false;
		Table[i].Path = 0;
	}
}
 
/* 置空函数:将所有的有向边置空
 * 返回值:无
 * 参数:无
 */
void ALGraph::MakeEmpty() {
	// 暂时储存中间节点
	Position P;
 
	// 遍历邻接表
	for (int i = 1; i < VexNum + 1; i++) {
		P = AdjList[i].firstArc;
 
		// 遍历所有链接的边
		while (P != NULL) {
			AdjList[i].firstArc = P->Next;
			delete P;
			P = AdjList[i].firstArc;
		}
	}
}
 
/* 排序函数:找出指定节点对于其他节点的最短无权路径
 * 返回值:无
 * 参数:Start:想要进行查找的节点
 */
void ALGraph::Unweighted(int Start) {
	// Q:储存队列，用于储存UnKnown节点
	// v:有向边的头结点
	// w:有向边的尾节点
	queue <int> Q;
	int v, w;
	
	// 初始化距离表
	InitTable();
 
	// 起始节点距离为0，并压入队列
	Table[Start].Dist = 0;
	Q.push(Start);
 
	while (!Q.empty()) {
		// 获取队列元素，并删除
		v = Q.front();
		Q.pop();
 
		// 该节点已知，不再需要使用
		Table[v].Known = true;
 
		// 遍历所以以该节点为头结点的有向边
		Position P = AdjList[v].firstArc;
		while (P != NULL) {
			// 获取尾节点
			w = P->adjvex;
			// 判断尾节点是否需要更新
			if (Table[w].Dist == INT_MAX) {
				// 更新信息
				Table[w].Dist = Table[v].Dist + 1;
				Table[w].Path = v;
				// 重新压入队列
				Q.push(w);
			}
 
			// 更新有向边位置
			P = P->Next;
		}
	}
}
 
/* 展示函数:展示该图的路径信息
 * 返回值:无
 * 参数:无
 */
void ALGraph::Display() {
	for (int i = 1; i < VexNum + 1; i++)
		cout << "Vex: " << i << "  ;Dist: " << Table[i].Dist << "  ; Path: " << Table[i].Path << endl;
}
 
/* Dijkstra算法:对赋权图进行单源最短路径排序
 * 返回值:无
 * 参数:Start:进行算法起始顶点
 */
void ALGraph::Dijkstra(int Start) {
	// v:单次排序的起始节点
	// w:单次排序的中值节点
	int v, w;
 
	// 初始化距离表
	InitTable();
	Table[Start].Dist = 0;
 
	// 遍历所有边
	while (true) {
		// Min:用于判断是否需要继续执行算法
		int Min = INT_MAX;
 
		// 特别注意:
		//     此处寻找最小节点使用的方法是我自己为了方便直接写的，如果
		// 用这种方法，时间复杂度应该比较高，达不到O(N * logN)的要求，所
		// 以正确的方法应该是把每个距离储存在优先队列中；
		//     当然，使用不同的优先队列也会有不同的效果，总体来说按照时
		// 间复杂度: 
		//     斐波拉契堆(O(E + V * logV)) < 配对堆(O(E * logV)) < 二叉堆(O(E * logV + V * logV))
 
		// 寻找最小的，且还未确定的有向边
		// 并将其头结点作为本次的起始节点
		for (int i = 1; i < VexNum + 1; i++)
			if (Table[i].Known == false && Min > Table[i].Dist) {
				v = i;
				Min = Table[i].Dist;
			}
 
		// 起始节点已知，不用再参与运算
		Table[v].Known = true;
 
		// 算法退出条件
		if (Min == INT_MAX)
			break;
 
		// 遍历所有以该起始节点为头结点的有向边
		Position P = AdjList[v].firstArc;
		while (P != NULL) {
			w = P->adjvex;
			// 判断尾节点是否已知
			if(Table[w].Known == false)
				if (Table[w].Dist > Table[v].Dist + P->Weight) {
					// 更新路径及距离
					Table[w].Path = v;
					Table[w].Dist = Table[v].Dist + P->Weight;
				}
 
			// 指向下一个节点
			P = P->Next;
		}
	}
}
 
/* 排序函数:用于计算具有负边值的图的最短路径
 * 返回值:无
 * 参数:Start:计算的起始节点
 */
void ALGraph::WeightNegative(int Start) {
	// Q:用于储存节点队列
	// v:单次排序的起始节点
	// w:单次排序的终止节点
	queue <int> Q;
	int v, w;
 
	// 初始化距离表
	InitTable();
	Table[Start].Dist = 0;
	Table[Start].Known = true;
	// 将起始节点压入队列
	Q.push(Start);
 
	// 遍历所有路径
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		Table[v].Known = false; // 此处状态表示没有在队列中
 
		// 遍历所有已该节点为头结点的有向边
		Position P = AdjList[v].firstArc;
		while (P != NULL) {
			w = P->adjvex;
 
			// 更新路径距离
			if (Table[w].Dist > Table[v].Dist + P->Weight) {
				Table[w].Dist = Table[v].Dist + P->Weight;
				Table[w].Path = v;
				// 若不在队列中，则压入队列
				if (Table[w].Known = false)
					Q.push(w);
			}
		}
	}
}
