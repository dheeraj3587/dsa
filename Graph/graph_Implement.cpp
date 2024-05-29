#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);
        if (!direction)
        {
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto it : adjList)
        {
            cout << it.first << "-->";
            for (auto num : it.second)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    void bfs(T src, unordered_map<T, bool> &visited)
    {
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T front = q.front();
            q.pop();
            cout << front << " ";

            for (auto it : adjList[front])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (auto it : adjList[src])
        {
            if (!visited[it])
            {
                dfs(it, visited);
            }
        }
    }
};

int main()
{
    Graph<int> g;
    unordered_map<int, bool> visited;

    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(1, 3, false);
    g.addEdge(3, 5, false);
    g.addEdge(3, 7, false);
    g.addEdge(7, 6, false);
    g.addEdge(7, 4, false);

    g.printGraph();

    cout << "BFS: ";
    g.bfs(0, visited);
    cout << endl;
    visited.clear();
    cout << "DFS: ";
    g.dfs(0, visited);

    return 0;
}
