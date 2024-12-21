#ifdef DEBUG
#include <stdio.h>
#endif
#include <stdlib.h>
#include "bst.h"

// Local functions
// I used a lot of local functions so that I could use recursive functions on nodes
struct Node
{
    Node * left;
    Node * right;
    void * data;
    long long key;
};
/*
Creates and allocates memory for a node, places the values taken into the node and then returns the node. */
Node * makeNode(Node * left, Node * right, void * data, long long key)
{
    Node * n = malloc(sizeof(Node));
    if(n)
    {
        *n = (Node){left,right,data,key};
    }
    return n;
}
/*
Finds and returns the Node that has the minimum key.*/
Node * minimumkey(Node * node)
{
    Node * temp = node;
    while(temp->left)
    {
        temp = temp->left;
    }
    return temp;
}
/*
helper function for tree insert, takes node and inserts it into the tree of root.*/
void Insert(Node *root, Node * node)
{
    if(root->left==NULL&&node->key<root->key)
    {
        root->left=node;
    }
    else if(root->right==NULL&&node->key>root->key)
    {
        root->right=node;
    }
    else{
        if(root->key>node->key)
        {
            Insert(root->left,node);
        }
        else if(root->key<node->key)
        {
            Insert(root->right,node);
        }
    }
}
/*
Helper function for InOrder. Prints the tree of root from left to right.*/
void NodeInOrder(Node * root, NODEVISITFUNC func)
{
    if(root!=NULL)
    {
        NodeInOrder(root->left,func);
        func(root->data);
        NodeInOrder(root->right,func);
    }
}
/*
Helper function for PreOrder. Prints the tree of root starting with the root, then goes to the left subtree, then the right.*/
void NodePreOrder(Node * root, NODEVISITFUNC func)
{
    if(root!=NULL)
    {
        func(root->data);
        NodePreOrder(root->left,func);
        NodePreOrder(root->right,func);
    }
}
/*
Helper function for PostOrder. Prints the tree of root starting with the left subtree, then the right, then prints the root*/
void NodePostOrder(Node * root, NODEVISITFUNC func)
{
    if(root!=NULL)
    {
        NodePostOrder(root->left,func);
        NodePostOrder(root->right,func);
        func(root->data);
    }
}
/*
Helper function for tree delete. Deletes node with key: key, and maintains the characteristics of a binary tree.*/
Node * NodeTreeDelete(Node * node, long long key)
{
    Node* temp;
    if (node == NULL) return node;
    if (key < node->key){
        node->left = NodeTreeDelete(node->left, key);
    }
    else if (key > node->key){
        node->right = NodeTreeDelete(node->right, key);
    }
    else{
        if (node->left == NULL){
            temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL){
            temp = node->left;
            free(node);
            return temp;
        }
        temp = minimumkey(node->right);
        node->key = temp->key;
        node->data = temp->data;
        node->right = NodeTreeDelete(node->right, temp->key);
    }
    return node;
}
// These are stubs.  That is, you need to implement these functions.

/*
Creates and allocates space for a BST, then returns it.*/
BST * NewBST()
{
    BST * B = malloc(sizeof(BST));
    if(B)
    {
        B->root=NULL;
        return B;
    }
    return NULL;
}
/*
Inserts a node with data: satelite and key: key into pBST.*/
void TreeInsert(BST * pBST, void * satellite, long long key)
{
    Node * node = makeNode(NULL,NULL,satellite,key);
    if(pBST->root==NULL)
    {
        pBST->root=node;
    }
    else{
    Insert(pBST->root,node);
    }
}
/*
Prints p in order*/
void InOrder(BST * p, NODEVISITFUNC func)
{
    NodeInOrder(p->root,func);
}
/*
Prints pBST in preorder.*/
void PreOrder(BST * pBST, NODEVISITFUNC func)
{
    NodePreOrder(pBST->root,func);
}

/*
prints pBST in postorder.*/
void PostOrder(BST * pBST, NODEVISITFUNC func)
{
    NodePostOrder(pBST->root,func);
}

/*
Searches pBST for a node with key: key then returns the data from the node if found or NULL if not found. */
void * Search(BST * pBST, long long key)
{
    Node * temp = pBST->root;
    while(temp->key!=key && temp!=NULL)
    {
        if(temp->key>key)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    if(temp)
    {
        return temp->data;
    }
    else
    {
        return NULL;
    }
}

/*
Deletes the node with key: key from pBST*/
void TreeDelete(BST * pBST, long long key)
{
    if(pBST==NULL)
    {
        return;
    }
    NodeTreeDelete(pBST->root,key);
}

