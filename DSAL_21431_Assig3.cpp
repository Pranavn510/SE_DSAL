#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;node* right;
	bool lth;bool rth;



	node(int data){
		this->data=data;
		left=right=NULL;
		lth=true;
		rth=true;
	}

	friend class tbst;
};

class tbst{

public:
	node* root;

	tbst(){
		root=NULL;
	}

	node* insert(node* &root ,int val){


		if(root==NULL){
			node* temp=new node(val);
			root=temp;
			return root;
		}
		node* curr=root;
		while(curr!=NULL){
			if(val < curr->data){
				if(curr->lth){
					node* temp=new node(val);
					temp->left = curr->left;
					temp->right = curr;
					curr->lth = false;
					curr->left = temp;
					return root;
				}
				curr=curr->left;
			}
			else if(val > curr->data){
				if(curr->rth){
					node* temp=new node(val);
					temp->right=curr->right;
					temp->left=curr;
					curr->rth=false;
					curr->right=temp;
					return root;
				}
				curr=curr->right;
			}
			else{
				return root;
			}
		}
	}

	node* succesor(node* ptr){
		if(ptr->rth){
			return ptr->right;
		}
		else{
			ptr =ptr->right;
			while(ptr->lth==false){
				ptr=ptr->left;
			}
			return ptr;
		}
	}

	node* predesor(node* ptr){
			if(ptr->lth){
				return ptr->left;
			}
			else{
				ptr =ptr->left;
				while(ptr->rth==false){
					ptr=ptr->right;
				}
				return ptr;
			}
	}

	node *leftMost(node *&root){
		
    	if (root == NULL)
        	return NULL;
 
    	while (root->left != NULL)
        	root = root->left;

    	return root;
		
	}

	void inorder(node* root) {
	    if (root == NULL)
	        return;

	    node* temp = root;
	    while (!temp->lth)
	        temp = temp->left;

	    while (temp != NULL) {
	        cout << temp->data << " ";

	        if (!temp->rth)
	            temp = temp->right;
	        else {
	            temp = temp->right;
	            while (temp != NULL && temp->lth)
	                temp = temp->left;
	        }
	    }
	    cout << endl;
	}

	void preorder(node* root){
    	if(root==NULL) return;
    	node* temp=root;
    	while(temp!=NULL){
    		cout<<temp->data<<" ";
    		if(temp->lth==false)
    			temp=temp->left;
    		else if(temp->rth==false)
    			temp=temp->right;
    		else{
    			while(temp!=NULL && temp->rth==true)
    				temp=temp->right;
    			if(temp!=NULL)
    				temp=temp->right;
    		}
    	}
    	cout<<endl;
    }


    void deletion(int key){
    	node* temp=root;
        node* parent=NULL;
       	while(temp!=NULL){
       		if(key==temp->data){
    			break;
    	    }
    	    parent=temp;
    	    if(key<temp->data){
    	    	if(temp->lth==false) temp=temp->left;
    	    	else break;
    	    }
    	    else{
    	    	if(temp->rth==false) temp=temp->right;
    	    	else break;
    	    }
        }
       	if(key!=temp->data){
       		cout<<key<<" not found"<<endl;
       		return;
       	}
       	else if (temp->lth == true && temp->rth == true){
       		if (parent == NULL)
       		    root = NULL;

       		else if (temp == parent->left) {
       		   	parent->lth = true;
       		    parent->left = temp->left;
       		}
       		else {
       		    parent->rth = true;
       		    parent->right = temp->right;
       		}
       		delete temp;
           	// cout<<key<<" Successfully deleted"<<endl;
           	return;
       	}
       	else if((temp->lth==true && temp->rth==false) || (temp->lth==false && temp->rth==true)){
       		node* child;
       		if(temp->lth==false)
       			child=temp->left;
       		else
       			child=temp->right;
       		if(parent==NULL){
       			root=child;
       		}
       		if(temp==parent->left){
       			parent->left=child;
       		}
       		else parent->right=child;
       		node* s=succesor(temp);
       		node* p=predesor(temp);

       		if(temp->lth==false){
       			p->right=s;
       		}
       		else{
       			s->left=p;
       		}
       		delete temp;
           	cout<<key<<" Successfully deleted"<<endl;
           	return;
       	}
       	else{

       		node* s=succesor(temp);
       		int t=s->data;
            deletion(s->data);
       	   	temp->data=t;
       	}
    }

};


int main() {

	tbst o;
	while (true)
	    {
	        cout << endl;
	        cout << "-------------MENU--------------------" << endl;
	        cout << "Enter 1 for creating the TBST " << endl;
	        cout << "Enter 2 for Displaying the TBST " << endl;
	        cout << "Enter 3 for Deleting node in TBST " << endl;
	        cout << "Enter 4 for EXIT !! " << endl;
	        cout << endl;
	        int n;
	        cout << "Enter your choice : ";
	        cin >> n;
	        if (n == 1)
	        {
                cout<<"Enter the no. of elements in TBST : ";int n;cin>>n;
                for(int i=0;i<n;i++){
                    int x;cout<<"Enter the data : ";cin>>x;
                    o.insert(o.root,x);
                }

	        }
	        else if (n == 2)
	        {
	            cout << "Inorder traversal : ";
	            o.inorder(o.root);
	            cout << endl;
	            cout << "preorder traversal : ";
	            o.preorder(o.root);
	            cout << endl;
	        }
	        else if (n == 3)
	        {
	        	cout << "Enter element for deleting : ";
	        	int ele;
	        	cin >> ele;
	        	o.deletion(ele);
	        }
	        else if (n == 4)
	        {
	            cout << " ---Thanks for using the program --- " << endl;
	            break;
	        }
	        else
	        {
	            cout << "---Enter the correct choice---" << endl;
	        }
	    }

	return 0;
}