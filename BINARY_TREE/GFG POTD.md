# Count the nodes at distance k from leaf

code

```cpp

class Solution {
  public:
    vector<vector<Node*>> paths;
    
    void solve(Node* root, vector<Node*> &temp){
        if(root == nullptr) return;
        
        temp.push_back(root);
        // checking for leaf node
        if(root->left == nullptr && root->right == nullptr){
            paths.push_back(temp);
        }
        
        solve(root->left, temp);
        solve(root->right, temp);
        
        temp.pop_back();
    }
    
    int kthFromLeaf(Node* root, int k) {
        // code here.
        vector<Node*> temp;
        solve(root, temp);
        
        unordered_set<Node*> result;
        
        for(vector<Node*> &path : paths){
            int n = path.size();
            if(n > k){
                result.insert(path[n-k-1]);
            }
        }
        
        return result.size();
        
    }
};

```