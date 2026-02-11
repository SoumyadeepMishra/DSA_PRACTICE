# Shortest Path in an Undirected Graph

```cpp

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // first make the adjacency list
        unordered_map<int, vector<pair<int, int>> > adj;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> result(n+1, INT_MAX); // to store total distance from source to every node
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que; // min heap
        
        que.push({0, 1}); // 1 is the source node
        result[1] = 0;
        
        // need to have a parent vector to track the parents
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
        }
        
        // main dijkstra logic
        while(!que.empty()) {
            int d = que.top().first;
            int node = que.top().second;
            que.pop();
            
            for(auto &neighbours : adj[node]) {
                int v = neighbours.first;
                int wt = neighbours.second;
                
                // cocndition for updation
                if(d+wt < result[v]) {
                    result[v] = d+wt;
                    que.push({d+wt, v});
                    parent[v] = node;
                }
            }
        }
        
        // now work for determining the path 
        vector<int> path;
        int dest_node = n; // given in question
        
        while(parent[dest_node] != dest_node) {
            path.push_back(dest_node);
            dest_node = parent[dest_node];
        }
        // still parent[node]==node; that node is not pushed which is 1
        path.push_back(1);
        reverse(path.begin(), path.end()); // this is the path
        
        // if no path then there will be infinity
        if(result[n] == INT_MAX) return {-1};
        
        vector<int> ans;
        
        ans.push_back(result[n]);
        
        // then push the whole path in the result;
        for(int &p : path) {
            ans.push_back(p);
        }
        
        return ans;
        
    }
};

```