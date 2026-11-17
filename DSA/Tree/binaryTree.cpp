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
    treeNode<object> *root = nullptr;
    void insertData(object value)
    {
        treeNode<object> *previous = nullptr;
        treeNode<object> *newNode = new treeNode<object>();

        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        treeNode<object> *current = root;
        while (current != nullptr)
        {
            previous = current; // save the previous one bcz we will use this previous for the insertion untill ourr current reach to the nullptr
            if (value == current->data)
            {
                cout << "Already Existed\n";
                break;
            }
            else if (value < current->data)
            {
                current = current->left;
            }
            else if (value > current->data)
            {
                current = current->right;
            }
        }
        if (value < previous->data)
        {
            previous->left = newNode;
            cout << "Node inserted to left pointer\n";
        }
        if (value > previous->data)
        {
            previous->right = newNode;
            cout << "Node inserted to right pointer\n";
        }
    }

    void insertDataRecursively(treeNode<object> *&currentNode, object value)
    {
        if (currentNode == nullptr)
        {
            treeNode<object> *newNode = new treeNode<object>();
            newNode->data = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            currentNode = newNode;
        }
        else if (value < currentNode->data)
        {
            insertDataRecursively(currentNode->left, value);
        }
        else if (value > currentNode->data)
        {
            insertDataRecursively(currentNode->right, value);
        }
        else
        {
            cout << "Already Existed\n";
        }
    }
    void insertDataRecursively(object value)
    {
        insertDataRecursively(root, value);
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
    void displayPreorder(treeNode<object> *current)
    {
        if (current == nullptr)
        {
            return;
        }
        cout << current->data << " ";
        displayPreorder(current->left);
        displayPreorder(current->right);
    }
    void displayInorder()
    {
        displayInorder(root);
    }
    void displayPreorder()
    {
        displayPreorder(root);
    }
};
int main()
{
    Tree<int> *tree = new Tree<int>();
    tree->insertData(10);
    tree->insertData(20);
    tree->insertData(30);
    tree->insertData(40);

    tree->insertDataRecursively(60);
    tree->displayInorder();
    return 0;
}
