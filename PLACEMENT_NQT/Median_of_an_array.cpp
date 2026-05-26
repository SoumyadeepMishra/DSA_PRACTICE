# include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }

    // i have to find the median of the array
    // step - 1 is to sort the array
    sort(v.begin(), v.end());
    int median_term = -1;

    if(n % 2 != 0) {
        cout << v[(n+1)/2 - 1];
    }

    else {
        median_term = v[n/2] + v[n/2 + 1];
        cout << median_term; 
    }


    return 0;

}