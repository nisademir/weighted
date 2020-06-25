#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <limits>
using namespace std;
#define unvisited 0
#define visited 1

class Graph {
private:
    int numVertex, numEdge;
    int** matrix;
    int* mark; //array of nodes
    int* prev; //array of previous node from source

public:
    //Below there are the functions for the Graph class
    //Constructor
    Graph(int n) {
        numVertex = n; //number of nodes
        numEdge = 0; //number of edges
        //initialize the pointers that will be used in shortest path algorithm
        prev = new int[numVertex];
        //initialize the mark array
        mark = new int[numVertex];
        for (int i = 0; i < numVertex; i++) {
            mark[i] = 0; //initialize all nodes as unvisited
        };
        matrix = new int* [numVertex];
        //create a 2D array for the graph
        for (int i = 0; i < numVertex; i++)
            matrix[i] = new int[numVertex];
        for (int i = 0; i < numVertex; i++)
            for (int j = 0; j < numVertex; j++) {
                matrix[i][j] = 0;
            };
    };
    //Destructor
    Graph() {
        delete[] mark;
        for (int i = 0; i < numVertex; i++)
            delete[] matrix[i];
        delete[] matrix;
        delete[] prev;

    };

    int first(int v) {
        for (int i = 0; i < numVertex; i++)
            if (matrix[v][i] != 0) return i;
        return numVertex; //Return n if none
    };
    //Return v's next neighbour after w
    int next(int v, int w) {
        for (int i = w + 1; i < numVertex; i++)
            if (matrix[v][i] != 0) return i;
        return numVertex; //Return n if none
    };
    //Set edge to "wt"
    void setEdge(int v1, int v2, int wt) {
        if (wt < 0)
            cout << "There is an error. Illegal weight value.\n";
        assert(wt > 0);
        if (matrix[v1][v2] == 0)
            numEdge++; matrix[v1][v2] = wt;
    };
    //Return the weight of (v1,v2)
    int weight(int v1, int v2) {
        return matrix[v1][v2];
    };
    //Set node as visited/unvisited
    void setMark(int v, int val) {
        mark[v] = val;
    };
    //return if all nodes are visited
    bool allVisited() {
        int a = 1;
        for (int i = 0; i < numVertex; i++) {
            if (mark[i] == unvisited)
                a = 0;
        }
        return a;
    };
    /*For the shortest path,
        Dijkstra's algorithm is used */
    void shortestPath(int src, int* dist) {
        for (int i = 0; i < numVertex; i++) {
            dist[i] = 10000;
        };
        for (int i = 0; i < numVertex; i++) {
            prev[i] = 0;
        };
        dist[src] = 0; //distance from source to itself
        int condition = allVisited();
        //continue operation until all nodes are visited
        while (!condition) {
            //find the first unvisited node
            int u = 0;
            for (int i = 0; i < numVertex; i++) {
                if (mark[i] == unvisited)
                    u = i;
            };
            //find the unvisited node with the min distance value
            for (int i = 0; i < numVertex; i++) {
                if (dist[u] > dist[i] && mark[i] == unvisited)
                    u = i;
            }
            setMark(u, visited); //mark the node as visited
            if (dist[u] == 10000)
                break; //if distance is infinity then break
            for (int v = first(u); v < numVertex; v = next(u, v)) {
                int alt = dist[u] + weight(u, v);
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                };
            };
            condition = allVisited();
        };
        cout << "Node\t";
        cout << "Previous Node,Distance\n";
        for (int i = 0; i < numVertex; i++) {
            cout << i;
            cout << "\t";
            cout << "\t";
            cout << prev[i];
            cout << ",";
            cout << dist[i];
            cout << "\n";
        };

    };
};
