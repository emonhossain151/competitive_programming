#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector <int> graph[N];
bool visited[N];
int level[N];

// void dfs(int u)
// {
//     // cout << "visiting " << u << " node" << endl;
//     visited[u] = true;
//     for(int v : graph[u])
//     {
//         if(visited[v]) continue;
//         dfs(v);
//     }
// }

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << "visiting node " << u << endl;
        for(int v : graph[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    bfs(1);
    return 0;
}