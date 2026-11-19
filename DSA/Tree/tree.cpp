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
    t->insertion(35);
    t->insertion(65);

    int choice;
    int value;
    do
    {
        cout << "\n========== BST MENU ==========\n";

        cout << "\n--- Normal Traversals ---\n";
        cout << "1. Inorder (Infix)\n";
        cout << "2. Preorder (Prefix)\n";
        cout << "3. Postorder (Postfix)\n";

        cout << "\n--- Right Priority Traversals ---\n";
        cout << "4. Inorder Right Priority (RNL)\n";
        cout << "5. Preorder Right Priority (NRL)\n";
        cout << "6. Postorder Right Priority (RLN)\n";

        cout << "\n--- Other Operations ---\n";
        cout << "7. Search Node\n";
        cout << "8. Count Leaf Nodes\n";
        cout << "9. Count Total Nodes\n";
        cout << "10. Find Maximum Node\n";

        cout << "\n0. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Inorder: ";
            t->displayInOrder();
            cout << endl;
            break;
        case 2:
            cout << "Preorder: ";
            t->displayPreOrder();
            cout << endl;
            break;
        case 3:
            cout << "Postorder: ";
            t->displayPostOrder();
            cout << endl;
            break;
        case 4:
            cout << "Inorder Right Priority: ";
            t->displayInOrderRightPriority(t->root);
            cout << endl;
            break;
        case 5:
            cout << "Preorder Right Priority: ";
            t->displayPreOrderRightPriority(t->root);
            cout << endl;
            break;
        case 6:
            cout << "Postorder Right Priority: ";
            t->displayPostOrderRightPriority(t->root);
            cout << endl;
            break;
        case 7:
        {
            cout << "Enter value to search: ";
            cin >> value;
            treeNode<int> *found = t->searchNode(value);
            if (found != nullptr)
                cout << "Node Found: " << found->data << endl;
            else
                cout << "Node Not Found!\n";
            break;
        }
        case 8:
        {
            int count = 0;
            t->countLeafs(t->root, count);
            cout << "Total Leafs: " << count << endl;
            break;
        }
        case 9:
        {
            int count = 0;
            t->countNodes(t->root, count);
            cout << "Total Nodes: " << count << endl;
            break;
        }
        case 10:
        {
            treeNode<int> *maxNode = t->maxNode();
            if (maxNode != nullptr)
                cout << "Maximum Node: " << maxNode->data << endl;
            else
                cout << "Tree is Empty!\n";
            break;
        }
        case 0:
            cout << "Program Exited!\n";
            break;
        default:
            cout << "Invalid Choice! Try Again.\n";
        }
    } while (choice != 0);
    delete t;

    return 0;
}