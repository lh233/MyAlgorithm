#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，
 * 但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
 * 例如，如果输入长度为7的数组[2,3,1,0,2,5,3]，那么对应的输出是2或者3。存在不合法的输入的话输出-1
 * 数据范围：0\le n \le 10000 \0≤n≤10000
 * 进阶：时间复杂度O(n)\O(n) ，空间复杂度O(n)\O(n)
 */
class Solution {
public:
    int duplicate(std::vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i-1] == nums[i])
                return nums[i];
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
