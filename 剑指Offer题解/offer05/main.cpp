/******替换空格******
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
********/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int space = s.find(" ");
        while(space != -1){
            s = s.replace(space, 1, "%20");
            space = s.find(" ");
        }
        cout << s << endl;
        return s;
    }
};

int main(){
    string test = " I like english";
    Solution ans;
    ans.replaceSpace(test);
}
