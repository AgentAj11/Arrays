// Rearrange the given array alternativelyj
/*
    1, 2, 3, 4, 5, 6 => 6, 1, 5, 2, 4, 3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void){

    vector<int> nums = {1, 9, 3, 2, 8, 7, 2, 82, 13, 23};
    
    sort(nums.begin(), nums.end());
    int maxElement = nums[nums.size() - 1] + 1;

    int maxIdx = nums.size() - 1;
    int minIdx = 0;
    
    for(int i = 0; i < nums.size(); i++){
        if(i % 2 == 0){
            nums[i] += nums[maxIdx] % maxElement * maxElement;
            maxIdx--;
        }   else{
            nums[i] += nums[minIdx] % maxElement * maxElement;
            minIdx++;
        }
    }


    cout << "Original array : ";
    for(auto x : nums){
        cout << x % maxElement << "\t";
    }   cout << endl;

    cout << "Modified array : ";
    for(auto x : nums){
        cout << x << "\t";
    }   cout << endl;
    
    cout << "Rearranged array : ";
    for(auto x : nums){
        cout << x / maxElement << "\t";
    }   cout << endl;

    return 0;
}