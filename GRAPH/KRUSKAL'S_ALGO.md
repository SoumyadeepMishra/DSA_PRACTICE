# Kruskal's Algorithm

```cpp

class Solution {
  public:
  
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        // base case
        if(x == parent[x]) 
            return x;
            
        return parent[x] = find(parent[x]);
    }
    
    void union_rank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent)
            return;
            
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if(rank[y_parent] >  rank[x_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
  
    int kruskal_algorithm(vector<vector<int>> &edges) {
        int sum = 0;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            // find parents
            int parent_u = find(u);
            int parent_v = find(v);
            
            if(parent_u != parent_v) {
                union_rank(u, v);
                sum += wt;
            }
            
        }
        return sum;
    }
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rank.resize(V, 0);
        // now initialize the parent array
        for(int i=0;i<V;i++) {
            parent[i] = i;
        }
        
        // lets solve it using kruskal's algorithm 
        auto lambda = [&](vector<int>v1, vector<int>v2){
            return v1[2] < v2[2];        
        };
        
        // 1. sort the vector on the basis of weight
        sort(edges.begin(), edges.end(), lambda);
        
        return kruskal_algorithm(edges);
    }
};

```