#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//视频+https://www.bilibili.com/video/BV11f4y1H7Rv?p=6&vd_source=9dcdb878abe0bc5fe7c8ed499dcbdf99

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    //preorder是指
    TreeNode *reConstructBinaryTree(vector<int> &pre, vector<int> &vin)
    {
        if (pre.size() == 0)
            return nullptr;
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode*));
        vector<int> leftPre, leftVin, rightPre, rightVin;

        //根节点的值就是第一个值
        node->val = pre[0];
        int left = 0;

        //根据中序序列确定根节点的位置
        for (int i = 0; i < vin.size(); i++) {
            if (pre[0] == vin[i]) {
                left = i;
                break;
            }
        }

        //左边前序+中序递归的数组
        for (int i = 0; i < left; i++) {
            leftPre.push_back(pre[i + 1]);
            leftVin.push_back(vin[i]);
        }

        //右边前序加+中序递归的数组
        for (int i = left + 1; i < pre.size(); i++) {
            rightPre.push_back(pre[i]);
            rightVin.push_back(vin[i]);
        }

        node->left = reConstructBinaryTree(leftPre, leftVin);
        node->right = reConstructBinaryTree(rightPre, rightVin);
        return node;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    vector<int> preorder={ 1, 2, 4, 3, 5, 6 };
    vector<int> inorder = { 2, 4, 1, 3, 6, 5 };
    Solution MySolution;
    TreeNode * TNode = MySolution.reConstructBinaryTree(preorder, inorder);

    return 0;
}
