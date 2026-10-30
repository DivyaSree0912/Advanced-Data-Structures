#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node *root, int value){
    if (root == NULL){
        return createNode(value);
    }
    if (value < root->data){
        root->left = insert(root->left, value);
    }
    else if (value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
}

struct node* search(struct node *root, int value){
    if (root == NULL || root->data == value){
        return root;
    }
    if (value < root->data){
        return search(root->left, value);
    }
    return search(root->right, value);
}

struct node* findMin(struct node *root){
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node *root, int value){
    if (root == NULL){
        return root;
    }
    if (value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data){
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else
        {
            struct node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    struct node *root = NULL;
    struct node *found;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    found = search(root, 40);

    if (found != NULL){
        printf("\n\nElement 40 is found");
    }
    else{
        printf("\n\nElement 40 is not found");
    }

    root = deleteNode(root, 70);

    printf("\n\nAfter deleting 70:");
    printf("\nInorder: ");
    inorder(root);

    return 0;
}