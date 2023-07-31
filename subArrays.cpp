// Subsets/Subarrays in an array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void subsetGenerator(vector<int> nums, vector<int> subset, vector<vector<int>> &subsets, int idx){
    if(idx == nums.size()){
        subsets.push_back(subset);
        return;
    }
    // exclude
    subsetGenerator(nums, subset, subsets, idx + 1);
    // include
    subset.push_back(nums[idx]);
    subsetGenerator(nums, subset, subsets, idx + 1);
}


void print(vector<vector<int>> subsets){
    for(auto x: subsets){
        for(auto y: x){
            cout << y << "\t";
        }   cout << endl;
    }
}


void driver(){
    vector<int> nums = {1, 2, 3};
    vector<int> subset;
    vector<vector<int>> subsets;

    cout << "Original Array : ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }   cout << endl;

    subsetGenerator(nums, subset, subsets, 0);
    sort(subsets.begin(), subsets.end());
    print(subsets);
    cout << subsets.size();
}


int main(void){
    driver();
    return 0;
}