#include <iostream>
template <typename object>
struct singlyNode
{
    object data;
    singlyNode<object> *next;
};
template <typename object>
class Solution
{
public:
    singlyNode<object> *reverseLinkedListFirstHalfFromMid(singlyNode<object> *&head, int size)
    {
        if (head == nullptr)
        {
            return head;
        }

        int middle = size / 2;
        int count = 0;

        singlyNode<object> *current = head;
        singlyNode<object> *previous = nullptr;
        singlyNode<object> *mid = nullptr;
        singlyNode<object> *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            ++count;
            previous = current;
            current = next;

            if (count == middle)
            {
                mid = current;
                break;
            }
        }

        head->next = current;
        head = previous;

        if (size % 2 != 0)
        {
            return mid;
        }

        return current;
    }

    bool isPalindrome(singlyNode<object> *head)
    {
        if (head == nullptr)
            return true;

        if (head->next == nullptr)
            return true;

        // now count size of the linkedlist
        int size = 0;
        singlyNode<object> *temp = head;

        while (temp != nullptr)
        {
            ++size;
            temp = temp->next;
        }

        singlyNode<object> *mid = reverseLinkedListFirstHalfFromMid(head, size);

        singlyNode<object> *current1 = head;
        singlyNode<object> *current2 = mid->next;

        bool result = false;
        if (size % 2 != 0)
        {
            while (current2 != nullptr)
            {
                if (current1->data != current2->data)
                {
                    reverseLinkedListFirstHalfFromMid(head, size);
                    return result;
                }
                current1 = current1->next;
                current2 = current2->next;
            }

            reverseLinkedListFirstHalfFromMid(head, size);
            result = true;
        }
        else
        {
            current2 = mid;

            while (current2 != nullptr)
            {
                if (current1->data != current2->data)
                {
                    reverseLinkedListFirstHalfFromMid(head, size);
                    return result;
                }

                current1 = current1->next;
                current2 = current2->next;
            }

            reverseLinkedListFirstHalfFromMid(head, size);
            result = true;
        }

        return result;
    }

    void printList(singlyNode<object> *head)
    {
        singlyNode<object> *current = head;

        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    Solution<int> *sol = new Solution<int>();
    singlyNode<int> *head = new singlyNode<int>();
    singlyNode<int> *node2 = new singlyNode<int>();
    singlyNode<int> *node3 = new singlyNode<int>();
    head->data = 10;
    node2->data = 20;
    node3->data = 10;
    head->next = node2;
    node2->next = node3;
    node3->next = nullptr;

    std::cout << sol->isPalindrome(head) << " ";

    sol->printList(head);
}