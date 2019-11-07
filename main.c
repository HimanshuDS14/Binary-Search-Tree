#include<stdio.h>

struct node
{
    int data;
    struct node *left ,*right;
};

struct node*create_node(int value)
{

    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->right = NULL;
    temp->left = NULL;
    return(temp);
};

struct node*insert(struct node*root , int value)
{
    if(root==NULL)
    {
        return(create_node(value));
    }
    else if(value > root->data)
    {
        root->right = insert(root->right , value);
    }
    else
    {
        root->left = insert(root->left ,value);
    }
    return(root);
};

void inorder(struct node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d " , root->data);
        inorder(root->right);
    }
}

void preorder(struct node*root)
{
    if(root!=NULL)
    {
        printf("%d " , root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf( "%d " , root->data);
    }
}

struct node*find_Minimun(struct node*root)
{
    if(root==NULL)
    {
        return(NULL);
    }
    else if(root->left!=NULL)
    {
        return find_Minimun(root->left);

    }
    else
        return(root);
};

struct node*delete_node(struct node*root , int value)
{
    if(root==NULL)
    {
        return(NULL);

    }

    if(value > root->data)
    {
        root->right = delete_node(root->right , value);
    }
    else if(value < root->data)
    {
        root->left = delete_node(root->left , value);
    }
    else
    {
        //No children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return(NULL);
        }
        //one child
        else if(root->left==NULL || root->right==NULL)
        {
            struct node*temp;

            if(root->left==NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }
            free(root);
            return(temp);


        }

        else
        {
            struct node*temp;
            temp = find_Minimun(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right , temp->data);


        }
    }
    return(root);
};


struct node*find_value(struct node*root , int value)
{
    if(root==NULL)
    {
        return(-1);
    }

    if(value > root->data)
    {
        return(find_value(root->right , value));
    }
    else if(value < root->data)
    {
        return(find_value(root->left , value));
    }
    else
        return(root);
};



int main()
{
    int ch , value;
    struct node*root;
    struct node*m;
    printf("Enter a root value : ");
    scanf("%d" , &value);
    root = create_node(value);

    while(1)
    {
        printf("1 Insert\n");
        printf("2 Find Minimum value\n");
        printf("3 Delete Node \n");
        printf("4 Find Value\n");
        printf("Enter your choice : ");
        scanf("%d" , &ch);

        switch(ch)
        {
        case 1:

            printf("Enter a value : ");
            scanf("%d" , &value);
            insert(root , value);
            printf("InOrder Traverse :  ");
            inorder(root);
            printf("\n");
            printf("PreOrder Traverse : ");
            preorder( root);
            printf("\n");
            printf("PostOrder Traverse :  ");
            postorder( root);
            printf("\n\n");
            break;
        case 2:
            m = find_Minimun(root);
            printf("%d" , m->data);
            printf("\n\n");
            break;

        case 3:
            printf("Enter a value : ");
            scanf("%d" , &value);
            struct node*d;

            delete_node(root , value);

            inorder(root);
            printf("\n\n");
            break;

        case 4:
            printf("Enter a value which you want a search : ");
            scanf("%d" , &value);
            struct node*f;
            f = find_value(root , value);
            if(f==-1)
                printf("Value Not Present in a tree");
            else
                printf("Value present in a tree");
            printf("\n\n");
            break;

        }
    }



}

