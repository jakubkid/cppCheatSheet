// Program to find Dijkstra's shortest path in O(N^2)
#include<iostream>
#include <list>
#include <vector>
#include <climits>

using namespace std;

// This class represents a directed graph using
// adjacency list representation

// intPair ==>  Integer Pair 
typedef pair<int, int> intPair; 

class Graph
{
    int numNode;    // No. of Nodes
    
    // In a weighted graph, we need to store Node and weight for every edge
    list< intPair > *adj;

public:
    Graph(int numNode);  // Constructor
    ~Graph(); // Destructor

    // function to add an edge to graph
    void addEdge(int fromNum, int toNum, int weight);
    
    // prints shortest path from start 
    void shortestPath(int start); 
};

Graph::Graph(int numNode)
{
    this->numNode = numNode;
    adj = new list<intPair>[numNode];
}

Graph::~Graph()
{
    delete[] adj;
}

void Graph::addEdge(int fromNum, int toNum, int weight)
{
    // bidirectional graph
    adj[fromNum].push_back({toNum, weight}); // Pre C++11 make_pair(toNum, weight)
    adj[toNum].push_back({fromNum, weight}); 
}

// Prints shortest paths from start to all other nodes 
void Graph::shortestPath(int start) 
{ 
    // Create a vector for distances and initialize all 
    // distances as infinite (INT_MAX) 
    vector<int> dist(numNode, INT_MAX); 
  
    // Create a vector which marks nodes for which we have found a patch and initialize to false
    vector<bool> pathFound(numNode, false); 
  
    // Distance of source node from itself is always 0 
    dist[start] = 0; 
    // Dont initialize yet pathFound[start] = true;
  
    // Find shortest path for all nodes loop until all pathFound are true
    while (true)
    { 
        // Pick the minimum distance node from the set of nodes not 
        // yet processed. u is always equal to start in the first iteration!!
        // THIS IS NOT EFFICIENT and causes O(n^2)
        int minNode = INT_MAX;
        int minDist = INT_MAX;
        for (int i = 0; i < numNode; i++) 
        {
            if (!pathFound[i] && (dist[i] <= minDist)) 
            {
                minDist = dist[i];
                minNode = i;
            }
        }
        if(minNode == INT_MAX)
        {
            break;// all distances are now calculated
        }
        
        // Mark the picked node as processed 
        pathFound[minNode] = true; 
  
        // Update dist value of the adjacent nodes of the picked node. 
        for (const intPair& adjNode: adj[minNode])
        {
            int node = adjNode.first; 
            int distance = adjNode.second; 
            // Update dist[node] only if is not in sptSet, there is an edge from 
            // minNode to node, and total weight of path from src to node through minNode is 
            // smaller than current value of dist[node] 
            if (!pathFound[node] && 
                dist[minNode] + distance < dist[node]) 
            {
                dist[node] = dist[minNode] + distance; 
            }
                
        }
    } 
  
   // Print shortest distances stored in dist[] 
    cout << "Vertex   Distance from Source\n"; 
    for (int i = 0; i < numNode; i++) 
    {
        cout << i <<"\t\t"<< dist[i]<< endl; 
    }
} 
  
// Driver program to test methods of graph class 
int main() 
{ 
    // create the graph given in above fugure 
    int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.shortestPath(0); 
  
    return 0; 
} 