# include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int i = 0;
    int j = n-1;
    while(i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
    cout << "Reversed array: ";
    for(int i=0;i<n;i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}