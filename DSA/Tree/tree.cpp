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

    void displayInOrder(treeNode<object> *current)
    {
        if (current == nullptr)
        {
            return;
        }
        displayInOrder(current->left);
        cout << current->data << " ";
        displayInOrder(current->right);
    }
    void displayInOrder()
    {
        displayInOrder(root);
    }
    void displayInOrder()
    {
        displayInOrder(root);
    }
    void displayPreOrder(treeNode<object> *current)
    {
        if (current == nullptr)
        {
            return;
        }
        cout << current->data << " ";
        displayPreOrder(current->left);
        displayPreOrder(current->right);
    }
    void displayPreOrder()
    {
        displayPreOrder(root);
    }
    void displayPostOrder(treeNode<object> *current)
    {
        if (current == nullptr)
        {
            return;
        }
        displayPostOrder(current->left);
        displayPostOrder(current->right);
        cout << current->data << " ";
    }
    void displayPostOrder()
    {
        displayPostOrder(root);
    }
    void insertRecursively(object value)
    {
        treeNode<object> *current = root;
        if (current == nullptr)
        {
            cout << "Inserted into root\n";
            return;
        }
    }
};
int main()
{
    tree<int> *t = new tree<int>();
    t->insertion(10);
    t->insertion(20);
    t->insertion(30);
    t->insertion(40);
    t->insertion(40);

    t->displayInOrder();
    delete t;

    return 0;
}