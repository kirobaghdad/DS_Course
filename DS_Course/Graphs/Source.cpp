// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <iostream>
using namespace std;
#include <limits.h>
#include "../LinkedQueue/LinkedQueue.h"
#include <list>
// Number of vertices in the graph
#define V 5


//Edge Class
class Edge {
private:
    int start;
    int end;
    int cost;

public:
    //Default Constructor
    Edge() {
        start = 0;
        end = 0;
        cost = 0;
    }

    Edge(int s, int e, int c) {
        setEdge(s, e, c);
    }

    //Setters
    void setCost(int c) {
        if (c > 0)
            cost = c;
        else cost = -1;
    }

    void setStart(int s) {
        if (s >= 0)
            start = s;
        else start = -1;
    }

    void setEnd(int e) {
        if (e >= 0)
            end = e;
        else end = -1;
    }

    void setEdge(int s, int e, int c) {
        setStart(s);
        setEnd(e);
        setCost(c);
    }

    //Getters
    int getStart()const {
        return start;
    }

    int getEnd()const {
        return end;
    }

    int getCost()const {
        return cost;
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// MINIMUM SPANNING TREE ALGORITHMS /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

//Nearest Neighbor Alogrithm (Approximation)
bool exist(int* arr, int j) {
    for (int i = 0; i < V; i++) {
        if (arr[i] == j)
            return true;
    }
    return false;
}

void nearestNeighbor(int graph[V][V], int src)
{
    int initialSrc = src;
    int min;
    int minIndex;
    int count;
    int visited[V];

    for (int i = 0; i < V; i++)
        visited[i] = -1;

    int distanceCovered = 0;

    for (count = 0; count < V - 1; count++) {
        visited[count] = src;
        min = INT_MAX;

        cout << src << endl;
        //Problem when src does not flow in linear fashion
        //Probably the solution is to use while loop
        for (int i = 0; i < V; i++) {
            if (graph[src][i] <= min && !exist(visited, i))
                min = graph[src][i], minIndex = i;
        }
        distanceCovered += graph[src][minIndex];
        src = minIndex;
    }
    
    visited[count] = src;
    distanceCovered += graph[src][initialSrc];
    cout << "The total covered distance is " << distanceCovered;
}


//Kruskal Algorithm (Exact)

int countEdges(int graph[V][V]) {
    int edgesNum = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != INT_MAX)
                edgesNum++;
        }
    }

    return edgesNum;
}

int getEdgesFromGraph(int graph[V][V], Edge*& edges ) {
    edges = new Edge[V * V];
    int edgesNum = 0;
    int count = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != INT_MAX) {
                edges[count++].setEdge(i, j, graph[i][j]);
                edgesNum++;
            }
        }
    }
    return edgesNum;
}

void sortEdges(Edge*& edges) {
    int i;
    bool swapped;
    //Bubble Sort
    do
    {
        swapped = false;
        i = 1;
        while (edges[i].getCost() != 0) {
            if (edges[i - 1].getCost() > edges[i].getCost()) {
                swap(edges[i - 1], edges[i]);
                swapped = true;
            }
            i++;
        }
    } while (swapped);

}
bool hasCycle(int graph[V][V], int src = 0){

    for (int i = 0; i < V; i++) {
        hasCycle(graph, i);
    }
    return true;
}

void kruskal(int graph[V][V]) {
    Edge* edges; 
    int i = 0;
    int edgesNum;

    edgesNum = getEdgesFromGraph(graph, edges);
    sortEdges(edges);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = i != j ? INT_MAX : 0;
        }
    }

    for (int i = 0; i < edgesNum; i++) {

        graph[edges[i].getStart()][edges[i].getEnd()] = edges[i].getCost();
        graph[edges[i].getEnd()][edges[i].getStart()] = edges[i].getCost();

        if (hasCycle(graph)) {
            graph[edges[i].getStart()][edges[i].getEnd()] = INT_MAX;
            graph[edges[i].getEnd()][edges[i].getStart()] = INT_MAX;
        }
    }

}

  ///////////////////////////////////////////////////////////////////////////////////////////////////
 //////////////////////////////// SHORTEST-PATH PROBLEM ALGORITHMS /////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
               && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

// driver program to test above function
int main()
{

    /* Let us create the example graph discussed above */
   /* int graph[V][V] = { { 0, 4 , 0, 0 , 0 , 0 , 0 , 8 , 0 },
                        { 4, 0 , 8, 0 , 0 , 0 , 0 , 11, 0 },
                        { 0, 8 , 0, 7 , 0 , 4 , 0 , 0 , 2 },
                        { 0, 0 , 7, 0 , 9 , 14, 0 , 0 , 0 },
                        { 0, 0 , 0, 9 , 0 , 10, 0 , 0 , 0 },
                        { 0, 0 , 4, 14, 10, 0 , 2 , 0 , 0 },
                        { 0, 0 , 0, 0 , 0 , 2 , 0 , 1 , 6 },
                        { 8, 11, 0, 0 , 0 , 0 , 1 , 0 , 7 },
                        { 0, 0 , 2, 0 , 0 , 0 , 6 , 7 , 0 } };*/

    //dijkstra(graph, 0);
    int graph[V][V] = { {0      , 4      , 10, 3      , INT_MAX},
                        {4      , 0      , 5 , INT_MAX, INT_MAX},
                        {10     , 5      , 0 , 8      , 6      }, 
                        {3      , INT_MAX, 8 , 0      , 2      },
                        {INT_MAX, INT_MAX, 6 , 2      , 0      }  };

    //nearestNeighbor(graph, 0);

    kruskal(graph);
    return 0;
}