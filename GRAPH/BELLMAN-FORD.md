# Bellman Ford algorithm

```cpp

// User function Template for C++

class Solution {
  public:
  
   #define infinity 1e8
  
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, infinity);
        dist[src] = 0;
        
        for(int i=1;i<=V-1;i++) {
            for(auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u] != infinity) {
                    if(dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }
        
        // one more time to check negative cycle 
        for(auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u] != infinity) {
                    if(dist[u] + wt < dist[v]) {
                        return {-1};
                    }
                }
            }
            
            return dist;
    }
};


```