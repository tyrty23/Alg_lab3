#include"Graph.h"

void main()
{
	vector<Edge> Edges;
	vector<int> deycstra;

	Edges.push_back(Edge::Edge(1, 2, 8));
	Edges.push_back(Edge::Edge(1, 4, 5));
	Edges.push_back(Edge::Edge(1, 6, 9)); 

	Edges.push_back(Edge::Edge(2, 4, 1));
	Edges.push_back(Edge::Edge(2, 3, 2));

	Edges.push_back(Edge::Edge(3, 5, 3));
	Edges.push_back(Edge::Edge(3, 8, 10));

	Edges.push_back(Edge::Edge(4, 5, 9));
	Edges.push_back(Edge::Edge(4, 6, 3));

	Edges.push_back(Edge::Edge(5, 8, 6));
	Edges.push_back(Edge::Edge(5, 7, 4));

	Edges.push_back(Edge::Edge(6, 7, 12));
	Edges.push_back(Edge::Edge(7, 8, 7));
	
	Graph g(Edges, 8);


	auto begin = chrono::steady_clock::now();
	deycstra = g.Deycstra(1);
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "\nThe time of Deycstra: " << elapsed_ms.count() << " mcss\n";

	for (int i = 0; i < deycstra.size(); i++) {
		cout << deycstra[i] << " ";
	}

	Edges.clear();
	Edges.push_back(Edge::Edge(1, 2, 9));
	Edges.push_back(Edge::Edge(1, 3, 2));
	Edges.push_back(Edge::Edge(3, 2, 6));
	Edges.push_back(Edge::Edge(2, 4, 4));
	Edges.push_back(Edge::Edge(2, 5, 12));
	Edges.push_back(Edge::Edge(3, 5, 28));
	Edges.push_back(Edge::Edge(3, 6, 10));
	Edges.push_back(Edge::Edge(4, 5, 16));
	Edges.push_back(Edge::Edge(6, 5, 15));
	Edges.push_back(Edge::Edge(4, 7, 19));
	Edges.push_back(Edge::Edge(5, 7, 3));
	Edges.push_back(Edge::Edge(6, 7, 25));
	Graph g2(Edges, 7);

	/*for (int i = 0; i < 7; i++) {
		cout << endl;
		for (int j = 0; j < 7; j++) 
			cout << g2.AdjMatrix[i][j] << " ";
		
	}*/

	begin = chrono::steady_clock::now();
	cout<<"\n\n"<<"Dynamic: " << g2.Dynamic(0, 6) << endl;
	end = chrono::steady_clock::now();
	elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "\nThe time of Dynamic: " << elapsed_ms.count() << " mcss\n";
}
