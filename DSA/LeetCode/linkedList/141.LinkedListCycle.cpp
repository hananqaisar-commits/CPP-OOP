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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        if (head == nullptr)
        {
            return false;
        }
        if (head->next == nullptr)
        {
            return false;
        }
        while (fast != nullptr && fast->next != nullptr) // i have toensure bothh fast and fast->next will not nullptr bcz i am moving fast by 2 nodes so make sure this check
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                return true;
            }
        }
        return false;
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

    cout << "Test 1: " << boolalpha << obj.hasCycle(head1) << endl;
    cout << "Test 2: " << boolalpha << obj.hasCycle(head2) << endl;
    cout << "Test 3: " << boolalpha << obj.hasCycle(head3) << endl;

    return 0;
}