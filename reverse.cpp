// Reversing the array

#include <iostream>
#include <vector>
using namespace std;


void print(vector<int> nums){
    for(auto x : nums){
        cout << x << "\t";
    }   cout << endl;
}


void loopSwap(vector<int> &nums){
    for(int start = 0, end = nums.size() - 1; start <= end; start++, end--){
        swap(nums[start], nums[end]);
    }
}


void recursionSwap(int start, int end, vector<int> &nums){
    if(start == end)    return;
    swap(nums[start], nums[end]);
    recursionSwap(start + 1, end - 1, nums);
}


void driver(){

    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "Original Array : ";
    print(nums);
    loopSwap(nums);

    cout << "Array after swapping : ";
    print(nums);

    recursionSwap(0, nums.size() - 1, nums);

    cout << "Array after swapping : ";
    print(nums);
    
}


int main(void){

    driver();

    return 0;    
}