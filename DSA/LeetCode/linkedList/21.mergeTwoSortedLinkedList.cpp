#include <iostream>
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        next = nullptr;
    }
};
class Solution
{
public:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    void insertAtEnd(int value)
    {
        ListNode *newNode = new ListNode();

        newNode->val = value;
        newNode->next = nullptr;

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *currentl1 = list1;
        ListNode *currentl2 = list2;

        while (currentl1 != nullptr && currentl2 != nullptr)
        {
            if (currentl1->val <= currentl2->val)
            {
                insertAtEnd(currentl1->val);
                currentl1 = currentl1->next;
            }
            else
            {
                insertAtEnd(currentl2->val);
                currentl2 = currentl2->next;
            }
        }

        while (currentl1 != nullptr)
        {
            insertAtEnd(currentl1->val);
            currentl1 = currentl1->next;
        }

        while (currentl2 != nullptr)
        {
            insertAtEnd(currentl2->val);
            currentl2 = currentl2->next;
        }

        return head;
    }
};