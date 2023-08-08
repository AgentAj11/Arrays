/*
    Find the element that appears once in an array where every other element appears twice
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


void print(vector<int> nums){
    for(auto x : nums){
        cout << x << "\t";
    }   cout << endl;
}


int byXOR(vector<int> nums){
    int res = nums[0];
    for(int i = 1; i < nums.size(); i++){
        res ^= nums[i];
    }   return res;
}


int bruteForce(vector<int> nums){
    int n = nums.size();

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(nums[i] == nums[j]){
                count++;
                if(count == 2) break;
            }
        }
        if(count == 1)
            return nums[i];
    }   return 1;
}


int hashing(vector<int> nums){
    map<int, int> freq;
    for(auto x : nums){
        freq[x]++;
    }
    
    for(auto x : freq){
        if(x.second == 1){
            return x.first;
        }
    }   return true;
}


int main(void){
    vector<int> nums = {2, 3, 5, 8, 4, 2, 5, 3, 4};
    cout << "Nums : ";
    print(nums);
    cout << "Number occuring once only = " << hashing(nums);
    

    return 0;
}

