#include<stdio.h>
#include<stdlib.h>

typedef struct BT* Node;

typedef struct BT{
    int data;
    Node Rchild, Lchild;
}BT;

Node getnode(){
    Node temp = (Node)malloc(sizeof(BT));
    return temp;
}

// void insert(Node* root,int val){
//     Node head = *root;
//     Node temp = getnode();
//     Node parent = NULL;

//     temp->data = val;
//     temp->Rchild = temp->Lchild = NULL;
//     if(head == NULL){
//         head = temp;
//         *root = head;
//         return;
//     }
//     while(head != NULL){
//         parent = head;
//         if(val > head->data){
//             head = head->Rchild;
//         }
//         else{
//             head = head->Lchild;
//         }
//     }
//     if(val > parent->data){
//         parent->Rchild = temp;
//     }
//     else{
//         parent->Lchild = temp;
//     }
//     return;
// }

void create_BT(Node* root){
    int x,option;
    Node temp;
    Node prev = NULL;
    if(!(*root)){
        temp = getnode();
        printf("Enter the value of root: ");
        scanf("%d",&x);
        temp->data = x;
        temp->Rchild = temp->Lchild = NULL;
        *root = temp;
        prev = *root;
    }
    Node curr = *root;
    printf("1.Go Left\n2.Go Right\n3.Go back\n4.Go to root\n5.Exit\nEnter option: ");
    scanf("%d",&option);
    while(option != 5){
        if(option == 1){
            prev = curr;
            temp = getnode();
            printf("Enter the value of left child:");
            scanf("%d",&x);
            temp->data = x;
            temp->Rchild = temp->Lchild = NULL;
            curr->Lchild = temp;
            curr = curr->Lchild;
        }
        else if(option == 2){
            prev = curr;
            temp = getnode();
            printf("Enter the value of right child:");
            scanf("%d",&x);
            temp->data = x;
            temp->Rchild = temp->Lchild = NULL;
            curr->Rchild = temp;
            curr = curr->Rchild;
        }
        else if(option == 3){
            curr = prev;
        }
        else if(option == 4){
            curr = *root;
        }
        else{
            return;
        }
        printf("Enter option: ");
        scanf("%d",&option);
    }
}

void inorder(Node root){
    if(root){
        inorder(root->Lchild);
        printf("%d ",root->data);
        inorder(root->Rchild);
    }
}

void preorder(Node root){
    if(root){
        printf("%d ",root->data);
        preorder(root->Lchild);
        preorder(root->Rchild);
    }
}

void postorder(Node root){
    if(root){
        postorder(root->Lchild);
        postorder(root->Rchild);
        printf("%d ",root->data);
    }
}

int main(){
    Node Tree = NULL;
    create_BT(&Tree);
    printf("Inorder : ");
    inorder(Tree);
    printf("\nPreorder : ");
    preorder(Tree);
    printf("\nPostorder : ");
    postorder(Tree);
}

/*
                3
             /    \
            1       4  
             \        \ 
                2       5

inorder: 1 2 3 4 5
preorder: 3 1 2 4 5
postorder: 2 1 5 4 3

*/


