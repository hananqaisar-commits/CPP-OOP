#include <iostream>
using namespace std;

template <typename object>
struct treeNode
{
    object data;
    treeNode *left;
    treeNode *right;
};
template <typename object>
class Tree
{
public:
    treeNode<object> *root = new treeNode<object>();

    treeNode<object> *current = root;
    treeNode<object> *insertData(object value)
    {
        if (current == nullptr)
        {
            treeNode<object> *newNode = new treeNode<object>();
            newNode->data = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }
        if (current->data < value)
        {
            current = current->right;
            current->right = insertData(value);
        }
        else if (current->data > value)
        {
            current = current->left;
            current->left = insertData(value);
        }
        return current;
    }
    void display()
    {
        treeNode<object> *current = nullptr;
        treeNode<object> *prev = nullptr;

        while (current != nullptr)
        {
            prev = current;
            cout << current->data << " ";
            if (current->left != nullptr)
                cout << current->data << " ";
            if (current->right != nullptr)
                cout << current->data << " ";

            current = prev;
        }
    }
};

int main()
{
    Tree<int> *tree = new Tree<int>();

    tree->insertData(10);
    tree->insertData(20);
    tree->insertData(30);

    tree->display();
    return 0;
}