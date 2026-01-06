#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    struct Node* right;
    struct Node* left;
}Node;
// function declaration
int getMinValue(Node*);

// create a new node
Node* getNewNode(int value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = value;
    node->left = NULL;
    node->right = NULL;

    return node; 
}
// insert a node
Node* insert(Node* root, int value){
    if(root == NULL){
        return getNewNode(value);
    }
    if(value < root->key){
        root->left = insert(root->left,value);
    }
    else{
        root->right = insert(root->right,value);
    }

    return root;
}


// preorder traversal
void preOrder(Node* root){
    if(root == NULL) return;
    //print root
    printf("%d ", root->key);
    // traverse left subtree
    preOrder(root->left);
    // traverse right subtree
    preOrder(root->right);
}
// inorder traversal
void inOrder(Node* root){
    if(root == NULL) return;
    // traverse left subtree recursively
    inOrder(root->left);
    // print root node
    printf("%d ",root->key);
    // traverse right subtree recursively
    inOrder(root->right);
}
// postorder traversal
void postOrder(Node* root){
    if(root == NULL) return;
    //traverse left subtree
    postOrder(root->left);
    //traverse right subtree
    postOrder(root->right);
    //print root
    printf("%d ",root->key);
}

// deleteNode node
Node* deleteNode(Node* root, int value){
    if(root == NULL) return NULL;
    // find the node
    if(value < root->key ){
        root->left = deleteNode(root->left,value);
    }
    else if(value > root->key){
        root->right = deleteNode(root->right, value);
    }
    // actual deletion
    else{
        //leaf node
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }// single child
        else if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // have both child
        else{
            int minVal = getMinValue(root->right);
            root->key = minVal;
            root->right = deleteNode(root->right, minVal);
        }
    }
    return root;
}
int getMinValue(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->key;
}

// search a value in BST
Node* search(Node* root, int value){
    if(root == NULL) return NULL;

    if(value == root->key){
        return root;
    }
    else if(value < root->key){
        return search(root->left,value);
    }
    else{
        return search(root->right, value);
    }
}

int main(){
    Node* root = NULL;
    inOrder(root);
    root = insert(root, 22);
    root = insert(root, 14);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root,11);
    root = insert(root,15);
    printf("\n Inorder traversal: ");
    inOrder(root);
    printf("\n preorder traversal: ");
    preOrder(root);
    printf("\n Postorder traversal: ");
    postOrder(root);

    root = deleteNode(root,14);
    printf("\n Inorder traversal: ");
    inOrder(root);
    // search 
    int val = 10;
    Node* node = search(root,val);
    if(node == NULL){
        printf("\n Element not found.");
    }
    else{
        printf("\n Element found: %d \n",node->key);
    }
    return 0;
}