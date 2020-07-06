// Program to print BFS traversal from a given
// source vertex. BFS(int start) traverses Nodes(vertices)
// reachable from start.
#include<iostream>
#include <list>
#include <queue>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int numNode;    // No. of Nodes
    // Pointer to an array containing adjacency lists
    list<int> *adj;
public:
    Graph(int numNode);  // Constructor
    ~Graph(); // Destructor

    // function to add an edge to graph
    void addEdge(int fromNum, int toNum);
    void BFS(int start);
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

void Graph::BFS(int start)
{
    // Mark all the nodes (vertices) as not visited  ()<-initializes object to 0
    bool *visited = new bool[numNode]();

    // Create a queue for BFS
    queue<int> nodeToCheck;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    nodeToCheck.push(start);


    while(!nodeToCheck.empty())
    {
        // Dequeue a vertex from queue and print it
        start = nodeToCheck.front();
        cout << start << " ";
        nodeToCheck.pop();

        // Get all adjacent Nodes(vertices) of the dequeued
        // Node(vertex) start. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (const int& nextNode: adj[start])
        {
            if (!visited[nextNode])
            {
                visited[nextNode] = true;
                nodeToCheck.push(nextNode);
            }
        }
    }
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

    cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}