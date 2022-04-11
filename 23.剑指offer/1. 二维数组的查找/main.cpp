/*
 * @Descripttion:
 * @version:
 * @Author: linhao
 * @Date: 2022-04-05 15:20:02
 * @LastEditors: linhao
 * @LastEditTime: 2022-04-05 15:44:47
 */
#include <iostream>
#include <vector>

using namespace std;


/*
例如下面的二维数组就是每行、每列都递增排序。如果在这个数组中查找数字7，则返回true；如果查找数字5，由于数组不含有该数字，则返回false。
    1 2 8  9
    2 4 9  12
    4 7 10 13
    6 8 11 15

https://www.cnblogs.com/edisonchou/p/4737944.html
*/
class Solution {
public:
    bool Find(int target, vector<vector<int>> matrix)
    {
        if(matrix.empty() || matrix[0].empty())
            return false;

        //从右上角开始
        int row = 0;  //列
        int column = matrix[0].size() - 1;
        while( row < matrix.size()-1 && column >= 0)
        {
            if(target == matrix[row][column])
                return true;
            //当前的数字比输入的数字小，行增加
            else if(target > matrix[row][column])
            {
                row++;
            }
            else
            {
                column--;
            }


        }
        return false;

    }
};

int main()
{
    //int[,] matrix = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
    return 0;
}
