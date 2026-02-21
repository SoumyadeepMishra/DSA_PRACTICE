# Euler Circuit and Euler Path

```cpp

class Solution {
  public:
  
    void dfs(int u, vector<int> adj[], vector<bool> &visited) {
        // base case
        if(visited[u] == true)
            return;
            
        visited[u] = true;
        for(int &v : adj[u]) {
            if(!visited[v]) {
                dfs(v, adj, visited);
            }
        }
        return;
    }
  
    bool is_connected(int V, vector<int> adj[]) {
        // first find any nonzero degree vertex
        int non_zero_degree_vertex = -1;
        for(int i=0;i<V;i++) {
            if(adj[i].size() > 0) {
                non_zero_degree_vertex = i;
            }
        }
        
        // call dfs from that non zero degree vertex
        vector<bool> visited(V, false);
        dfs(non_zero_degree_vertex, adj, visited);
        
        // check if any nonzerodegree vertex left to visit or not 
        for(int i=0;i<V;i++) {
            if(visited[i] == false && adj[i].size() > 0) {
                return false;
            }
        }
        return true;
    }
  
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        
        // step 1 --> all the nonzero degree vertices are connected or not 
        if(is_connected(V, adj) == false) {
            return 0;
        }
        
        // step 2 --> count number of odd degree vertices
        int odd_count = 0;
        
        for(int i=0;i<V;i++) {
            if(adj[i].size() % 2 != 0) {
                odd_count++;
            }
        }
        
        if(odd_count == 2)
            return 1;
        
        if(odd_count == 0)
            return 2;
            
        if(odd_count > 2)
            return 0;
    }
};

```