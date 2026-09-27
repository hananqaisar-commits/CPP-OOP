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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *tail = nullptr;
        ListNode *current = head;
        ListNode *previous = nullptr;

        int count = 0;
        int size = 0;
        // Find the size of linked list
        while (current != nullptr)
        {
            ++size;
            current = current->next;
        }
        // If list is empty, has only one node, or k is zero,
        // then no rotation is needed
        if (size == 0 || size == 1 || k == 0)
        {
            return head;
        }

        // Remove unnecessary full rotations
        k = k % size; // without this time complexity is the issue to pass all test cases of leetcode
        if (k == 0)
        {
            return head;
        }
        current = head; // again reset current to head
        while (current != nullptr)
        {
            if (current->next == nullptr)
            {
                // if k rotation completed, then return the list
                if (k == count)
                {
                    current = head;
                    return head;
                }
                else
                {
                    tail = current;    // 1. tail will be current
                    tail->next = head; // now tail ka next will point to head
                    head = tail;       // now tail will be my new head

                    tail = previous; // previous will become my new tail
                    previous->next = nullptr;

                    count++;
                }

                tail = nullptr;
                current = head;
                previous = nullptr;
            }
            previous = current;
            current = current->next;
        }
        return head;
    }
};

int main()
{
    Solution *sol = new Solution();

    ListNode *node3 = new ListNode(3);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *list = new ListNode(1, node2);

    int k = 7;

    list = sol->rotateRight(list, k);

    ListNode *current = list;

    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }

    return 0;
}