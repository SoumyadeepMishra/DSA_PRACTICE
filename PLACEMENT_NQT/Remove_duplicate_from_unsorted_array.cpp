#include<bits/stdc++.h> 
using namespace std;
int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }

    
    unordered_set<int> s;
    for(int &num : v) {
        if(s.find(num) == s.end()) {
            cout << num << " ";
            s.insert(num);
        }
    }

    /* for(int &num : ans) {
        cout << num << " ";
    } */

    return 0;
}