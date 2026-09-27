#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *current = head;
        ListNode *previous = nullptr;
        ListNode *temp;

        int size = 0;
        while (current != nullptr)
        {
            ++size;
            current = current->next;
        }
        current = head; // again current is now at head
        size = (size - n) + 1;
        int position = 1;
        while (current != nullptr)
        {
            if (position == size && current == head)
            {
                temp = current; // just i have to delete the current one if it has more nodes then we  will handle that edgecase delete that current with temp annd move current to next and return that current this is imp edge case in leetcode
                current = current->next;
                delete temp;
                return current; //
            }
            if (position == size)
            {
                temp = current;
                previous->next = current->next;
                delete temp;
                return head;
            }
            previous = current;
            current = current->next;
            position++;
        }
        return head;
    }
};