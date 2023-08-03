// Return an subarray equal to the sum (if any)


// Vector one liner
/*
    return vector<int>(arr.begin(), arr.begin() + i + 1);
*/


#include <iostream>
#include <vector>

using namespace std;

class SubarraySum{
    private:
        vector<int> nums;
        int key;

    public:
        SubarraySum(vector<int> nums, int key){
            this -> nums = nums;
            this -> key = key;
        }

        void print(vector<int> subarray){
            for(auto x : subarray){
                cout << x << "\t";
            }   cout << endl;
        }

        vector<int> createSubarray(int start, int end){
            vector<int> subarray;
            while(start <= end){
                subarray.push_back(nums[start++]);
            }   return subarray;
        }

        vector<int> bySlidingWindow(){
            
            int start = 0;
            int end = 1;
            int n = nums.size();
            int currentSum = nums[0];
            vector<int> subarray(1,-1);

            while(end <= n){
                while(currentSum > key && start < end - 1)
                    currentSum -= nums[start++];

                if(currentSum == key)
                    return createSubarray(start, end - 1);
                
                currentSum += nums[end++];
            }   return subarray;
        }

        vector<int> byNestedLoop(){
            
            int start;
            int end;
            int currentSum;
            // This method can be optimized by adding condition: if(currentSum > key)
            for(start = 0; start < nums.size(); start++){
                currentSum = nums[start];
                if(currentSum == key){
                    return createSubarray(start, start);
                }   else{
                    for(end = start + 1; end < nums.size(); end++){
                        currentSum += nums[end];
                        if(currentSum == key){
                            return createSubarray(start, end);
                        }
                    }
                }
            }
        }

        
};


int main(void){
    
    vector<int> nums = {1, 2, 3, 4, 5, 8, 9, 11, 4, 7, 9};

    cout << "Array : ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << "\t";
    }   cout << endl;

    int key;
    cout << "Key : ";
    cin >> key;

    SubarraySum obj(nums, key);
    vector<int> subarray;

    // subarray = obj.bySlidingWindow();
    subarray = obj.byNestedLoop();

    obj.print(subarray);

    return 0;
}