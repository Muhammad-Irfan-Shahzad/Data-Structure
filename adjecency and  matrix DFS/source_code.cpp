
#include<iostream>
using namespace std;
class Graph {

	int v;

	int e;

	int** adj;
 
  bool visited[31623] = {false};
public:
	Graph(int v, int e);

	void addEdge(int start, int e);

	void DFS(int start,bool visited[]);
	
	
	void printGraph() {
		cout<<"Src    "<<"   des \n";
  for (int d = 0; d < v; ++d) {
   
    for (int j=0;j<e;j++)
     if(adj[d][j]==1)
     {
	 
      cout << d<<"-------> " <<j<<endl;
     }  
      

  }
}
};

Graph::Graph(int v, int e)
{
	this->v = v;
	this->e = e;
	adj = new int* [v];
	for (int row = 0; row < v; row++) {
		adj[row] = new int[v];
		for (int column = 0; column < v; column++) {
			adj[row][column] = 0;
		}
	}
}

void Graph::addEdge(int start, int e)
{

	adj[start][e] = 1;
	adj[e][start] = 1;
}

void Graph::DFS(int start,bool visited[])
{

 
	cout << start << " ";

	visited[start] = true;

	for (int i = 0; i < v; i++) {

	
		if (adj[start][i] == 1 && (!visited[i])) {
			DFS(i, visited);
		}
	}
}

int main()
{
	int v = 5, e = 4;
	Graph G(v, e);
	G.addEdge(0, 1);
	G.addEdge(0, 4);
	G.addEdge(1, 2);
	G.addEdge(1, 3);
	cout<<"Adjencey output :\n";
	G.printGraph();
	cout<<endl;
	
	cout<<"DFS output \n";
	bool visited[31623] = {false};
	G.DFS(0,visited);
}

