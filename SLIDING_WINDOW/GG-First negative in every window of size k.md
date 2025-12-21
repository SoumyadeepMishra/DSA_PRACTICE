## First negative in every window of size k

```cpp

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        
        // applying sliding window technique
        int i = 0, j = 0;
        deque<int> deq; // store the current negative element
        vector<int> result; // store result
        
        while(j < n){
            if(arr[j] < 0){
                deq.push_back(arr[j]);
            }
            
            // chcecking the window size
            if(j-i+1 == k){
                if(!deq.empty()){
                    result.push_back(deq.front());
                } else{
                    result.push_back(0);
                }
                
                if(arr[i]<0 && !deq.empty()){
                    deq.pop_front();
                }
                i++;
            }
            j++;
        }
        return result;
    }
};

```