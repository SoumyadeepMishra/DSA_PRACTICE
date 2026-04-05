# Minimum sum partition

# Memoization

```cpp

class Solution {
  public:
  
    int helper(vector<int> &arr, int n, int currSum, int sum, vector<vector<int>> &dp) {
        
        // base case
        if(n == 0)
            return abs(sum - 2*currSum);
        
        if(dp[n][currSum] != -1)
            return dp[n][currSum];
        
        int take = helper(arr, n-1, currSum+arr[n-1], sum, dp);
        int notTake = helper(arr, n-1, currSum, sum, dp);
        
        return dp[n][currSum] = min(take, notTake);
        
    }
  
    int minDifference(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        
        for(int i=0;i<n;i++) {
            sum += arr[i];
        }
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        return helper(arr, n, 0, sum, dp);
    }
};


```