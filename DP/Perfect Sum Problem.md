# Perfect Sum Problem

```cpp

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (target + 1));
        
        // initialization
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=target;j++) {
                
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                    
                else if(i == 0)
                    dp[i][j] = 0;
                    
                else if(j == 0)
                    dp[i][j] = 1;
                
            }
        }
        
        // main condition
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=target;j++) { // int --> j = 0
                                        // boolean --> j = 1
                
                if(arr[i-1] == 0) {
                    // take it or not take it 
                    // both cases are same
                    dp[i][j] = 2 * dp[i-1][j];
                }
                
                else if(arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        
        return dp[n][target];
    }
};

```