#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<int>>& graph, int node, 
             vector<int>& nodeVis, vector<int>& pathVis, vector<int>& safe) 
    {
        nodeVis[node] = 1;
        pathVis[node] = 1;

        for (int neigh : graph[node]) 
        {
            // If neighbour not visited → DFS
            if (!nodeVis[neigh]) 
            {
                if (dfs(graph, neigh, nodeVis, pathVis, safe)) 
                {
                    safe[node] = 0;
                    return true;
                }
            }

            // If neighbour already in path → cycle
            else if (pathVis[neigh]) 
            {
                safe[node] = 0;
                return true;
            }
        }

        // No cycle from this node
        safe[node] = 1;
        pathVis[node] = 0;

        return false;
    }

    bool dfs2(vector<vector<int>>& graph, int node,
              vector<int>& visited, vector<int>& safe)
    {
        visited[node] = 1;

        for (int x : graph[node])
        {
            // Cycle detected
            if (visited[x] == 1)
            {
                safe[node] = 0;
                return true;
            }

            // DFS call
            else if (visited[x] == 0)
            {
                if (dfs2(graph, x, visited, safe))
                {
                    safe[node] = 0;
                    return true;
                }
            }
        }

        visited[node] = 2;
        safe[node] = 1;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        // ================= METHOD 1 =================
        // TC : O(V+E)
        // SC : O(V)

        // int n = graph.size();

        // vector<int> safe(n, 0);
        // vector<int> nodeVis(n, 0);
        // vector<int> pathVis(n, 0);

        // for (int i = 0; i < n; i++) 
        // {
        //     if (!nodeVis[i]) 
        //     {
        //         dfs(graph, i, nodeVis, pathVis, safe);
        //     }
        // }

        // vector<int> safeNodes;

        // for (int i = 0; i < n; i++) 
        // {
        //     if (safe[i] == 1)
        //         safeNodes.push_back(i);
        // }

        // return safeNodes;



        // ================= METHOD 2 =================
        // TC : O(V+E)
        // SC : O(V)

        // int n = graph.size();

        // vector<int> safe(n, 0);
        // vector<int> visited(n, 0);

        // for (int i = 0; i < n; i++) 
        // {
        //     if (!visited[i]) 
        //     {
        //         dfs2(graph, i, visited, safe);
        //     }
        // }

        // vector<int> safeNodes;

        // for (int i = 0; i < n; i++) 
        // {
        //     if (safe[i] == 1)
        //         safeNodes.push_back(i);
        // }

        // return safeNodes;



        // ================= METHOD 3 : KAHN'S ALGO =================
        // TC : O(V+E)
        // SC : O(V+E)

        int n = graph.size();

        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);

        // Build reverse graph
        for (int u = 0; u < n; u++) 
        {
            for (int v : graph[u]) 
            {
                reverseGraph[v].push_back(u);
                indegree[u]++;
            }
        }

        // Push terminal nodes
        queue<int> q;

        for (int i = 0; i < n; i++) 
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> safeList;

        // BFS
        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();

            safeList.push_back(node);

            for (int parent : reverseGraph[node]) 
            {
                indegree[parent]--;

                if (indegree[parent] == 0) 
                {
                    q.push(parent);
                }
            }
        }

        sort(safeList.begin(), safeList.end());

        return safeList;
    }
};