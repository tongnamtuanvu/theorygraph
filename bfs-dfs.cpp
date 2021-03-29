#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> adjList;

public:
    Graph()
    {
    }
    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto entry : i.second)
            {
                cout << entry << " , ";
            }
            cout << endl;
        }
    }
    void bfs(T src)
    {
        queue<T> q;
        map<T, bool> visited;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            cout << node << " , ";
            q.pop();
            for (int neighbor : adjList[node])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
    void dfsHelper(T node, map<T, bool> &visited)
    {
        visited[node] = true;
        cout << node << " , ";
        for (T neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfsHelper(neighbor, visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        dfsHelper(src, visited);
        //ThÃ nh pháº§n liÃªn thÃ´ng
        int component = 1;
        cout << endl;
        for (auto i : adjList)
        {
            T element = i.first;
            if (!visited[element])
            {
                dfsHelper(element, visited);
                component++;
            }
        }
        cout << endl;
        cout << "The current graph has " << component << " component";
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    // g.addEdge(1, 5);
    // g.addEdge(1, 7);
    // g.addEdge(5, 7);
    g.print();
    /*
        0 --- 1\
        |     | \7
        |     |  /
        4 --- 5/
    */
    cout << endl;
    cout << "BFS : ";
    g.bfs(0);
    cout << endl;
    cout << "DFS : ";
    /*
         0      3
        / \     |
       /   \    |
       1   2    4
       2 thÃ nh pháº§n liÃªn thÃ´ng
    */
    g.dfs(0);
    return 0;
}
