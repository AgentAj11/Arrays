// Random Vector Generator

#include <iostream>
#include <vector>
#include <random>

using namespace std;


vector<int> generateRandomVector(int vectorSize){
    random_device rd;
    mt19937 generator(rd());
    int x = 1;
    int y = 100;
    uniform_int_distribution<int> distribution(x, y);


    vector<int> nums(vectorSize, 1);
    for(int i = 0; i < nums.size(); i++){
        nums[i] = distribution(generator);
    }   return nums;
}


int main(void){

    int n;
    cout << "N : ";
    cin >> n;

    vector<int> randomVector = generateRandomVector(n);

    cout << "Randomly Generated Vector ";
    for(auto x : randomVector){
        cout << x << "\t";
    }   cout << endl;

    return 0;
}