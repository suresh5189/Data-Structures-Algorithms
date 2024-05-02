// Given an undirected graph and a number m, the task is to color the given graph with at most m colors such that no two adjacent vertices of the graph are colored with the same color

// Note: Here coloring of a graph means the assignment of colors to all vertices

// Input:  graph = {0, 1, 1, 1},
//                 {1, 0, 1, 0},
//                 {1, 1, 0, 1},
//                 {1, 0, 1, 0}
// Output: Solution Exists:
// Following are the assigned colors: 1  2  3  2

// Input: graph = {1, 1, 1, 1},
//                {1, 1, 1, 1},
//                {1, 1, 1, 1},
//                {1, 1, 1, 1}

// Output: Solution does not exist

// Time Complexity: O( N^M) (n raised to m)
// Space Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, int color[], bool graph[101][101], int m, int n)
{
    if (node == n)
        return true;

    for (int i = 1; i <= n; i++)
    {
        if (isSafe(node, color, graph, n, i))
        {
            color[i] = i;
            if (solve(node + 1, color, graph, n, i))
                return true;
            color[i] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    int color[n] = {0};
    if (solve(0, color, graph, m, n))
        return true;
    return false;
}

int main()
{
    int n;
    cout << "Enter the Vertices of The Graph: ";
    cin >> n;

    bool graph[101][101];

    // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][0] = 1;
    graph[0][3] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;

    int m;
    cout << "Enter the Number of Colors :";
    cin >> m;

    cout << graphColoring(graph, m, n);
}