// Wave Sort
// a >= b <= c >= d <= e >= f...

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


class WaveSort{

    private:
    vector<int> nums;

    public:
        WaveSort(vector<int> nums){
            this -> nums = nums;
        }

        void print(vector<int> nums){
            for(auto x : nums){
                cout << x << "\t";
            }   cout << endl;
        }

        vector<int> sortAndSwap(){
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size() - 1; i += 2)
                swap(nums[i], nums[i + 1]);
            return nums;
        }

        vector<int> optimized(){
            int n = nums.size();
            for(int i = 0; i < n; i += 2){
                if(i > 0 and nums[i - 1] > nums[i])
                    swap(nums[i - 1], nums[i]);
                if(i < n - 1 and nums[i] < nums[i + 1])
                    swap(nums[i], nums[i + 1]);
            }   return nums;

            // Extremly gorgious
            // for(int current = 0, previous, next; current < n; current += 2){
            
            // previous = current - 1;
            // if(current > 0 && nums[previous] > nums[current]){
            //     swap(nums[previous], nums[current]);
            // }
            
            // next = current + 1;
            // if((current < n - 1) && nums[next] > nums[current]){
            //     swap(nums[current], nums[next]);
            // }
        }
};


int main(void){

    vector<int> nums;
    // nums = {20, 10, 8, 2, 4, 6};
    nums = {10, 5, 6, 3, 2, 20, 100, 80};
    WaveSort obj(nums);

    cout << "Original Array : ";
    obj.print(nums);

    vector<int> wave;

    // wave = obj.sortAndSwap();
    wave = obj.optimized();

    cout << "Wave Array : ";
    obj.print(wave);

    return 0;
}
