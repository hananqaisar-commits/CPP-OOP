#include <iostream>
using namespace std;
template <typename object>
struct treeNode
{
    object data;
    treeNode<object> *left;
    treeNode<object> *right;
};
template <typename object>
class tree
{
public:
    treeNode<object> *root = nullptr;
    void insertion(object value)
    {
        treeNode<object> *current = root;
        treeNode<object> *newNode = new treeNode<object>();
        treeNode<object> *previous = nullptr;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        while (current != nullptr)
        {
            previous = current;
            if (newNode->data < current->data)
            {
                current = current->left;
            }
            else if (newNode->data > current->data)
            {
                current = current->right;
            }
            else
            {
                cout << "Already existed!\n";
                return;
            }
        }
        if (newNode->data < previous->data)
        {
            previous->left = newNode;
        }
        else if (newNode->data > previous->data)
        {
            previous->right = newNode;
        }
        else
        {
            cout << "Invalid\n";
            return;
        }
    }

    void displayInorder(treeNode<object> *current)
    {
        if (current == nullptr)
        {
            return;
        }
        displayInorder(current->left);
        cout << current->data << " ";
        displayInorder(current->right);
    }
    void displayInorder()
    {
        displayInorder(root);
    }
};
int main()
{
    tree<int> *t = new tree<int>();
    t->insertion(10);
    t->insertion(20);
    t->insertion(30);
    t->insertion(40);

    t->displayInorder();
    delete t;

    return 0;
}