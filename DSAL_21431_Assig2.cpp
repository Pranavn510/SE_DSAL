#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(){
        left=NULL;
        right=NULL;
        data=0;
    }
    node(int data){
        left=NULL;
        right=NULL;
        this->data=data;
    }
};

class binaryTree{
public:
    node *root;
    queue <node *> q;

    binaryTree(){
    root=NULL;
    }

    void  insertnode(node * &root,int val){

    node *temp=new node(val);
    if(root==NULL){
        root=temp;
    }
    else if(q.front()->left==NULL){
        q.front()->left=temp;
    }
    else if(q.front()->right==NULL){
        q.front()->right=temp;
        q.pop();
    }
    q.push(temp);
}

void create(node *&root){
    int n;
    cout<<"enter the no of nodes ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cout<<"Enter The Node value.";
        cin>>num;
        insertnode(root,num);
    }
    }
    //Traversals
    void Preorder(node *&root)
    {
        if (root==NULL)
    {
        return;
    }

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void NonRecursivePreorder(node *root)
    {

        if (root == NULL)
        {
            return;
        }
        stack<node *> st;
        st.push(root);

        while (!st.empty())
        {
            root = st.top();
            st.pop();
            cout << root->data << " ";

            if (root->right != NULL)
            {
                st.push(root->right);
            }
            if (root->left != NULL)
            {
                st.push(root->left);
            }
        }
    }

void Inorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder(node *&root)
{
    if(root==NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void nonRecursivePostorder(node *root)
    {

        stack<node *> st1, st2;

        if (root == NULL)
        {
            return;
        }
        st1.push(root);
        while (!st1.empty())
        {
            root = st1.top();
            st1.pop();

            st2.push(root);
            if (root->left != NULL)
            {
                st1.push(root->left);
            }
            if (root->right != NULL)
            {
                st1.push(root->right);
            }
        }
        while (!st2.empty())
        {
            root = st2.top();
            st2.pop();
            cout << root->data << " ";
        }
    }



int height(node *&root){
    if(root==NULL){
        return 0;
    }
    else{
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left,right) + 1;
        return ans;
    }
}

void swapnode(node *&root){
    if(root==NULL){
        return ;
    }
    else{
    swap(root->left , root->right);
    swapnode(root->left);
    swapnode(root->right);
    }
}

    void NonRecursiveInorder(node *root)
    {
        stack<node *> st;
        node *temp = root;
        while (!st.empty() || temp != NULL)
        {
            if (temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = st.top();
                cout << temp->data << " ";
                st.pop();
                temp = temp->right;
            }
        }
    }


void traversal(node *&root , int &count){
    if(root == NULL){
        return ;
    }
    else{
        traversal(root->left, count);
        if(root->left == NULL && root->right == NULL){
        count++;
        }
        traversal(root->right, count);
    }
}

int noLeaves(node *&root){
    int cnt = 0;
    traversal(root , cnt);
    return cnt;
}

int countIntNodes(node *&root){
    int count ;
    if(root == NULL || (root->left==NULL && root->right == NULL)){
        return 0;
    }
    countIntNodes(root->left);
    countIntNodes(root->right);
    count = 1 + countIntNodes(root->left) + countIntNodes(root->right);
    return count;
}

node *makeCopy(node *&root)
    {
    	node *newRoot = new node(root->data);
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            newRoot->left = makeCopy(root->left);
            newRoot->right = makeCopy(root->right);
            return newRoot;
        }
        Postorder(newRoot);
    }

    void erase(node *&root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            erase(root->left);
            erase(root->right);
            free(root);
        }
    }

};


int main(){
    binaryTree bt;
    node *root = NULL;

    cout<<"<------------MENU--------------->"<<endl;
    cout<<"Enter 1 for creating Binary tree."<<endl;
    cout<<"Enter 2 for displaying Binary tree."<<endl;
    cout <<"Enter 3 for swapping elements in the tree "<<endl;
    cout<<"Enter 4 for displaying Height of tree."<<endl;
    cout <<"Enter 5 for Copy this tree to another [operator=] "<< endl;
    cout<<"Enter 6 for displaying number of leaves "<<endl;
    cout<<"Enter 7 for displaying number of internal nodes"<<endl;
    cout<<"Enter 8 to earse all nodes in binary tree"<<endl;
    cout<<"Enter 9 to EXIST"<<endl;


    while(true){
    int choice;
    cout<<"Enter the choice:- ";
    cin>>choice;
    if(choice == 1){
    bt.create(root);
    }
    else if(choice == 2){
    cout<<"Inorder Traversal: ";
    bt.Inorder(root);
    cout<<endl;
    cout<<"Inorder Traversal using nonrecurssion: ";
    bt.NonRecursiveInorder(root);
    cout<<endl;
    cout<<"Preorder Traversal: ";
    bt.Preorder(root);
    cout<<endl;
    cout<<"Preorder Traversal using nonrecurssion:  ";
    bt.NonRecursivePreorder(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    bt.Postorder(root);
    cout<<endl;
    cout<<"Postorder Traversal using nonrecurssion:  ";
    bt.nonRecursivePostorder(root);
    cout<<endl;
    }
    else if(choice ==3)
    {
        bt.swapnode(root);
        cout<<"Nodes are swaped successfully!!"<<endl;
    }
    else if(choice == 4){
    cout<<"The height of the given tree is: "<<bt.height(root)<<endl;
    }
    else if(choice == 5){
        bt.makeCopy(root);
        cout<<"Tree copied successfully"<<endl;
    }
    else if(choice == 6){
        cout<<"Number of leaves of the tree: "<<bt.noLeaves(root)<<endl;
    }
    else if(choice == 7){
        cout<<"Number of internal nodes of the tree is: "<<bt.countIntNodes(root)<<endl;
    }
    else if(choice == 8){
        bt.erase(root);
        cout<<"Earsed all nodes!!"<<endl;
    }
    else if(choice == 9){
        break;
    }
    else{
        cout<<"Enter proper choice!!";
    }
    }
}
