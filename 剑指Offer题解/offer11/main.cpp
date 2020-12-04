/******剑指 Offer 11. 旋转数组的最小数字******
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1.
********/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0;
        int high = numbers.size() - 1;
        int pivot = 0;
        while (low < high) {
            pivot =low + (high - low)/2;// ( low < pivot <= high )
            //when  pivot = (low + high)/2 ( low <= pivot < high )
            if(numbers[pivot] < numbers[high])
                high = pivot;
            else if(numbers[pivot] > numbers[high])
                low = pivot + 1;
            //we must have pivot-variate plus 1 when we use "pivot = (low + high)/2" to prevent endless loop.
            //because low and pivot is same exactly when high is great 1 than low.
            else
                high--;//To prevent specific condition which all numbers are same except the minmax.
        }
        return numbers[low];
    }
};
int main()
{
    return 0;
}
