#include <iostream>

struct node
{
    int data;
    node* left;
    node* right;
}* root;


class AVL
{
public:
    AVL() { root = NULL; }
    node* insert(node* root,int key)
    {
        if(root==NULL)
        {
            root=new node;
            root->data=key;
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        else if (root->data > key)
        {
            root->left=insert(root->left,key);
            root=balance(root);
        }
        else if (root->data < key)
        {
            root->right=insert(root->right,key);
            root=balance(root);
        }
        return root;  
    }
    int height(node* leaf)
    {
        int h{0};
        if(leaf!=NULL)
        {
            int l_height=height(leaf->left);
            int r_height=height(leaf->right);
            h=std::max(l_height,r_height);
            return h+1;
        }
        return h;
    }
    int balanceFactor(node* leaf)
    {
        int l_height=height(leaf->left);
        int r_height=height(leaf->right);
        int b_factor=l_height-r_height;
        return b_factor;
    }
    node* llRotation(node* leaf)
    {
        node* temp;
        temp=leaf->left;
        leaf->left=temp->right;
        temp->right=leaf;
        return temp;
    }
    node* rrRotation(node* leaf)
    {
        node* temp;
        temp=leaf->right;
        leaf->right=temp->left;
        temp->left=leaf;
        return temp;
    }
    node* rlRotation(node* leaf)
    {
        node* temp;
        temp=leaf->right;
        leaf->right=llRotation(temp);
        return rrRotation(leaf);
    }
    node* lrRotation(node* leaf)
    {
        node* temp;
        temp=leaf->left;
        leaf->left=rrRotation(temp);
        return llRotation(leaf);
    }
    node* balance(node* leaf)
    {
        int bal_factor = balanceFactor(leaf);
    	if (bal_factor > 1)
    	{
    		if (balanceFactor(leaf->left) > 0)
    		{
    			leaf = llRotation(leaf);
    		}
    		else
    		{
    			leaf = lrRotation(leaf);
    		}
    	}
    	else if (bal_factor < -1)
    	{
    		if (balanceFactor(leaf->right) > 0)
    		{
    			leaf = rlRotation(leaf);
    		}
    		else
    		{
    			leaf = rrRotation(leaf);
    		}
    	}
	    return leaf;
    }
    void inorder(node* leaf)
    {
        if(leaf!=NULL)
        {
        inorder(leaf->left);
        std::cout<<leaf->data<<"\t";
        inorder(leaf->right);
        }
    }
};

using std::cout;
using std::endl;

int main()
{
	int choice, item;
	AVL avl;
	while (1)
	{
		cout << "1.Insert Element into the tree" << endl;
		cout << "2.InOrder traversal" << endl;
		cout << "3.Exit" << endl;
		cout << "Enter your Choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter value to be inserted: ";
			std::cin >> item;
			root = avl.insert(root, item);
			break;
		case 2:
			cout << "Inorder Traversal:" << endl;
			avl.inorder(root);
			cout << endl;
			break;
		case 3:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}
