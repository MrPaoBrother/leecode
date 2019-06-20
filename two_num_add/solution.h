/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return hasMore(l1, l2) ? addMaxMin(l1, l2) : addMaxMin(l2, l1);
    }

    bool hasMore(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return false;

        while (l1)
        {
            if (l2 == nullptr)
                return true;
            l1 = l1->next;
            l2 = l2->next;
        }
        return false;
    }

    ListNode *addMaxMin(ListNode *maxL, ListNode *minL)
    {
        if (minL == nullptr)
        {
            return maxL;
        }

        // ListNode *result = new ListNode(0);
        ListNode *head = maxL;
        ListNode *preMax;
        int flag = 0;
        while (minL)
        {
            preMax = maxL;
            int val = maxL->val + minL->val + flag;
            flag = val / 10;
            val = val % 10;
            maxL->val = val;
            maxL = maxL->next;
            minL = minL->next;
        }

        while (maxL)
        {
            preMax = maxL;
            int val = maxL->val + flag;
            flag = val / 10;
            val = val % 10;
            maxL->val = val;
            maxL = maxL->next;
        }

        if (flag != 0)
        {
            ListNode *l = new ListNode(flag);
            preMax->next = l;
        }

        return head;
    }

    int getLengthDiff(ListNode *l1, ListNode *l2)
    {
        int diff = 0;
        return 0;
    }

    long getNodeNum(ListNode &l)
    {
        long result = l.val;
        int multiple = 10;
        while (l.next)
        {
            /* code */
            result += multiple * l.next->val;
            multiple *= 10;
            l = *l.next;
        }
        return result;
    }

    ListNode *getNumNode(long long &num)
    {
        ListNode *result = new ListNode(0);
        ListNode *head = result;
        while (num > 0)
        {
            /* code */
            int val = num % 10;
            ListNode *l = new ListNode(val);
            l->val = val;
            result->next = l;
            result = result->next;
            num /= 10;
        }
        return head->next;
    }
};