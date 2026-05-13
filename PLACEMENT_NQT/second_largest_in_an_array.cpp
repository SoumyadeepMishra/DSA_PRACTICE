# include<bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    cin >> n;

    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i=0;i<n;i++) {

        if(nums[i] > largest) {
            secondLargest = largest;
            largest = nums[i];
        }
        else if(nums[i] > secondLargest && nums[i] != largest) {
            secondLargest = nums[i];
        }

    }

    cout<< "second largest : " << secondLargest << endl;   
    return 0;
}