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
                delete newNode;
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
    treeNode<object> *insertRecursively(treeNode<object> *current, object value)
    {

        if (current == nullptr)
        {
            treeNode<object> *newNode = new treeNode<object>();
            newNode->data = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }
        if (value < current->data)
            current->left = insertRecursively(current->left, value);

        else if (value > current->data)
            current->right = insertRecursively(current->right, value);

        else
            cout << "Already existed\n";

        return current;
    }
    int countLeafs(treeNode<object> *current, int &count)
    {
        if (current == nullptr)
        {
            return 0;
        }
        if (current->left == nullptr && current->right == nullptr)
        {
            count++;
            return 1;
        }
        countLeafs(current->left, count);
        countLeafs(current->right, count);

        return count;
    }
    treeNode<object> *searchNode(object target)
    {
        treeNode<object> *current = root;
        while (current != nullptr)
        {
            if (target < current->data)
            {
                current = current->left;
            }
            else if (target > current->data)
            {
                current = current->right;
            }
            else
            {
                cout << "Node Found\n";
                return current;
            }
        }
        cout << "Node not found\n";
        return nullptr;
    }

    int countNodes(treeNode<object> *current, int &count)
    {
        if (current == nullptr)
        {
            return 0;
        }
        count++;
        countNodes(current->left, count);
        countNodes(current->right, count);
        return count;
    }
    void displayPreOrderRightPriority(treeNode<object> *current)
    {
        if (current == nullptr)
            return;

        cout << current->data << " ";
        displayPreOrderRightPriority(current->right);
        displayPreOrderRightPriority(current->left);
    }

    void displayInOrderRightPriority(treeNode<object> *current)
    {
        if (current == nullptr)
            return;

        displayInOrderRightPriority(current->right);
        cout << current->data << " ";
        displayInOrderRightPriority(current->left);
    }

    void displayPostOrderRightPriority(treeNode<object> *current)
    {
        if (current == nullptr)
            return;

        displayPostOrderRightPriority(current->right);
        displayPostOrderRightPriority(current->left);
        cout << current->data << " ";
    }
    treeNode<object> *maxNode()
    {
        treeNode<object> *maxNodeCount = new treeNode<object>();
        maxNodeCount->data = 0;
        maxNodeCount->left = nullptr;
        maxNodeCount->right = nullptr;
        treeNode<object> *current = root;
        while (current != nullptr)
        {
            if (current->data > maxNodeCount->data)
            {
                maxNodeCount = current;
                current = current->right;
            }
        }
        return maxNodeCount;
    }
};
int main()
{
    tree<int> *t = new tree<int>();
    t->insertion(50);
    t->insertion(30);
    t->insertion(70);
    t->insertion(20);
    t->insertion(40);
    t->insertion(60);
    t->insertion(80);
    t->insertion(10);
    t->insertion(10);
    t->insertion(35);
    t->insertion(65);

    int count = 0;
    int count2 = 0;

    t->displayInOrder();
    cout << endl;
    cout << "Total Leafs: " << t->countLeafs(t->root, count) << " \n";
    cout << "Total Nodes: " << t->countNodes(t->root, count2) << " \n";

    t->displayPreOrderRightPriority(t->root);
    cout << endl;
    t->displayInOrderRightPriority(t->root);
    cout << endl;
    t->displayPostOrderRightPriority(t->root);
    cout << endl;
    treeNode<int> *founded = t->searchNode(35);
    cout << founded->data << " \n";
    treeNode<int> *maxNode = t->maxNode();
    cout << "Max Node: " << maxNode->data << " \n";

    delete t;
    return 0;
}