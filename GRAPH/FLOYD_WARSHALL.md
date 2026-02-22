# Floyd Warshall

```cpp

// User function template for C++

class Solution {
  public:
  
    #define INF 1e8
  
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        
        for(int via = 0; via < n; via++) {
         // for every grid value
         for(int i=0;i<n;i++) {
             for(int j=0;j<dist[0].size();j++) {
                 if(dist[i][via] < INF && dist[via][j] < INF)
                   dist[i][j] = min(dist[i][j], dist[i][via]+dist[via][j]);
                 
             }
         }
        }
        
    }
};

```