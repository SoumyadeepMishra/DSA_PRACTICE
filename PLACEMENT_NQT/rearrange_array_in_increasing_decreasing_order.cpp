# include<bits/stdc++.h>
using namespace std;

void rearrange(vector<int> &nums, int n) {
    sort(nums.begin(), nums.end());

    // reverse the second half of the array
    reverse(nums.begin() + n / 2, nums.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);   
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    rearrange(nums, n);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}