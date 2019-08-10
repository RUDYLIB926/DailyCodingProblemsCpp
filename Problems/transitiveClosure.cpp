#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

/* 
PROBLEM STATEMENT
The transitive closure of a graph is a measure of which vertices are reachable from other vertices. 
It can be represented as a matrix M, where M[i][j] == 1 if there is a path between vertices i and j, 
and otherwise 0.

For example, suppose we are given the following graph in adjacency list form:

graph = [
    [0, 1, 3],
    [1, 2],
    [2],
    [3]
]
The transitive closure of this graph would be:

[1, 1, 1, 1]
[0, 1, 1, 0]
[0, 0, 1, 0]
[0, 0, 0, 1]
Given a graph, find its transitive closure.

ALGORITHM
steps
1. Find primary edges for all verticies
2. Check tier 1 verticies connections to determine if a path exists to tier 2 connections
3. Check tier 2 connections to determine if a path exists to tier 3.

Primary check
1. start at node 0, mark paths that exist to any nodes.
*/


// Number of vertices in the graph
#define N 4

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
	// An array of vectors to represent adjacency list
	std::vector<int> adjList[N];

	// Constructor
	Graph(std::vector<Edge> const &edges)
	{
		// add edges to the directed graph
		for (int i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			adjList[src].push_back(dest);
		}
	}

    void PrintGraph(){
        std::vector<std::vector<int>> graph = {{0, 1, 3}, {1, 2}, {2}, {3}};
        for (auto row:graph){
            for (int x:row){
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
    }
};

// C is connectivity matrix and stores transitive closure of graph
// root is the topmost node in DFS tree(it is starting vertex of DFS)
// descendant is current vertex to be explored in DFS
// Invariant: A path already exists from root -> descendant in graph
void DFS(Graph const& graph, bool C[N][N], int root, int descendant)
{
	for (int child : graph.adjList[descendant])
	{
		// if child is a adjacent vertex of descendant, we have
		// found a path from root->child
		if (!C[root][child])
		{
			C[root][child] = true;
			DFS(graph, C, root, child);
		}
	}
}

// main function
int main()
{
	// array of graph edges as per above diagram
	std::vector<Edge> edges = {
		{ 0, 2 }, { 1, 0 }, { 3, 1 }
	};
    std::vector<Edge> edges1 = {
		{ 0, 1 }, { 0, 3 }, 
        { 1, 2 }
	};

	// create a graph from edges
	Graph graph(edges1);
    graph.PrintGraph();
	// C is connectivity matrix and stores the transitive closure
	// of the graph. The value of C[i][j] is 1 only if a directed
	// path exists from vertex i to vertex j.
	bool C[N][N];
	std::memset(C, false, sizeof C);

	// consider each vertex and start DFS from it
	for (int v = 0; v < N; v++)
	{
		C[v][v] = true;
		DFS(graph, C, v, v);

		// print path info for vertex v
		for (int u = 0; u < N; u++)
			std::cout << std::left << std::setw(4) << C[v][u];
		std::cout << std::endl;
	}

	return 0;
}
/*
int main(){
    std::vector<std::vector<int>> graph = {{0, 1, 3}, {1, 2}, {2}, {3}};
    // Graph list
    // [ 
    //     [0,1,3],
    //     [1,2],
    //     [2],
    //     [3]
    // ]
    

    for (auto row:graph){
        for (int x: row){
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    std::vector<std::vector<int>> graph1(graph.size());
    for(int graphRow = 0; graphRow < graph.size(); graphRow++){
        std::vector<int> row(graph.size());
        for (int rowIndex = 0; rowIndex < row.size(); rowIndex++){
            for (int listIndex = 0; listIndex < graph[graphRow].size(); listIndex++){
                if (rowIndex == graph[graphRow][listIndex]){
                    row[rowIndex] = 1;
                    break;
                }
                else{
                    row[rowIndex] = 0;
                }
            }
        }
        graph1[graphRow] = row;
   }
   for (auto row:graph1){
        for (int x: row){
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    
    // Graph Matrix
    // [
    //     [1,1,0,1],
    //     [0,1,1,0],
    //     [0,0,1,0],
    //     [0,0,0,1]
    // ]
    
    std::vector<std::vector<int>> output(graph1.size());
    
    for (int graphRow = 0; graphRow < graph1.size(); graphRow++){
        std::vector<int> row = graph1[graphRow];
        for (int rowIndex = 0; rowIndex < row.size(); rowIndex++){
            if (row[rowIndex] != 1){
                
            }
        }
    }
    for (auto row:output){
        for (int x: row){
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    // Connectivity Matrix
    // [
    //     [1,1,1,1],
    //     [0,1,1,0],
    //     [0,0,1,0],
    //     [0,0,0,1]
    // ]

    return 0;
}
*/