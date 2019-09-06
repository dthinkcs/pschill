#include <iostream>
#include <stack> // another way of doing dfs
#include <queue> // for bfs
using namespace std;

int** undirectedGraphInputStartsWithOneAdjacencyMatrix(int n, int m); // undirected graph input
void printDFSOneComp(int sv, int** G, int n, int m, bool* visited);
int** directedGraphInputStartsWithOneAdjacencyMatrix(int n, int m); // directed graph input
void printDFS(int** G, int n, int m, int sv);
void printDFSOneComp(int sv, int** G, int n, int m, bool* visited);
void printDFSOneCompSTK(int sv, int** G, int n, int m, bool* visited);
void printDFS_stack(int** G, int n, int m, int sv);

void printBFS(int** G, int n, int m, int sv);
void printBFSOneComp(int sv, int** G, int n, int m, bool* visited);

void spanningTree(int** G, int n, int m, int sv);

int main()
{
   int n;
   cin >> n;
   int m;
   cin >> m;

   // initialize the adjacency matrix
   // int** G = undirectedGraphInputStartsWithOneAdjacencyMatrix(n, m); // n vertices
   int** G = directedGraphInputStartsWithOneAdjacencyMatrix(n, m); // n vertices

   // starting vertex input
   int sv;
   cin >> sv;
   // bool* visited = new bool[n];
   // for (int i = 0; i < n; i++)
   // {
   //  visited[i] = false;
   // }
   // printDFSOneComp(sv, G, n, m, visited);
   // cout << endl;
   cout << "DFS(rec):" << endl;
   printDFS(G, n, m, sv);
   cout << endl;

   cout << "DFS(stack):" << endl;
   printDFS_stack(G, n, m, sv);
   cout << endl;

   cout << "BFS(queue):" << endl;
   printBFS(G, n, m, sv);
   cout << endl;

}

int** undirectedGraphInputStartsWithOneAdjacencyMatrix(int n, int m)
{
  // initialize the adjacency matrix
  int** G = new int*[n]; // n vertices
  for (int i = 0; i < n; i++)
  {
    G[i] = new int[n];
    for (int j = 0; j < n; j++)
     {
       G[i][j] = 0;
     }
  }
  // take input for every edge and there are m no of edges
  for (int i = 0; i < m; i++)
  {
    int f; int s;
    cin >> f >> s;
    G[f - 1][s - 1] = G[s - 1][f - 1] = 1;
  }

  return G;
}


int** directedGraphInputStartsWithOneAdjacencyMatrix(int n, int m)
{
  // initialize the adjacency matrix
  int** G = new int*[n]; // n vertices
  for (int i = 0; i < n; i++)
  {
    G[i] = new int[n];
    for (int j = 0; j < n; j++)
     {
       G[i][j] = 0;
     }
  }
  // take input for every edge and there are m no of edges
  for (int i = 0; i < m; i++)
  {
    int f; int s;
    cin >> f >> s;
    G[f - 1][s - 1] = 1;
  }

  return G;
}

void printDFS(int** G, int n, int m, int sv)
{
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
      printDFSOneComp(i, G, n, m, visited);
  }
}

void printDFS_stack(int** G, int n, int m, int sv)
{
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
      printDFSOneCompSTK(i, G, n, m, visited);
  }
}

void printVertexAddOne(int n)
{
  cout << n + 1 << endl;
}

void printDFSOneComp(int sv, int** G, int n, int m, bool* visited)
{
  visited[sv] = true;
  printVertexAddOne(sv); // ACTIVITY DOING HERE
  for (int i =  0; i < n; i++)
  {
    if (G[sv][i] && !visited[i])
    {
      printDFSOneComp(i, G, n, m, visited);
    }
  }
}

void printDFSOneCompSTK(int sv, int** G, int n, int m, bool* visited)
{
  stack<int> stk;
  stk.push(sv);
  visited[sv] = true;
  while (!stk.empty())
  {
    // u is the top vertex and poppedVertex
    // also print the vertex
    int poppedVertex = stk.top(); stk.pop();

    // print the poppedVertex ACTIVITY DOING HERE
    printVertexAddOne(poppedVertex);

    // push all the neighbours that are unvisited push them in "reverse order" // n - 1 to 0 in adjacency matrix AND // right and left in BinTree
    for (int i = n - 1; i >= 0; i--)
    {
      if (G[poppedVertex][i] && !visited[i])
      {
        stk.push(i); // v gets push AND once you push WAS_BUG visited[i] = false
        visited[i] = true;
      }
    }
  }
}

void printBFS(int** G, int n, int m, int sv)
{
  bool* visited = new bool[n];
  for (int i = 0; i < n; i++)
    visited[i] = false;

  for (int i = 0; i < n; i++)
    if (!visited[i])
      printBFSOneComp(i, G, n, m, visited);
}

void printBFSOneComp(int sv, int ** G, int n, int m, bool* visited)
{

  queue<int> q;
  q.push(sv);
  visited[sv] = true;
  while (!q.empty())
  {
    int frontVertex = q.front(); q.pop();
    printVertexAddOne(frontVertex);

    for (int i = 0; i < n; i++) // u = i wherein you have to check for each vertex
      if (G[frontVertex][i] && !visited[i])
      {
        q.push(i);
        visited[i] = true;
      }
  }
}
