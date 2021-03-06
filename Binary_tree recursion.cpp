#include <iostream>

using namespace std;

class binaryTreeNode
{

    binaryTreeNode* _left{};
    binaryTreeNode* _right{};
    int _data{};
    friend class binaryTree;
public:
    binaryTreeNode(int data) : _data(data) { }

};

class binaryTree
{
private:
    binaryTreeNode* root = NULL;
    int _count = 0;
public:

    void insertData(int data, binaryTreeNode* root)
    {

        if (data > root->_data)
        {
            if (root->_right == NULL)
            {
                root->_right = new binaryTreeNode(data);
                root->_right->_right = NULL;
                root->_right->_left = NULL;
                _count++;
            }
            else insertData(data, root->_right);
        }
        else if (data < root->_data)
        {
            if (root->_left == NULL)
            {
                root->_left = new binaryTreeNode(data);
                root->_left->_right = NULL;
                root->_left->_left = NULL;
                _count++;
            }
            else insertData(data, root->_left);

        }
    }

    void insert(int data)
    {

        if (root == NULL || _count == 0)
        {
            root = new binaryTreeNode(data);
            root->_right = NULL;
            root->_left = NULL;
            _count++;
        }
        else insertData(data, root);
    }

    void recursionStandart(binaryTreeNode* root)
    {
        cout << root->_data << endl;
        if (root->_left != NULL) recursionStandart(root->_left);
        if (root->_right != NULL) recursionStandart(root->_right);
    }
    void PrintStandart()
    {
        binaryTreeNode* temp = root;
        recursionStandart(temp);
    }
    void recursionInorder(binaryTreeNode* root)
    {
        if (root->_left != NULL) recursionInorder(root->_left);
        cout << root->_data << endl;
        if (root->_right != NULL) recursionInorder(root->_right);
    }
    void PrintInorder()
    {
        binaryTreeNode* temp = root;
        recursionInorder(temp);
    }
};

int main()
{

    binaryTree tree;
    tree.insert(39.5);
    tree.insert(50.1);
    tree.insert(8);
    tree.insert(5);
    tree.insert(6);
    tree.insert(1);
    tree.insert(9);
    tree.insert(40);
    tree.insert(10);
    tree.PrintInorder();

    cout << endl;
    tree.PrintStandart();

}
