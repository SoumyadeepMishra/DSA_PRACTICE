# include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }

    // i have to remove the duplicate form sorted array
    set<int> s;
    for(int i=0;i<n;i++) {
        s.insert(v[i]);
    }

    for(int it : s) {
        cout << it << " ";
    }

    return 0;
}