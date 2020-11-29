/******从尾到头打印链表******
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
********/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> ans;
    vector<int> reversePrint(ListNode* head) {
        while(head){
            ans.push_back(head->val);
            head = head->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
