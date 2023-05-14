#include "Graph.h"

Graph::Graph(vector<Edge> e, int n)
{
	this->Edges = e;
	this->CountV = n;

	vector<int> v(n, INF);

	vector<vector<int>>AdjMatrix2(n, v);
	AdjMatrix = AdjMatrix2;
	AdjMatrix_ = AdjMatrix2;

	for (Edge e : Edges) {
		AdjMatrix[e.V1-1][e.V2-1] = e.weight;
		AdjMatrix[e.V2-1][e.V1-1] = e.weight;
		AdjMatrix_[e.V1 - 1][e.V2 - 1] = e.weight;
	}
}



vector<int> Graph::Deycstra(int first){
	
	//vector<int> answer;
	////set<int> komponent;
	////Edge e;
	////komponent.insert(Edges[9].V1);
	////while (answer.size() < CountV ) {
	////	e = MinEdge(komponent);
	////	if (!(e.V1 == -1)) {
	////		answer.push_back(e);
	////		komponent.insert(e.V1);
	////		komponent.insert(e.V2);
	////	}
	////	else { break; }
	////}
	////return answer;
	//
	//set<int> used;
	//vector<int> line;
	//line = AdjMatrix[0];
	//used.insert(0);
	//while (used.size() < CountV) {
	//	int a = MinEdge(line);
	//	used.insert(a);
	//}
	//return answer;
	vector<int> answer;

	set<pair<int, int> > s;
	for (int i = 0; i < CountV; i++) 
		answer.push_back(INF);
	
	s.insert(make_pair(0, first-1));
	answer[first-1] = 0;
	while (!s.empty()) {

		auto p = *(s.begin());

		int node = p.second;
		int nodedist = p.first;

		s.erase(s.begin());

		for (int i = 0; i < CountV; i++) {
			if (answer[i] > nodedist + AdjMatrix[node][i]) {
				auto f = s.find(make_pair(answer[i], i));
				if (f != s.end())
					s.erase(f);
				answer[i] = nodedist + AdjMatrix[node][i];
				s.insert(make_pair(answer[i], i));
			}
		}
	}

	return answer;
}

int Graph::Dynamic(int a, int b)
{
	int count = 0;
	for (int i = 0; i < CountV; i++)
		if (AdjMatrix_[i][b] < INF-100) {
			count++;
		}
	if (count == 0) 
		return 0;
	int min = INF;
	int index=0;
	for (int i = 0; i < CountV; i++)
		if (AdjMatrix_[i][b] < min) {
			min = AdjMatrix_[i][b];
			index = i;
		}
	return min + Dynamic(a, index);;
}

int Graph::MinEdge(vector<int> ar)
{
	int min = INF;
	int count = 0;
	for (int i = 0; i < CountV; i++) {
		if (ar[i] < min) {
			min = ar[i];
			count = i;
		}
	}
	return count;
}




