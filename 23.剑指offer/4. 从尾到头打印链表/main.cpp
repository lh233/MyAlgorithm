#include <iostream>

using namespace std;

/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

输入head: [1, 3, 2]
输出 [2, 3, 1]
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        stack<int> stk;
        ListNode * p = head;
        while(p)
        {
            stk.push(p->val);
            p = p->next;
        }

        vector<int> ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;
    }
};
