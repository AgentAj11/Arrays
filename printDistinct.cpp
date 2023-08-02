// Print Distinct Array Elements

#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <map>
#include <limits.h>
using namespace std;


vector<int> generateRandomVector(int vectorSize){
    random_device rd;
    mt19937 generator(rd());
    int x = 1;
    int y = 100;
    uniform_int_distribution<int> distribution(x, y);

    vector<int> nums(vectorSize, 10);

    for(int i = 0; i < nums.size(); i++){
        nums[i] = distribution(generator);
    }   return nums;
}


class PrintDistinct{
    private:
        vector<int> nums;

    public:

        PrintDistinct(vector<int> nums){
            this -> nums = nums;
        }


        void byNestedLoop(){
            // Very interesting code. Pay attention.
            for(int i = 0; i < nums.size(); i++){
                int j;
                for(j = 0; j < i; j++){
                    if(nums[i] == nums[j]){
                        break;
                    }
                }
                if(i == j){
                    cout << nums[i] << "\t";
                }
            }
        }

        vector<int> bySet(){
            vector<int> distinctNums;
            set<int> s(nums.begin(), nums.end());
            for(auto x : s){
                distinctNums.push_back(x);
            }   return distinctNums;
        }

        vector<int> byFrequencyCount(){

            /*
                Map can solve this problem more effictively.
                If their is any negative number in array, counting frequency by array will only make it more complex and memory inefficient.
            */
            // int max = INT_MIN;
            // for(int i = 0; i < nums.size(); i++){
            //     if(nums[i] > max){
            //         max = nums[i];
            //     }
            // }

            // int freq[max + 1] = {0};
            // // update frequency
            // for(int i = 0; i < nums.size(); i++){
            //     freq[nums[i]]++;
            // }

            // vector<int> distinct;
            // for(int i = 0; i < max + 1; i++){
            //     if(freq[i] != 0){
            //         distinct.push_back(i);
            //     }
            // }   return distinct;


            // Using map
            map<int,int> freq;
            for(auto x : nums){
                freq[x]++;
            }

            vector<int> distinct;
            for(auto x : freq){
                distinct.push_back(x.first);
            }   return distinct;
        }

        void print(vector<int> arr){
            for(auto x : arr){
                cout << x << "\t";
            }   cout << endl;
        }
};


void driver(){
    vector<int> nums = {4, 5, 0, 8, -2, 7, 9, 1, 4, 5, 0, 2, 1};
    PrintDistinct obj(nums);
    vector<int> distinctNums;
    
    cout << "Original Array : ";
    obj.print(nums);

    // obj.byNestedLoop();
    // distinctNums = obj.bySet();
    // distinctNums = obj.byFrequencyCount();

    cout << "Distinct Numbers : ";
    obj.print(distinctNums);
}


int main(void){
    driver();
    return 0;
}
