#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL, *temp;

void inorder(struct node *ptr)
{
    if (ptr == NULL)
        return;

    inorder(ptr->left);
    printf("%d ", ptr->data);
    inorder(ptr->right);
}

void preorder(struct node *ptr)
{
    if (ptr == NULL)
        return;

    printf("%d ", ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}

void postorder(struct node *ptr)
{
    if (ptr == NULL)
        return;

    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d ", ptr->data);
}

void insert(int x)
{
    struct node *p, *p1;

    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
        return;
    }

    p = root;
    p1 = NULL;

    while (p != NULL)
    {
        p1 = p;

        if (x < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if (x < p1->data)
        p1->left = temp;
    else
        p1->right = temp;
}

void search(int x)
{
    temp = root;

    while (temp != NULL)
    {
        if (x > temp->data)
            temp = temp->right;
        else if (x < temp->data)
            temp = temp->left;
        else
        {
            printf("\nElement %d is found\n", x);
            return;
        }
    }

    printf("\nElement not found\n");
} 

void deletion(int x)
{
    int c = 0;
    struct node *p = root, *p1 = root;

    while (p != NULL)
    {
        if (p->data == x)
        {
            c = 1;
            break;
        }

        p1 = p;

        if (x < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if (!c)
    {
        printf("Element not found\n");
        return;
    }

    // Special handling for root node
    if (p == root)
    {
        // Root is the only node
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            printf("Deleted Element = %d\n", x);
            return;
        }

        // Root has only left child
        if (root->left != NULL && root->right == NULL)
        {
            temp = root;
            root = root->left;
            free(temp);
            printf("Deleted Element = %d\n", x);
            return;
        }

        // Root has only right child
        if (root->left == NULL && root->right != NULL)
        {
            temp = root;
            root = root->right;
            free(temp);
            printf("Deleted Element = %d\n", x);
            return;
        }
    }

    // Leaf node
    if (p->left == NULL && p->right == NULL)
    {
        if (p1->left == p)
            p1->left = NULL;
        else
            p1->right = NULL;

        printf("Deleted Element = %d\n", p->data);
        free(p);
    }

    // Node with only left child
    else if (p->left != NULL && p->right == NULL)
    {
        if (p1->left == p)
            p1->left = p->left;
        else
            p1->right = p->left;

        printf("Deleted Element = %d\n", p->data);
        free(p);
    }

    // Node with only right child
    else if (p->left == NULL && p->right != NULL)
    {
        if (p1->left == p)
            p1->left = p->right;
        else
            p1->right = p->right;

        printf("Deleted Element = %d\n", p->data);
        free(p);
    }

    // Node with two children
    else
    {
        struct node *q = p->right;
        struct node *q1 = p;

        while (q->left != NULL)
        {
            q1 = q;
            q = q->left;
        }

        p->data = q->data;

        if (q1->left == q)
            q1->left = q->right;
        else
            q1->right = q->right;

        free(q);
    }
}

int main()
{
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    printf("Inorder : ");
    inorder(root);

    printf("\nPreorder : ");
    preorder(root);

    printf("\nPostorder : ");
    postorder(root);

    search(40);

    deletion(70);

    printf("Inorder after deleting 70 : ");
    inorder(root);

    printf("\n");
}