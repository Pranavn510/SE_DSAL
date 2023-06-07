#include <bits/stdc++.h>
using namespace std ;

struct Node {
    int key ;
    string value ;
    int height = 1 ;
    Node* left = nullptr ;
    Node* right = nullptr ;
};


class AVLTree {

    Node* root = nullptr ;

    int nodeBalanceFactor( Node* node ) {
        if( node == nullptr ) {
            return 0 ;
        }
        return nodeHeight( node -> left ) - nodeHeight( node -> right ) ;
    }

    int nodeHeight( Node *node ) {
        if( node == nullptr ) {
            return 0;
        }
        return node -> height ;
    }

    void updateHeight( Node* node ) {
        node -> height = 1 + max( nodeHeight( node -> left ) , nodeHeight( node -> right ) )  ;
    }

    Node* LLRotation( Node *node ) {
        Node *newRoot = node->left;
        newRoot->right = node;
        node->left = nullptr;

        updateHeight( node );
        updateHeight( newRoot );

        return newRoot;
    }

    Node* RRRotation( Node *node ) {
        Node *newRoot = node->right;
        newRoot->left = node;
        node->right = nullptr;

        updateHeight( node );
        updateHeight( newRoot );

        return newRoot;
    }

    Node* RLRotation( Node* node ) {
        node -> right = LLRotation( node -> right ) ;
        return RRRotation( node ) ;
    }

    Node* LRRotation( Node* node ) {
        node -> left = RRRotation( node -> left ) ;
        return LLRotation( node ) ;
    }

    Node* balance( Node* node ) {
        if( nodeBalanceFactor( node ) == 2 ) {
            if( nodeBalanceFactor( node -> left ) < 0 )
                node = LRRotation( node ) ;
            else
                node = LLRotation( node ) ;
        }
        else if( nodeBalanceFactor( node ) == -2 )  {
                if( nodeBalanceFactor( node -> right ) > 0 )
                    node =RLRotation( node ) ;
                else
                    node = RRRotation( node ) ;
        }
        updateHeight( node ) ;
        return node ;
    }

    void iinorder( Node *root ) {
        if( root == nullptr )
            return;
        iinorder( root->left );
        cout<< root->key <<" ";
        iinorder( root->right );
    }

    void preorder(Node* root){
    	if(root==NULL) return;
    	cout<<root->key<<endl;
    	preorder(root->left);
    	preorder(root->right);
    }
    Node* insertSubTree( Node* curr , int key , string value ) {
        if( curr == nullptr ) {
            Node* newNode = new Node() ;
            newNode -> key = key ;
            newNode -> value = value ;
            return newNode ;
        }
        if( curr -> key > key ) {
            curr -> left = insertSubTree( curr -> left , key , value ) ;
        }
        else if( curr -> key < key ) {
            curr -> right = insertSubTree( curr -> right , key , value ) ;
        }
        else {
            curr -> value = value ;
            return curr ;
        }
        return balance( curr ) ;
    }

public:

    void insert( int key, string value ) {
        root = insertSubTree( root, key, value);
    }

    void display() {
        cout<< "\nInorder: " <<endl;
        iinorder( root );
        cout<<endl;

        cout<<"\nPreorder: "<<endl;
        preorder(root);
        cout<<endl;
    }

    Node* search( int key ) {
        Node *curr = root;
        while( curr != nullptr ) {
            if( key > curr->key )
                curr = curr->right;
            else if( key < curr->key )
                curr = curr->left;
            else
                return curr;
        }
        return nullptr;
    }

};

int main() {
    AVLTree tree;

    while(true){
    	cout<<"1. insert node in AVL"<<endl;
    	cout<<"2. display AVL"<<endl;
    	cout<<"3. search in AVL"<<endl;
    	cout<<"4. Exit"<<endl;
    	int res;
    	cout<<"Enter your response : ";
    	cin>>res;
    	if(res==1){
    		int k;
    		string v;
    		cout<<"Enter key : ";
    		cin>>k;
    		cout<<"Enter value : ";
    		cin>>v;
    		tree.insert(k,v);
    	}
    	else if(res==2){
    		tree.display();
    	}
    	else if(res==3){
    		int k;
    		cout<<"Enter key : ";
    		cin>>k;
    		if(tree.search(k)) cout<<k<<" is present in AVl"<<endl;
    		else cout<<k<< " not found"<<endl;
    	}
    	else if(res==4) break;
    	else continue;
    }

    return 0;
}
