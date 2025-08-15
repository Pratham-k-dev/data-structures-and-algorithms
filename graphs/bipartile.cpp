/*


bipartite graph: A bipartite graph is a graph whose vertex set can be split into two disjoint groups such that:

No two vertices within the same group are connected by an edge.


----------------------------------------------------------------------------------------------------------------

>> You can color every vertex with one of two colors so that every edge connects different colors.

>> Graph contains no odd-length cycles (this is a key property — odd cycles make bipartiteness impossible).
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    { // Using BFS
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> level(n);
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            queue<int> q;
            q.push(i);
            level[i] = 0; // store levels respect to to the starting node

            visited[i] = 1;
            int l = 1;
            while (!q.empty())
            {
                int s = q.size();
                while (s--)
                {
                    int cur = q.front();

                    q.pop();

                    for (int &j : graph[cur])
                    {
                        if (!visited[j])
                        {
                            q.push(j);
                            visited[j] = 1;
                            level[j] = l;
                        }
                        else if (level[j] != l - 2 && level[j] != l)
                        { // if its not a parant and cycle doesnt meet at same level its an odd numbered cycle

                            return false;
                        }
                    }
                }
                l++;
            }
        }

        return true;
    }



      bool DFS(int cur,int l,vector<vector<int>>& graph,vector<int> &visited,vector<int> &level){ //DFS
        visited[cur]=1;
        level[cur]=l;
        for(int j: graph[cur]){
            if(!visited[j]&&  !DFS(j,l+1,graph,visited,level)) return false;
            else if(level[j]!=l && (l-level[j]+1)&1)return false;
        }
        return true;
    }

    bool isBipartite2(vector<vector<int>> &graph) //using DFS
    {
        
            int n = graph.size();
            vector<int> visited(n, 0);
            vector<int> level(n);

            for (int i = 0; i < n; i++)
            {
                if (visited[i])
                    continue;

                if (!DFS(i, 0, graph, visited, level))
                    return false;
            }

            return true;
        
    }
};

int main()
{
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    Solution o;
    o.isBipartite(graph);

    return 0;
}