#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Problem #1 - Two Sum from Leetcode solved with C++
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap;
    for (int i=0; i< nums.size(); i++){
        umap[nums[i]] = i;
    }
    for (int i=0; i< nums.size(); i++){
        int comp = target - nums[i];
        if (umap.count(comp) && umap[comp] != i){
            return {i, umap[comp]};
        };
    }


    /* return nothing if no solution found*/
    return {};
}

int main() {
    /* Testing case 1, where nums = {2,7,11,15} and target = 9*/
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> vec = twoSum(nums, target);

    cout <<"Position of the elements that sum up to " << target << ": " << endl << "[ ";
    
    for (int i=0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}

