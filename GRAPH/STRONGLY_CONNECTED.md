# Strongly Connected Components

```cpp

//Position this line where user code will be pasted.
class Solution {
  public:
  
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited) {
        // base case
        if(visited[u] == true)
            return;
        
        visited[u] = true;
        
        for(int &v : adj[u]) {
            if(visited[v] == false) {
                dfs(v, adj, visited);
            }
        }
        return;
    }
  
    void topo_sort(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
        // base case
        if(visited[u] == true) return;
        
        visited[u] = true;
        
        for(int &v : adj[u]) {
            if(visited[v] == false) {
                topo_sort(v, adj, visited, st);
            }
        }
        st.push(u);
        return;
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        
        // step 1 --> save topo order in a stack 
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                topo_sort(i, adj, visited, st);
            }
        }
        
        // step 2 --> reverse the edges of the graph
        vector<vector<int>> reverse(V);
        for(int i=0;i<V;i++) {
            for(int &v : adj[i]) {
                reverse[v].push_back(i);
            }
        }
        
        // step 3 --> call dfs traversal in stack order
        visited = vector<bool>(V, false);
        int scc = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(visited[node] == false){
                dfs(node, reverse, visited);
                scc++;
            }
        }
        
        return scc;
    }
};

```