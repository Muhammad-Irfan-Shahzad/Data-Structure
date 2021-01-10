/*
  find shortest spaning tree using kruskal's algorithm
*/
            3           10
       (1)--------(2)---------(3)     
       / \        / \         / \ 
      /  4\      /  3\       /  1\
    4/     \   2/     \    6/     \
    /       \  /       \   /       \ 
   /   5     \/   11    \ /    2    \ 
(0)----------(4)--------(5)---------(6)
   \         / \         /\         /
    \      2/   \       /  \      8/
    6\     /    1\    3/  11\     /
      \   /       \   /      \   /
       \ /    4    \ /    7   \ /
       (7)---------(8)--------(9)
       
       
       #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
 
using namespace std;
 
struct Edge
{
    int src, dest, weight;
};
 
struct Graph
{
        int V, E;
 
        struct Edge* edge;
};
 
 struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
 
    return graph;
}
struct subset
{
        int parent;
        int rank;
};
 
int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*) a;
    struct Edge* b1 = (struct Edge*) b;
    return a1->weight > b1->weight;
}
 
void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0; 
    int i = 0; 
 
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    struct subset *subsets = (struct subset*) malloc(V * sizeof(struct subset));
 
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    while (e < V - 1)
    {
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        
    }
 
    cout<<"The edges in the constructed MST\n";
    for (i = 0; i < e; ++i)
        cout<<result[i].src<<"->"<<result[i].dest<<" = "<<result[i].weight<<endl;
    return;
}
 
int main()
{
   
    int V = 10; 
    int E = 19; 
    struct Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 4;
 
    // add edge 0-4
    graph->edge[1].src = 0;
    graph->edge[1].dest = 4;
    graph->edge[1].weight = 5;
 
    // add edge 0-7
    graph->edge[2].src = 0;
    graph->edge[2].dest = 7;
    graph->edge[2].weight = 6;
 
    // add edge 1-2
    graph->edge[3].src = 1;
    graph->edge[3].dest = 2;
    graph->edge[3].weight = 3;
 
    // add edge 1-4
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 4;
   
    // add edge 2-3
    graph->edge[5].src = 2;
    graph->edge[5].dest = 3;
    graph->edge[5].weight = 10;
    
    // add edge 2-5
    graph->edge[6].src = 2;
    graph->edge[6].dest = 5;
    graph->edge[6].weight = 3;
    
    // add edge 3-6
    graph->edge[7].src = 3;
    graph->edge[7].dest = 6;
    graph->edge[7].weight = 1;
    
	// add edge 4-2
    graph->edge[8].src = 4;
    graph->edge[8].dest = 2;
    graph->edge[8].weight = 2;
  
    // add edge 4-5
    graph->edge[9].src = 4;
    graph->edge[9].dest = 5;
    graph->edge[9].weight = 11;
 
    // add edge 4-7
    graph->edge[10].src = 4;
    graph->edge[10].dest = 7;
    graph->edge[10].weight = 2;
 
    // add edge 4-8
    graph->edge[11].src = 4;
    graph->edge[11].dest = 8;
    graph->edge[11].weight = 1;
  
    // add edge 5-3
    graph->edge[12].src = 5;
    graph->edge[12].dest = 3;
    graph->edge[12].weight = 6;
 
    // add edge 5-6
    graph->edge[13].src = 5;
    graph->edge[13].dest = 6;
    graph->edge[13].weight = 2;
    
    // add edge 5-8
    graph->edge[14].src = 5;
    graph->edge[14].dest = 8;
    graph->edge[14].weight = 3;
    
    // add edge 5-9
    graph->edge[15].src = 5;
    graph->edge[15].dest = 9;
    graph->edge[15].weight = 11;
 
    // add edge 7-8
    graph->edge[16].src = 7;
    graph->edge[16].dest = 8;
    graph->edge[16].weight = 4;
	
	// add edge 8-9
    graph->edge[17].src = 8;
    graph->edge[17].dest = 9;
    graph->edge[17].weight = 7;
	
	// add edge 9-6
    graph->edge[18].src = 9;
    graph->edge[18].dest = 6;
    graph->edge[18].weight = 8;
	
	
	
	KruskalMST(graph);
 
    return 0;
}

