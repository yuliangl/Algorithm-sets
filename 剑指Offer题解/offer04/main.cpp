/******二维数组中的查找******
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
********/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int row = matrix.size();
        int column = matrix[0].size();

        for(int i = 0; i<row; i++){
            for(int j = column - 1; j>=0; j--){
                if(matrix[i][j] == target){
                    cout << "i,j = " << i << "," << j <<endl;
                    return true;
                }
                else if(matrix[i][j] < target)
                    break;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {
            {1,   4,  7, 11, 15},
            {2,   5,  8, 12, 19},
            {3,   6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30},};
    int target = 10;
    Solution test;
    test.findNumberIn2DArray(matrix,target);
}
