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

# Tabulation(Bottom Up)

```cpp

class Solution {
  public:
  
    void subsetSum(vector<int> &arr, int n, int sum, vector<vector<int>> &dp) {
        
        // initialization
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=sum;j++) {
                
                if(i == 0 && j == 0)
                    dp[i][j] = true;
                    
                else if(i == 0)
                    dp[i][j] = false;
                    
                else if(j == 0)
                    dp[i][j] = true;                
            }
        }
        
        // main condition
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=sum;j++) {
                
                if(arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        
    }
  
    int minDifference(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        
        for(int i=0;i<n;i++) {
            sum += arr[i];
        }
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        subsetSum(arr, n, sum, dp);
        
        vector<int> vec;
        for(int i=0;i<sum+1;i++) {
            if(dp[n][i] == true){
                vec.push_back(i);
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<vec.size();i++) {
            ans = min(ans, abs(sum-2*vec[i]));
        }
        
        return ans;
    }
};


```