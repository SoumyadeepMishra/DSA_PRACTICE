#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    int element = 5;

    v[n] = element; // to insert in the end we can directly assign the value to the last index
    for(int i=0;i<=n;i++) {
        cout << v[i] << " ";
    }

    return 0;
}