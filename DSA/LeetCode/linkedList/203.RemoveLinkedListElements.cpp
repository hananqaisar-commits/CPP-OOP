#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return head;
        ListNode *current = head;
        ListNode *previous = nullptr;
        while (current != nullptr)
        {
            if (current->val == val)
            {
                if (previous == nullptr)
                    head = current->next;
                else
                    previous->next = current->next;
            }
            else
                previous = current;
            current = current->next;
        }
        return head;
    }
};
int main()
{

    Solution *sol = new Solution();
    ListNode *head = new ListNode();
    ListNode *node2 = new ListNode();
    ListNode *node3 = new ListNode();
    ListNode *node4 = new ListNode();
    head->val = 10;
    node2->val = 20;
    node3->val = 20;
    node4->val = 40;

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;

    sol->removeElements(head, 20);

    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << "->";
        current = current->next;
    }
    cout << "nullptr" << endl;

    return 0;
}