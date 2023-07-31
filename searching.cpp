// Searching Algorithms
// 1. Linear search
// 2. Binary search
// 3. Built-in binary search function


#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;


void print(vector<int> nums){
    for(auto x : nums){
        cout << x << "\t";
    }   cout << endl;
}


int linearSearch(vector<int> nums, int key){
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == key)
            return i;
    }   return -1;
}


int binarySearch(vector<int> nums, int key){
    int start = 0;
    int end = nums.size() - 1;
    int mid;

    while(start <= end){
        mid = (start + end) / 2;
        if(nums[mid] == key)
            return mid;
        else if(nums[mid] > key){
            end = mid - 1;
        }   else{
            start = mid + 1;
        }
    }   return -1;
}


void driver(){

    // generating random number

    random_device rd;
    mt19937 generator(rd());
    int x = 1;
    int y = 100;
    uniform_int_distribution<int> distribution(x, y);


    vector<int> nums(10, 1);
    for(int i = 0; i < nums.size(); i++){
        nums[i] = distribution(generator);
    }

    sort(nums.begin(), nums.end());
    print(nums);

    int key;
    cout << "Key : ";
    cin >> key;
    int idx;

    // idx = linearSearch(nums, key);
    // if(idx == -1){
    //     cout << key << " not found!\n";
    // }   else{
    //     cout << key << " found at index " << idx << endl;
    // }

    // idx = binarySearch(nums, key);
    // if(idx == -1){
    //     cout << key << " not found!\n";
    // }   else{
    //     cout << key << " found at index " << idx << endl;
    // }

    // by built-in function
    if(binary_search(nums.begin(), nums.end(), key)){
        cout << key << " is present in : ";
        print(nums);
    }   else{
        cout << key << " not present in : ";
        print(nums);
    }
}


int main(void){
    driver();
    return 0;
}