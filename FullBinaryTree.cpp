/*HERE I HAVE IMPLEMENTED THE WHOLE BINARY TREE WITH ALL BASIC FUNCTIONALITIES*/

#include <iostream>

//structure of a node
struct node 
{
    int data;    //data of node
    node* left;  //connection(pointer) to left child of parent node
    node* right; //connection(pointer) to right child of parent node
};

//Class defining Binary Tree
class BinaryTree
{
private:
    node* root;       //declaring root node
    //declaring counter to count number of iterations required to search a element
    static int count; 
public:

    //constructor which also initialises root node to NULL
    BinaryTree() { root == NULL; } 

    //Destructor which will clean up the memory after exit and delete abinary Tree
    ~BinaryTree() 
    {
        std::cout << "Now since, you are exiting we are destroying the tree\n";
        destroyBTree(root);  // call function which destroys The tree
    }

    void create(int key)  //Create Function to create Binary Tree
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
            insert(key, root); //Call to insert Function 
        }
    }
    
    void searchKey(int key) // Function to search a particular element
    {
        if(root!=NULL)
        {
            int temp = search(key, root); // call to serach function
            std::cout << "In " << temp << " counts/iterations\n";
            // you will also get number of iterations required to find that element 
        }
        else 
        {
            std::cout << "element not found : ";
        }
    }

    void inorderPrint() // Function to Print inorder sequence
    {
        std::cout << "sequence by doing inorder traversal : ";
        inorder(root); // call to inorder()
        std::cout << "\n";
    }

    void preorderPrint() // Function to Print preorder sequence
    {
        std::cout << "sequence by doing preorder traversal : ";
        preorder(root); // call to preorder() 
        std::cout << "\n";
    }

    void postorderPrint() //Function to Print postorder sequence
    {
        std::cout << "sequence by doing postorder traversal : ";
        postorder(root); // call to postorder()
        std::cout << "\n";
    }

private:

    // Insert Function where actual Tree will be created and elements will be inserted
    inline void insert(int key, node* leaf)
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

    inline void inorder(node* root)    // Function for inorder Traversal
    {
        if (root != NULL)
        {
            inorder(root->left);
            std::cout << root->data << " ";
            inorder(root->right);
        }
    }

    inline void preorder(node* root)  // Function for preorder Traversal
    {
        if (root != NULL)
        {
            std::cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    inline void postorder(node* root) // Function for postorder Traversal
    {
        if (root != NULL)
        {
            postorder(root->left);
            postorder(root->right);
            std::cout << root->data << " ";
        }
    }

    // Function that destroys each and every node indivisually
    inline void destroyBTree(node* leaf) 
    {
        if (leaf != NULL)
        {
            destroyBTree(leaf->left);
            destroyBTree(leaf->right);
            delete leaf;
        }
    }
    // Function where element is searched by comparisons & no.of counts/iterations are returned 
    inline int search(int key, node* leaf)
    {
        count++;
        if (key == leaf->data)
        {
            std::cout << "element found : "<<leaf->data<<"\n";
            return count;
        }
        else if (key > leaf->data)
        {
            search(key, leaf->left);
        }
        else
        {
            search(key, leaf->right);
        }
    }
};

//Initialisation of Static int member variable
int BinaryTree::count{ 0 }; 

int main() //Entry Point
{
    BinaryTree b;//object of BinaryTree class
  
    // GIVEN BELLOW ARE THE FUNCTIONALITIES IN THIS BINARY TREE
    std::cout << "Congrats you have created a Binary Tree or Binary Search Tree\n"
        << "To add elements in Tree enter choice 1\n"
        << "To search a element in Binary Tree enter choice 2\n"
        << "To do Post-Order Traversal enter choice 3\n"
        << "To do Pre-Order Traversal enter choice 4\n"
        << "To do In-Order Traversal enter choice 5\n";
    char ch = 'y';
    int choice{ 0 };
    while (ch == 'y' || ch == 'Y')
    {
        if (ch == 'y' || ch == 'Y')
        {
            std::cout << "enter choice :\n";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                std::cout << "enter numbers you want to add\n";
                int x;
                std::cin >> x;
                b.create(x);
                break;
            case 2:
                std::cout << "enter data to be searched\n";
                int val;
                std::cin >> val;
                b.searchKey(val);
            case 3:
                b.postorderPrint();
                break;
            case 4:
                b.preorderPrint();
                break;
            case 5:
                b.inorderPrint();
                break;
            }
            std::cout << "do you want to continue,enter y or Y(to exit press n)\n";
            std::cin >> ch;
        }
        else
        {
            std::cout<<"Made by Satej Dhakane\n";
            return 0;
        }
    }
    return 0;
}

  
