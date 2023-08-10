// find leaders in an array
// leader-  arr[i] == leader, if {arr[i+1], arr[i+2] ... arr[n-1]} < arr[i]

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;


void print(vector<int> nums){
    for(auto x : nums){
        cout << x << "\t";
    }   cout << endl;
}


vector<int> bF(vector<int> nums){
    vector<int> leaders;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        bool leader = true;
        for(int j = i + 1; j < n; j++){
            if(nums[i] < nums[j]){
                leader = false;
                break;
            }
        }
        if(leader){
            leaders.push_back(nums[i]);
        }
    }   return leaders;
}


vector<int> suffixMaximum(vector<int> nums){
    int max = INT_MIN;
    vector<int> leaders;

    for(int i = nums.size() - 1; i >= 0; i--){
        if(nums[i] > max){
            max = nums[i];
            leaders.push_back(nums[i]);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}


int main(void){

    vector<int> nums;
    // nums = {16, 17, 4, 3, 5, 2};
    nums = {1, 2, 3, 4, 5, 2};

    cout << "Original Nums = ";
    print(nums);

    vector<int> leaders;
    
    // leaders = bF(nums);
    leaders = suffixMaximum(nums);

    cout << "Leaders : ";
    print(leaders);

    return 0;
}