#include <iostream>
#include <string>

using namespace std;

/*
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣

*/

/*
��������������һ���ڵ㣬һ�������������
1.������Ϊ�գ��򷵻ؿգ�

2.�ڵ��Һ��Ӵ��ڣ�������һ��ָ��Ӹýڵ���Һ��ӳ�����һֱ����ָ�����ӽ���ָ���ҵ���Ҷ�ӽڵ㼴Ϊ��һ���ڵ㣻

3.�ڵ㲻�Ǹ��ڵ㡣����ýڵ����丸�ڵ�����ӣ��򷵻ظ��ڵ㣻����������ϱ����丸�ڵ�ĸ��ڵ㣬�ظ�֮ǰ���жϣ����ؽ�����������£�
*/


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==nullptr)
            return nullptr;

        TreeLinkNode* p1;
        if(pNode->right!=nullptr){
            p1=pNode->right;
            while(p1->left!=nullptr)
                p1=p1->left;
            return p1;
        }

        while(pNode->next!=nullptr){
            TreeLinkNode* pfa=pNode->next;
            if(pNode==pfa->left)
                return pfa;
            pNode=pNode->next;
        }

        return nullptr;
    }
};


int main()
{
    TreeLinkNode tree = TreeLinkNode(10);       // ���ĸ��ڵ�


    return 0;
}
