#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
};
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        if (head == nullptr)
        {
            return head;
        }
        if (head->next == nullptr)
        {
            return head;
        }
        while (fast != nullptr && fast->next != nullptr) // i have toensure bothh fast and fast->next will not nullptr bcz i am moving fast by 2 nodes so make sure this check
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
int main()
{
    ListNode *head = new ListNode();

    head->val = 1;

    head->next = new ListNode();
    head->next->val = 2;

    head->next->next = new ListNode();
    head->next->next->val = 3;

    head->next->next->next = new ListNode();
    head->next->next->next->val = 4;

    head->next->next->next->next = new ListNode();
    head->next->next->next->next->val = 5;

    Solution *sol = new Solution();
    ListNode *find = sol->middleNode(head);

    cout << find->val;

    return 0;
}