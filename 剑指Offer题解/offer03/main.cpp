/******数组中重复的数字******
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，
但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
********/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(size_t i=0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1])
                return nums[i];
        }
        return -1;
    }
};

int main(){

}
