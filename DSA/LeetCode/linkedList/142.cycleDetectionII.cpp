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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) // i have toensure bothh fast and fast->next will not nullptr bcz i am moving fast by 2 nodes so make sure this check
        {
            slow = slow->next;
            fast = fast->next->next;

            int count = 0;
            if (fast == slow)
            {
                ListNode *newNodeCurrent = head;
                while (newNodeCurrent != slow)
                {
                    newNodeCurrent = newNodeCurrent->next;
                    slow = slow->next;
                }
                return newNodeCurrent;
            }
        }
        return nullptr;
    }
};
int main()
{
    // Test 1: No cycle
    ListNode *head1 = new ListNode();
    head1->val = 1;
    head1->next = new ListNode();
    head1->next->val = 2;
    head1->next->next = new ListNode();
    head1->next->next->val = 3;
    head1->next->next->next = new ListNode();
    head1->next->next->next->val = 4;

    // Test 2: Cycle
    ListNode *head2 = new ListNode();
    head2->val = 1;
    head2->next = new ListNode();
    head2->next->val = 2;
    head2->next->next = new ListNode();
    head2->next->next->val = 3;
    head2->next->next->next = new ListNode();
    head2->next->next->next->val = 4;

    // 4 -> 2
    head2->next->next->next->next = head2->next;

    // Test 3: Single node, no cycle
    ListNode *head3 = new ListNode();
    head3->val = 10;

    Solution obj;

    ListNode *ans = obj.detectCycle(head1);

    int count = 0;

    for (ListNode *current = head1; current != ans; current = current->next)
    {
        count++;
    }
    cout << count << endl;

    return 0;
}