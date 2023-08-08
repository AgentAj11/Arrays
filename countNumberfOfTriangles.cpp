#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void print(vector<vector<int>> triangles){
    for(auto x : triangles){
        for(auto y : x){
            cout << y << "\t";
        }   cout << endl;
    }
}


int bF(vector<int> nums){
    vector<vector<int>> triangles;
    vector<int> triangle;
    int count = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(nums[i] + nums[j] > nums[k] &&
                nums[j] + nums[k] > nums[i] &&
                nums[i] + nums[k] > nums[j]){
                    count++;
                    triangle.push_back(nums[i]);
                    triangle.push_back(nums[j]);
                    triangle.push_back(nums[k]);
                    triangles.push_back(triangle);
                    triangle.clear();
                }
            }
        }
    }
    print(triangles);
    return count;
}


int doubleNestedLoop(vector<int> nums){
    int count = 0;
    int n = nums.size();
    vector<int> triangle;
    vector<vector<int>> triangles;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-2; i++){
        for(int j = i + 1; j < n; j++){
            int k = j + 1;
            while(k < n && (nums[i] + nums[j] > nums[k])){
                count++;
                triangle.push_back(nums[i]);
                triangle.push_back(nums[j]);
                triangle.push_back(nums[k]);
                triangles.push_back(triangle);
                triangle.clear();
                k++;
            }
        }
    }

    print(triangles);
    return count;
}


// int findNumberOfTriangles(vector<int> arr, int n)
// {
//     // Count of triangles
//     int count = 0;
//     vector<vector<int>> triangles;
//     vector<int> triangle;
 
//     // The three loops select three different values from
//     // array
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
 
//             // The innermost loop checks for the triangle
//             // property
//             for (int k = j + 1; k < n; k++)
 
//                 // Sum of two sides is greater than the
//                 // third
//                 if (arr[i] + arr[j] > arr[k]
//                     && arr[i] + arr[k] > arr[j]
//                     && arr[k] + arr[j] > arr[i]){
//                         count++;
//                         triangle.push_back(arr[i]);
//                         triangle.push_back(arr[j]);
//                         triangle.push_back(arr[k]);
//                         triangles.push_back(triangle);
//                         triangle.clear();
//                     }
//         }
//     }

//     print(triangles);
//     return count;
// }



void driver(){
    vector<int> sides = {3, 5, 4, 2, 5, 6};
    // cout << "Number of triangles = " << findNumberOfTriangles(sides, 6);
    // 
    cout << "Number of triangles = " << bF(sides);
    cout << endl;
    cout << "Number of triangles = " << doubleNestedLoop(sides);

}


int main(void){
    driver();
    return 0;
}