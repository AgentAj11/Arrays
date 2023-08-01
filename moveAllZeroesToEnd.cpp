// Program to move all zeroes in an array to the end.

#include <iostream>
#include <vector>
using namespace std;


class ZeroMover{
    public: 

        vector<int> nums;

        ZeroMover(vector<int> nums){
            this -> nums = nums;
        }


        void print(vector<int> nums){
            for(auto x : nums){
                cout << x << "\t";
            }   cout << endl;
        }


        void extraSpace(){
            vector<int> temp;
            int zero = 0;

            for(int i = 0; i < nums.size(); i++){
                if(nums[i] != 0){
                    temp.push_back(nums[i]);
                }   else zero++;
            }

            for(int i = 0; i < zero; i++){
                temp.push_back(0);
            }   nums = temp;
        }


        void twoPointer(){
            int nonZeroPtr = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] != 0){
                    nums[nonZeroPtr++] = nums[i];
                }
            }
            while(nonZeroPtr < nums.size()){
                nums[nonZeroPtr++] = 0;
            }
        }


        void deleteZeros(){
            // by STL
            int zeroCount = 0;

            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0){
                    zeroCount++;
                    nums.erase(nums.begin() + i);
                    i--;
                }
            }

            while(zeroCount){
                nums.push_back(0);
                zeroCount--;
            }
        }

        // same as two pointer method but here swapping will be used & their is no need to keep track of zero count(also no need to push the zeroes at the end of array).
        void byPartioning(){
            int j = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] != 0){
                    swap(nums[j++], nums[i]);
                }
            }
        }
};


void zeroDriver(){
    vector<int> arr = {0, 0, 0, 0, 2, 3, 8, 21, 9, 01, 0, 0, -1, 22, 4, 6};

    ZeroMover move(arr);

    cout << "Original Array\n";
    move.print(arr);

    // move.extraSpace();
    // move.twoPointer();
    // move.deleteZeros();
    move.byPartioning();

    cout << "Modified Array\n";
    move.print(move.nums);
}


int main(void){
    zeroDriver();
    return 0;
}