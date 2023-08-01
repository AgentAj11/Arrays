#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    
    //
    void shift(vector<int>& nums,int i){
        for(int j=i; j<nums.size()-1; j++){
            nums[j] = nums[j+1];
        }
    }
    
    
    void moveZeroes(vector<int>& nums) {
        //
        int counter = 0;
        
        for(int i=0; i<nums.size()-1;) {
            if(nums[i] == 0){
                shift(nums,i);
                counter++;
            }
            else i++;
        }
        
        int size = nums.size() - counter;
        for(int i=size; i<nums.size(); i++){
            nums[i] = 0;
        }
        
    }
};


int main(void){
    cout<<"Namaste world\n";
    Solution obj;
    vector<int> nums{0,0};
    obj.moveZeroes(nums);
    for(auto i:nums)
        cout<<i<<"\t";
        cout<<endl;
    return 0;
}