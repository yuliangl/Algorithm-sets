/******剑指 Offer 10- II. 青蛙跳台阶问题******
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
********/
#include <iostream>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        int sum=0, a=1, b=1, ans=0;
        while (n>1) {
            sum = a+b;
            a = b;
            b = sum;
            ans = sum%1000000007;
            n--;
        }
        cout<< ans <<endl;
        return ans;
    }
};

int main()
{
    Solution test;
    test.numWays(20);
    return 0;
}
