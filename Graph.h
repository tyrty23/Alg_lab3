#pragma once
#include "Edge.h"
#include <vector>
#include <algorithm>
#include <set>
#include <chrono>


const int INF = 1e4;

class Graph
{

public:
	int CountV;
	vector<Edge> Edges;

	vector<vector<int>> AdjMatrix;

	vector<vector<int>> AdjMatrix_;

	Graph(vector<Edge>, int);

	vector<int> Deycstra(int);

	int Dynamic(int, int);

	int MinEdge(vector<int>);

};

