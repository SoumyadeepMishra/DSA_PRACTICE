# Prims Algorithm

```cpp

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        // first have to make the adjacency list
        unordered_map<int, vector<pair<int, int>> > adj;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // inMST vector
        vector<bool> inMST(V, false);
        int sum = 0;
        
        // min heap
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // {wt, node}
        
        while(!pq.empty()) {
            auto p = pq.top();
            int wt = p.first;
            int node = p.second;
            pq.pop();
            
            // main condition here
            if(inMST[node] == true) {
                continue;
            }
            
            inMST[node] = true;
            sum += wt;
            
            for(auto &ngh : adj[node]) {
                int v = ngh.first;
                int wt = ngh.second;
                
                if(inMST[V] == false) {
                    pq.push({wt, v});
                }
            }
        }
        
        return sum;
        
    }
};

```