#include<bits/stdc++.h>
#include<conio.h>
int menu();
using namespace std;
class BST
{
private:
    struct node
    {
        int item;
        node *left;
        node *right;
    };
    node *root;
protected:
    void inorderT(node *);
    void preorderT(node *);
    void postorderT(node *);
public:
    BST()
    {
        root=NULL;
    }
    void insert(int data);
    void inorder();
    void preorder();
    void postorder();
    void deletion(int data);
};
void BST::insert(int data)
{
    node *n=new node;
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    if(root==NULL)
    {
        ///tree is empty
        root=n;
    }
    else
    {
        node *t=root;
        while(1)
        {
            if(t->item==data)
            {
                ///duplicate value
                delete n;
                break;
            }
            else if(t->item<data)
            {
                ///insertion in right subtree
                if(t->right==NULL)
                {
                    t->right=n;
                    break;
                }
                t=t->right;
            }
            else
            {
                ///insertion in left subtree
                if(t->left==NULL)
                {
                    t->left=n;
                    break;
                }
                t=t->left;
            }
        }
    }
}
void BST::inorderT(node *t)
{
    if(t)
    {
        inorderT(t->left);
        cout<<t->item<<" ";
        inorderT(t->right);
    }
}
void BST::inorder()
{
    inorderT(root);
    cout<<endl;
}
void BST::preorderT(node *t)
{
    if(t)
    {
        cout<<t->item<<" ";
        preorderT(t->left);
        preorderT(t->right);
    }
}
void BST::preorder()
{
    preorderT(root);
    cout<<endl;
}
void BST::postorderT(node *t)
{
    if(t)
    {
        postorderT(t->left);
        postorderT(t->right);
        cout<<t->item<<" ";
    }
}
void BST::postorder()
{
    postorderT(root);
    cout<<endl;
}
void BST::deletion(int data)
{
    if(root==NULL)
    {
        cout<<"OPERATION FAILED: TREE IS EMPTY!"<<endl;
    }
    else
    {
        node *ptr=root;
        node *parptr=NULL;
        ///traverse
        while(ptr)
        {
            if(data==ptr->item)
            {
                break;
            }
            else if(data<ptr->item)
            {
                parptr=ptr;
                ptr=ptr->left;
            }
            else
            {
                parptr=ptr;
                ptr=ptr->right;
            }
        }
        if(ptr==NULL)
        {
            ///element not present in the tree
            cout<<"OPERATION FAILED: ELEMENT NOT FOUND!"<<endl;
        }
        else
        {
            if(parptr==NULL&&ptr!=NULL)
            {
                ///node to be deleted is the root node
                if(ptr->left==NULL&&ptr->right==NULL)
                {
                    delete ptr;
                    root=NULL;
                }
                else if(ptr->left==NULL||ptr->right==NULL)
                {
                    if(ptr->left==NULL)
                        root=ptr->right;
                    else
                        root=ptr->left;
                    delete ptr;
                }
                else
                {
                    node *parsucc=ptr;
                    node *succ=ptr->right;
                    while(succ->left)
                    {
                        parsucc=succ;
                        succ=succ->left;
                    }
                    ptr->item=succ->item;
                    if(succ->right==NULL)
                    {
                        ///successor has 0 child
                        if(parsucc->left==succ)
                        {
                            parsucc->left=NULL;
                        }
                        else
                        {
                            parsucc->right=NULL;
                        }
                        delete succ;
                    }
                    else
                    {
                        ///successor has 1 child
                        if(parsucc->right==succ)
                        {
                            parsucc->right=succ->right;
                        }
                        else
                        {
                            parsucc->left=succ->right;
                        }
                        delete succ;
                    }
                }
            }
            else
            {
                ///node to be deleted is except root node
                if(ptr->left==NULL&&ptr->right==NULL)
                {
                    ///0 child
                    if(parptr->left==ptr)
                        parptr->left=NULL;
                    else
                        parptr->right=NULL;
                    delete ptr;
                }
                else if(ptr->left==NULL&&ptr->right!=NULL||ptr->right==NULL&&ptr->left!=NULL)
                {
                    ///1 child
                    if(parptr->left==ptr)
                    {
                        if(ptr->left==NULL)
                            parptr->left=ptr->right;
                        else
                            parptr->left=ptr->left;
                    }
                    else
                    {
                        if(ptr->left==NULL)
                            parptr->right=ptr->right;
                        else
                            parptr->right=ptr->left;
                    }
                    delete ptr;
                }
                else
                {
                    ///2 child
                    node *parsucc=ptr;
                    node *succ=ptr->right;
                    while(succ->left)
                    {
                        parsucc=succ;
                        succ=succ->left;
                    }
                    ptr->item=succ->item;
                    if(succ->right==NULL)
                    {
                        ///successor has 0 child
                        if(parsucc->left==succ)
                        {
                            parsucc->left=NULL;
                        }
                        else
                        {
                            parsucc->right=NULL;
                        }
                        delete succ;
                    }
                    else
                    {
                        ///successor has 1 child
                        if(parsucc->right==succ)
                        {
                            parsucc->right=succ->right;
                        }
                        else
                        {
                            parsucc->left=succ->right;
                        }
                        delete succ;
                    }
                }
            }
        }
    }
}
int menu()
{
    int choice;
    cout<<"1.insertion"<<endl;
    cout<<"2.deletion"<<endl;
    cout<<"3.inorder traversal"<<endl;
    cout<<"4.preorder traversal"<<endl;
    cout<<"5.postorder traversal"<<endl;
    cout<<"6.Exit"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    return choice;
}
int main()
{
    BST t1;
    int data;
    while(true)
    {
        system("cls");
        t1.inorder();
        switch(menu())
        {
        case 1:
            cout<<"Enter data to Insert:";
            cin>>data;
            t1.insert(data);
            break;
        case 2:
            cout<<"Enter data to Delete:";
            cin>>data;
            t1.deletion(data);
            break;
        case 3:
            t1.inorder();
            break;
        case 4:
            t1.preorder();
            break;
        case 5:
            cout<<"Enter data to Search:";
            t1.postorder();
            break;
        case 6:
            exit(0);
        default:
            cout<<"INVALID CHOICE!!"<<endl;
        }
        getch();
    }
    return 0;
}
