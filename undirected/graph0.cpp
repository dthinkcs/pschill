#include <iostream>
using namespace std;
// UNDIRECTED GRAPH
int main()
{
   int n;
   cin >> n;
   int m;
   cin >> m;

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
   // UNDIRECTED GRAPH input
   for (int i = 0; i < m; i++)
   {
     int f; int s;
     cin >> f >> s;
     G[f][s] = G[s][f] = 1;
   }
}
