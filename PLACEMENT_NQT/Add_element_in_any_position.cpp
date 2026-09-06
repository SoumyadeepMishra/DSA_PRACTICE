#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    int position;
    cin >> position;
    int element;
    cin >> element;

    v.insert(v.begin()+position-1, element);
    for(int i=0;i<=n;i++) {
        cout << v[i] << " ";
    }
}