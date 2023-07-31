// Program to segregate Odd and Even in a given list of numbers
// T(n) = O(n)
// S(n) = O(1)

#include <iostream>
#include <random>
using namespace std;


void segregate(vector<int> &nums){
    // two pointer technique
    int evenPtr = 0;
    int oddPtr = nums.size() - 1;

    while(evenPtr < oddPtr){
        if(nums[evenPtr] % 2 == 0 && nums[oddPtr] % 2 == 1){
            evenPtr++;
            oddPtr--;
        }   else if(nums[evenPtr] % 2 == 1 && nums[oddPtr] % 2 == 0){
            swap(nums[evenPtr], nums[oddPtr]);
            evenPtr++;
            oddPtr--;
        }   else if(nums[evenPtr] % 2 == 0 && nums[oddPtr] % 2 == 0){
            evenPtr++;
        }   else{
            oddPtr--;
        }
    }
}


void print(vector<int> nums){
    for(auto x : nums){
        cout << x << "\t";
    }   cout << endl;
}


void driver(){

    random_device rd;
    mt19937 generator(rd());
    int x = 1;
    int y = 100;
    uniform_int_distribution<int> distribution(x, y);
    
    int n;
    cout << "N : ";
    cin >> n;
    vector<int> nums(n, 1);
    for(int i = 0; i < nums.size(); i++){
        nums[i] = distribution(generator);
    }

    cout << "Original Array\n";
    print(nums);
    segregate(nums);
    cout << "Segregated Array\n";
    print(nums);
}


int main(void){
    driver();
    return 0;
}
