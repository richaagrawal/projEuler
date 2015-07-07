#include "probs.h"
#include <list>
#include <stack>
using namespace std;

// Class to represent a graph
class Graph
{
	int V;    // No. of vertices'

	// Pointer to an array containing adjacency list
	list<int> *adj;

	// A function used by topologicalSort
	void topologicalSortUtil(int v);

	// Stack 
	stack<int> Stack;

public:
	Graph(int V);   // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of the complete graph
	void topologicalSort();

	// Maintains the integer values seen
	bool *present;
	bool *visited;
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];

	// Mark all the vertices as not visited and
	// check if vertices are present
	visited = new bool[V]; 
	present = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		present[i] = false;
	}
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list
	present[v] = true;
	present[w] = true;
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v)
{
	// Mark the current node as visited.
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i);

	// Push current vertex to stack which stores result
	Stack.push(v);
}

// The function to do Topological Sort. It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{


	// Call the recursive helper function to store Topological Sort
	// starting from all vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i);

	// Print contents of stack
	int top;
	while (Stack.empty() == false)
	{
		top = Stack.top();
		// To check if the number is not present in the passcode
		if (present[top])
			cout << top << "";
		Stack.pop();
	}
}
void prob79()
{
	Graph g(10);

	ifstream file("txtFiles/p079_keylog.txt");
	bool isOpen = file.is_open();

	string line;
	int ctr = 0;
	int v;
	while (getline(file, line))
	{
		stringstream linestream(line);
		linestream >> v;
		// create Graph
		int d1, d2, d3;
		d1 = v / 100;
		d2 = v / 10 % 10;
		d3 = v % 100 % 10;
		g.addEdge(d1, d2);
		g.addEdge(d2, d3);
	}

	cout << "Passcode: " << endl;
	g.topologicalSort();
}