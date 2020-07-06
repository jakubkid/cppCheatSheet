// Program to print DFS traversal from a given
// source vertex. DFS(int start) traverses Nodes(vertices)
// reachable from start.
#include<iostream>
#include <list>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int numNode;    // No. of Nodes
    // Pointer to an array containing adjacency lists
    list<int> *adj;
    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int numNode);  // Constructor
    ~Graph(); // Destructor

    // function to add an edge to graph
    void addEdge(int fromNum, int toNum);
    // DFS traversal of the Nodes (vertices )
    // reachable from start
    void DFS(int start);
};

Graph::Graph(int numNode)
{
    this->numNode = numNode;
    adj = new list<int>[numNode];
}

Graph::~Graph()
{
    delete[] adj;
}

void Graph::addEdge(int fromNum, int toNum)
{
    adj[fromNum].push_back(toNum); // Add w to v’s list.
}

void Graph::DFSUtil(int start, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[start] = true;
    cout << start << " ";

    // Recur for all the nodes(vertices) adjacent
    // to this node(vertex)
    list<int>::iterator i;
    for (const int& nextNode: adj[start])
    {
        if (!visited[nextNode])
        {
            DFSUtil(nextNode, visited);
        }
    }
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int start)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[numNode]();

    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(start, visited);
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 

    return 0;
}