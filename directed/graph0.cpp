#include <iostream>
using namespace std;
// DIR GRAPH
int** directedGraphInputAdjacencyMatrix(int n, int m);


int main()
{
   int n;
   cin >> n;
   int m;
   cin >> m;


   int** G = directedGraphInputAdjacenyMatrix(n, m);


}

int** directedGraphInputAdjacencyMatrix(int n, int m)
{
  // initialize the adjacency matrix
  int** G = new int*[n]; // n vertices
  for (int i = 0; i < n; i++)
  {
    G[i] = new int[n];
    for (int j = 0; j < n; i++)
     {
       G[i][j] = 0;
     }
  }
  // take input for every edge and there are m no of edges
  for (int i = 0; i < m; i++)
  {
    int f; int s;
    cin >> f >> s;
    G[f][s] = 1;
  }

  return G;
}
