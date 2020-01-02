#ifndef ALGRAPH_H
#define ALGRAPH_H
 
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
 
// 重定义边节点，便于操作
typedef struct ArcNode *Position;
 
/* 边节点
 * 储存元素:
 * adjvex:该有向边连向的节点
 * Weight:该有向边的权重
 * Next:该有向边头节点的其他边节点
 */
struct ArcNode {
	int adjvex;
	int Weight;
	Position Next;
};
 
/* 顶点节点
 * 储存元素:
 * Name:该节点的姓名；
 * firstArc:该顶点链接的第一个有向边；
 */
struct VexNode {
	int Name;
	Position firstArc;
};
 
/* 表节点
 * 储存元素:
 * Known:该节点检测状态；
 * Dist:该节点到目标节点的最小距离；
 * Path:最小距离时其链接的上一个节点；
 */
struct TNode {
	bool Known;
	int Dist;
	int Path;
};
 
/* ALGraph类
 * 接口:
 * Creat:创建功能，在选定节点之间创建有向边；
 * MakeEmpty:置空功能，将所有有向边删除，初始化各个顶点；
 * Unweighted:排序功能，找出选定顶点对于其他顶点的最短无权路径；
 * Display:展示功能，展示该图的路径信息；
 * Dijkstra:Dijkstra算法，用于计算赋权图最短路径
 * WeightNegative:排序功能，用于计算具有负边值的图的最短路径
 */
class ALGraph
{
public:
	// 构造函数
	ALGraph(int = 10);
	// 析构函数
	~ALGraph();
 
	// 接口函数
	// 基础函数
	void Creat();
	void MakeEmpty();
	void Display();
 
	// 最短路径函数
	void Unweighted(int);
	void Dijkstra(int);
	void WeightNegative(int);
 
private:
	// 辅助函数
	void InitTable();
 
	// 数据成员
	int VexNum; // 储存顶点数
	int ArcNum; // 储存边数
	VexNode *AdjList; // 储存邻接表
	TNode *Table; // 储存距离表
};
 
 
#endif // !ALGRAPH_H 
