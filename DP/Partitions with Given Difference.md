# Partitions with Given Difference

```cpp

class Solution {
  public:
  
    int countSubset(vector<int> &arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        
        // initialization
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=sum;j++) {
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
            for(int j=0;j<=sum;j++) {
                // take it
                if(arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sumTotal = 0;
        for(int i=0;i<n;i++) {
            sumTotal += arr[i];
        }
        
        int target = (diff + sumTotal) / 2;
        
        if((diff + sumTotal)%2 != 0) // if odd no subset possible
            return 0;
        
        return countSubset(arr, target);
    }
};

```