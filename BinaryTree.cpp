/*THIS IS BINARY TREE IT IS INTERESTING*/
#include <iostream>

struct node
{
    int data;
    node* left;
    node* right;
};

class BinaryTree
{
private:
    node* root{NULL};
public:
    void create(int key)
    {
        if (root == NULL)
        {
            root = new node;
            root->data = key;
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            insert(key, root);
        }
    }
    void inorderPrint()
    {
        std::cout << "sequence by doing inorder traversal : ";
        inorder(root);
        std::cout << "\n";
    }
    void preorderPrint()
    {
        std::cout << "sequence by doing preorder traversal : ";
        preorder(root);
        std::cout << "\n";
    }
    void postorderPrint()
    {
        std::cout << "sequence by doing postorder traversal : ";
        postorder(root);
        std::cout << "\n";
    }

private:
    void insert(int key, node* leaf)
    {
        if (leaf->data < key)
        {
            if (leaf->left != NULL)
            {
                insert(key, leaf->left);
            }
            else
            {
                leaf->left = new node;
                leaf->left->data = key;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
        }
        if (leaf->data > key)
        {
            if (leaf->right != NULL)
            {
                insert(key, leaf->right);
            }
            else
            {
                leaf->right = new node;
                leaf->right->data = key;
                leaf->right->left = NULL;
                leaf->right->right = NULL;
            }
        }
    }
    void inorder(node* root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            std::cout << root->data << " ";
            inorder(root->right);
        }
    }
    void preorder(node* root)
    {
        if (root != NULL)
        {
            std::cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(node* root)
    {
        if (root != NULL)
        {
            postorder(root->left);
            postorder(root->right);
            std::cout << root->data << " ";
        }
    }
};

int main()
{
    BinaryTree b;
    b.create(10);
    b.create(13);
    b.create(5);
    b.create(7);
    b.create(30);
    b.inorderPrint();
    b.preorderPrint();
    b.postorderPrint();
    std::cout << "Hello World!\n";
    return 0;
}

