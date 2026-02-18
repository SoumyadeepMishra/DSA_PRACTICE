# Longest Substring Without Repeating Characters

```cpp

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int len = 0;

        // for the index storing
        unordered_map<char, int> mp;

        while(j < n) {
            if(mp.count(s[j])) {
                // index should be updated value
                if(mp[s[j]] >= i) {
                    i = mp[s[j]] + 1;
                    len = max(len, j-i+1);
                }
            }
            mp[s[j]] = j;
            j++;
        }
        return len;
    }
};

```