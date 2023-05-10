#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        this->data = d;
        left = NULL;
        right = NULL;
    }
};



node *buildTree(node *&root, int d){
    if (root == NULL)
        {
            root = new node(d);
            return root;
        }

        if (d < root->data)
        {
            root->left = buildTree(root->left, d);
        }
        else
        {
            root->right = buildTree(root->right, d);
        }
        return root;
}

void take_inp(node *&root ){
    cout<<"Enter the number of nodes to enter:- ";
    int n,d;
    cin>>n;
    for(int i = 0;i<n;i++){
        cout<<"Enter the data: "<<endl;
        cin>>d;
        buildTree(root,d);
    }
}

void Inorder(node *&root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(node *&root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(node *&root){
    if(root == NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
void search(node *&root , int key){
    if(root==NULL){
        cout<<"Not Present!!"<<endl;
        return;
    }
    if(root->data == key){
        cout<<"Present"<<endl;
        return;
    }
    else{
        if(key>root->data){
            search(root->right,key);
        }
        else{
            search(root->left,key);
        }
    
    }    
}

void minValue(node *&root){
    node *temp = root;
    while(temp->left!=NULL){
        temp= temp->left;
    }
    cout<<"The min value is: "<<temp->data<<endl;
}
void maxValue(node *&root){
    node *temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    cout<<"The max value is: "<<temp->data<<endl;
}
void swap(node *&root){
    if(root==NULL){
        return;
    }
    else{
        swap(root->left , root->right);
        swap(root->left);
        swap(root->right);
    }
}

int height(node *&root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(right,left) + 1;
    return ans;
}
int Longest_path(node *&root){
    if(root == NULL){
        return 0;
    }
    int op1 = Longest_path(root->left);
    int op2 = Longest_path(root->right);
    int op3 = height(root->left) + 1 + height(root->right);

    int op4 = max(op1,max(op2,op3));
    return op4;
}
node *minValueRight(node *&root)
    {
        node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

node* deleting(node *&root, int x)
    {
        if (root == NULL)
        {
            cout << "Element is not present..." << endl;
            return root;
        }
        else if (x < root->data)
        {
            root->left = deleting(root->left, x);
        }
        else if (root->data < x)
        {
            root->right = deleting(root->right, x);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                int min = minValueRight(root->right)->data;
                root->data = min;
                root->right = deleting(root->right, min);
                return root;
            }
        }
        return root;
    }


int main(){
    node *root = NULL;
    cout << "-------------MENU--------------------" << endl;
    cout << "Enter 1 for creating the BST " << endl;
    cout << "Enter 2 for Displaying the BST " << endl;
    cout << "Enter 3 for finding min and max value in the BST " << endl;
    cout << "Enter 4 for searching in the BST " << endl;
    cout << "Enter 5 for no. of nodes in longest path of BST " << endl;
    cout << "Enter 6 for deleting element in the BST " << endl;
    cout << "Enter 7 for swapping elements in the BST " << endl;
    cout << "Enter 8 for EXIT !! " << endl;
    cout << endl;
    
    
    
    while(true){
        int n;
        cout<<"Enter your choice: "<<endl;
        cin>>n;
        if(n==1){
            
            take_inp(root);
        }
        else if(n==2){
            cout<<"Inorder traversal: ";
            Inorder(root);
            cout<<endl;
            cout<<"Preorder traversal: ";
            Preorder(root);
            cout<<endl;
            cout<<"Postorder traversal:  ";
            Postorder(root);
            cout<<endl;
        }
        else if(n==4){
            int key;
            cout<<"Enter the key to search: "<<endl;
            cin>>key;
            search(root,key);
        }
        else if(n==3){
            minValue(root);
            maxValue(root);
        }
        else if(n==7){
            cout<<endl;
            swap(root);
        }
        else if(n==5){
            cout<<"The number of nodes in the longest path is: "<<endl;
            Longest_path(root);
        }
        else if(n==6){
            cout<<"Enter the element for deleting:- ";
            int ele;
            cin>>ele;
            deleting(root,ele);
        }
        else if(n==8){
            cout<<"Thank you for using the program!!"<<endl;
            break;
        }
        else{
            cout<<"Please enter the proper choice!!"<<endl;
        }
    }
    }



