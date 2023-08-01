// Rotate the array
#include <iostream>
#include <vector>
#include <deque>
using namespace std;


void print(vector<int> nums){
    for(auto x : nums){
        cout << x << "\t";
    }   cout << endl;
}


void reverse(vector<int> &nums, int start, int end){
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}


void oneRotation(vector<int> &nums){
    // right rotation
    int temp = nums[nums.size() - 1];
    for(int i = nums.size() - 1; i > 0; i--){
        nums[i] = nums[i - 1];
    }   nums[0] = temp;
}


void oneByOne(vector<int> &nums, int n){
    // brute force

    for(int j = 0; j < n; j++){
        int temp = nums[nums.size() - 1];
        for(int i = nums.size() - 1; i > 0; i--){
            nums[i] = nums[i - 1];
        }   nums[0] = temp;
    }
}


void byTempArray(vector<int> &nums, int n){

    n %= nums.size();
    int d = nums.size() - n;
    vector<int> temp;

    for(int i = d; i < nums.size(); i++){
        temp.push_back(nums[i]);
    }

    for(int i = 0; i < d; i++){
        temp.push_back(nums[i]);
    }

    nums = temp;
}


deque<int> byDeque(vector<int> &nums, int n){

    deque<int> dq;
    for(auto x : nums){
        dq.push_back(x);
    }

    for(int i = 0; i < (n % nums.size()); i++){
        int temp = dq.back();
        dq.pop_back();
        dq.push_front(temp);
    }

    return dq;
}


void reversalAlgorithm(vector<int> &nums, int n){
    // inconsistent output
    // n %= nums.size();
    // reverse(nums, 0, n - 1);
    // reverse(nums, n, nums.size() - 1);
    // reverse(nums, 0, nums.size() - 1);
    
    n %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, n - 1);
    reverse(nums, n, nums.size() - 1);
}


void driver(){
    vector<int> nums(10, 1);
    
    for(int i = 0; i < nums.size(); i++){
        nums[i] = (i + 1) * 10;
    }

    cout << "Original array :\n";
    print(nums);

    int n;
    cout << "N : ";
    cin >> n;

    // oneByOne(nums, n);
    // byTempArray(nums, n);
    // deque<int> rotatedArray = byDeque(nums, n);
    reversalAlgorithm(nums, n);
    print(nums);
}


int main(void){
    driver();
    return 0;
}
