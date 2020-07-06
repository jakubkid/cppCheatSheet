// Program to find Dijkstra's shortest path using 
// priority_queue in STL 
#include<iostream>
#include <list>
#include <vector>
#include <queue>
#include <utility> // std::pair, std::make_pair
#include <climits> // INT_MAX

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
    // Create a priority queue (min heap so minimum distance first) to store nodes
    // that is why greater<intPair> is needed
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/ 
    priority_queue< intPair, vector <intPair> , greater<intPair> > minQueue; 
  
    // Create a vector for distances and initialize all 
    // distances as infinite (INT_MAX) 
    vector<int> dist(numNode, INT_MAX); 
  
    // Insert source itself in priority queue and initialize 
    // its distance as 0. 
    minQueue.push({0, start}); 
    dist[start] = 0; 
  
    /* Looping till priority queue becomes empty (or all 
      distances are not finalized) */
    while (!minQueue.empty()) 
    { 
        // The first node in pair is the minimum distance 
        // node, extract it from priority queue. 
        // node label is stored in second of pair (it 
        // has to be done this way to keep the nodes 
        // sorted distance (distance must be first item 
        // in pair) 
        int minNode = minQueue.top().second; 
        minQueue.pop(); 
  
        for (const intPair& adjNode: adj[minNode])
        { 
            // Get node label and distance of current adjacent 
            // of minNode 
            int node = adjNode.first; 
            int distance = adjNode.second; 
  
            //  If there is shorted path to v through u. 
            if (dist[node] > dist[minNode] + distance) 
            { 
                // Updating distance of v 
                dist[node] = dist[minNode] + distance; 
                minQueue.push({dist[node], node}); 
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