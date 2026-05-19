class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> G(numCourses);   // Adjacency list
        vector<int> degree(numCourses, 0);   // In-degree array
        
        // Build graph
        for (auto &e : prerequisites) {
            G[e[1]].push_back(e[0]);  // edge: e[1] -> e[0]
            degree[e[0]]++;           // increase in-degree
        }
        
        queue<int> q;
        
        // Push nodes with 0 in-degree
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        
        // BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for (int neigh : G[node]) {
                degree[neigh]--;
                if (degree[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        return count == numCourses;
    }
};