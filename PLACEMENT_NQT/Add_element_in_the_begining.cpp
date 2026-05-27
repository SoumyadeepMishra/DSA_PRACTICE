#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int element = 5;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }

    // to insert in the begining we need to shift all the elements to the right by one position
    for(int i=n ; i>0; i--) {
        v[i] = v[i-1];
    }
    v[0] = element;
    for(int i=0;i<=n;i++) {
        cout << v[i] << " ";
    }


    return 0;
}