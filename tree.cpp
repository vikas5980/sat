#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct node 
{
    int data; 
    struct node *left, *right;
} Node;

Node *createNewNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == nullptr)
    {
        printf("Mem alloaction failed");
        return nullptr;
    }
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void inOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);

    printf("%d -> ", root->data);

    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    printf("%d -> ", root->data);
    
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
    printf("%d -> ", root->data);
}

int getNumOfNodesInBST(Node *root)
{
    if (root == nullptr)
        return 0;

    int left = getNumOfNodesInBST(root->left);
    int right = getNumOfNodesInBST(root->right);

    return (left + right) + 1;
}

int getMaxHeightOfBST(Node *root)
{
    if (nullptr == root)
        return -1;

    int lHeight = getMaxHeightOfBST(root->left);
    int rHeight = getMaxHeightOfBST(root->right);

    return ((lHeight > rHeight) ? lHeight : rHeight) + 1;
}

void mirror(Node *root)
{
    if (root == nullptr)
        return;

    mirror(root->left);
    mirror(root->right);

    Node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int countLeafNodes(Node *root)
{
    if (root == nullptr)
        return 0 ;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void inOrderTraversal(Node* root, vector<int> &arr)
{
    if (root == nullptr)
        return;
    
    inOrderTraversal(root->left, arr);
    arr.push_back(root->data);
    inOrderTraversal(root->right, arr);
}

int minValue(Node* root) 
{
    // Code here
    vector<int> arr;
    inOrderTraversal(root, arr);
    
    return arr[0];
}

int main() 
{
    Node *root = createNewNode(1); 
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5); 
    root->right->right = createNewNode(6);

    printf("\n inOrderTraversal   : ");
    inOrderTraversal(root);

    printf("\n preOrderTraversal   : ");
    preOrderTraversal(root);

    printf("\n postOrderTraversal   : ");
    postOrderTraversal(root);

    printf("\n getNumOfNodesInBST   : %d \n", getNumOfNodesInBST(root));

    printf("\n getMaxHeightOfBST   : %d \n", getMaxHeightOfBST(root));

    printf("\n postOrderTraversal : \n");
    postOrderTraversal(root);
    mirror(root);
    printf("\n mirror : \n");
    postOrderTraversal(root);

    printf("\n count leaf nodes : %d", countLeafNodes(root));

    printf("\n minValue : %d", minValue(root));

    return 0;
}