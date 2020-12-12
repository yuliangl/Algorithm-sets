/******剑指 Offer 12. 矩阵中的路径******
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
路径不能再次进入这个格子。
********/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findpath(const vector<vector<char>>& board, const string& word, vector<bool>& visited, size_t row, size_t column, string::iterator& itr)
    {
        if (itr == word.end())  //到达字符末尾，匹配成功
            return true;
        if (row < 0 || row >= board.size() || column < 0 || column >= board[0].size())  //如果坐标不在矩阵范围内
            return false;  //返回false
        bool haspath = false;  //标记子节点是否含有下一个字符
        int columns = board[0].size();  //矩阵的列数
            //cout << row << " " << column << " " << *itr << endl;	//大家可以使用cout来查看每一步访问节点的位置，便于理解
        if (!visited[row * columns + column] && board[row][column] == *itr)  //当前位置未被访问，且当前位置可以和字符串匹配上
        {

            ++itr;  //迭代器后移一个字符
            visited[row * columns + column] = true;  //标记为以访问，防止该节点的子节点再将该节点加入其子节点
            haspath = findpath(board, word, visited, row, column - 1, itr)  //左边是否有路径
                || findpath(board, word, visited, row, column + 1, itr)   //右边是否有路径
                || findpath(board, word, visited, row - 1, column, itr)   //上边是否有路径
                || findpath(board, word, visited, row + 1, column, itr);  //下边是否有路径
            if (!haspath)  //如果子节点没有路径，则说明从当前节点不可能找到路径，回溯
            {
                --itr;  //迭代器回退
                visited[row * columns + column] = false;  //将该节点标记为未访问，方便其他节点再进行访问
            }
        }
        return haspath;  //返回结果
    }

    bool exist(vector<vector<char>>& board, string& word)
    {
        if (!word.size())  //所给的word为空
            return true;
        //获得矩阵的行列数
        unsigned int rows = board.size(), columns = board[0].size();
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < columns; ++j)
            {
                if (board[i][j] == word[0])  //找到可行节点位置
                {
                    auto itr = word.begin();
                    vector<bool> visited(rows * columns, false);  //标记节点是否被访问
                    if (findpath(board, word, visited, i, j, itr))  //从该节点出发寻找到了路径
                        return true;
                }
            }
        return false;  //所有可能的路径都找了也没到找，返回false
    }
};



int main()
{
    return 0;
}
