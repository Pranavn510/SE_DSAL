#include<iostream>
using namespace std;
class node{

    private:
    string key,value;
    node* next;


    public:
    friend class hashmap;

    node(){
        key ="_ _ _";
        value ="_ _ _";
        next = NULL;
    }

    node(string key,string value){
        this->key=key;
        this->value=value;
        next=NULL;

    }

};

class hashmap{

    private:
    int size;
    node** arr;

    public:
    hashmap(int size){
        this->size=size;
        arr = new node*[size];
        for(int i=0;i<size;i++){
            arr[i]=NULL;
        }



    }

    int hashfn(string key){
        int sum=0;
        for(int i=0;i<key.size();i++){
            sum+= int(key[i]);
        }
        return sum % size;

    }


    void insert(string key,string value){

        int index=hashfn(key);
        node *newNode;
        newNode  =new node(key,value);
        if(arr[index]==NULL){
            arr[index]=newNode;
            cout<<"Insertion completed"<<endl;
        }
        else{
            node* temp =arr[index];
            newNode->next=temp;
            arr[index]=newNode;
            cout<<"Insertion completed"<<endl;
        }

    }

    void display(){
        for(int i=0;i<size;i++){
            if(arr[i]!=NULL){
                node* temp=arr[i];
                while(temp->next!=NULL){
                    cout<<temp->key<<" : "<<temp->value<<" ---> ";
                    temp=temp->next;
                }
                cout<<temp->key<<" : "<<temp->value<<" ---> ";
                cout<<"END"<<endl;

            }
            else{
                cout<<"_ _ _"<<" :"<<"_ _ _"<<endl;
            }

        }
    }
    void search(string key){
        bool flag=false;
        int index=hashfn(key);
        if(arr[index]!=NULL){
            if(arr[index]->key==key){
                cout<<"Element found"<<endl;
                return;
            }
            else{
                node* temp = arr[index];
                while(temp->next!=NULL){
                    if(temp->key==key){
                        flag=true;
                        break;
                    }
                    temp=temp->next;
                }
                if(temp->key==key){
                    flag=true;
                }
                if(flag){
                    cout<<"Element found"<<endl;

                }
                else{
                    cout<<"Element not found"<<endl;
                }
            }
        }
        else{
            cout<<"Element not found"<<endl;
        }
    }

    void deletenode(string key){
        bool flag=false;
        int index=hashfn(key);
        if(arr[index]!=NULL){
            node* temp=arr[index];
            if(arr[index]->key==key){
                cout<<"Element deleted"<<endl;
                arr[index]=NULL;
                arr[index]=temp->next;
                return;
            }
            else{
                node* prev=NULL;
                while(temp->next!=NULL){
                    if(temp->key==key){
                        cout<<"Element deleted"<<endl;
                        prev->next=temp->next;
                        delete temp;
                        return;
                    }
                    prev=temp;
                    temp=temp->next;
                }
                if(temp->key==key){
                    cout<<"Element deleted"<<endl;
                    prev->next=temp->next;
                    delete temp;
                    }
                else{
                    cout<<"No such element is present"<<endl;
                }
            }

    }

    else{
        cout<<"No such element is present"<<endl;
        }

    }




};
int main(){

    hashmap h(10);
    int n;
    while(true){
        cout<<"____________MENU_____________"<<endl;
        cout<<"Enter 1 to insert data!"<<endl;
        cout<<"Enter 2 to delete a node!"<<endl;
        cout<<"Enter 3 to search a node!"<<endl;
        cout<<"Enter 4 to display the records"<<endl;
        cout<<"Enter 5 to EXIT!"<<endl;
        cout<<"Enter your choice over here-> ";
        cin>>n;
        if(n==1){
            int ch;
            cout<<"Please enter the number of data to be inserted -> ";
            cin>>ch;
            while(ch--){
                string word,meaning;
                cout<<"Please enter the word-> ";
                cin>>word;
                cout<<"Please enter it's meaning-> ";
                cin>>meaning;
                h.insert(word,meaning);
            }

        }

        else if(n==2){
            string word;
            cout<<"Please enter the word to be deleted-> ";
            cin>>word;
            h.deletenode(word);
        }
        else if(n==3){
            string word;
            cout<<"Please enter the word to be searched-> ";
            cin>>word;
            h.search(word);

        }
        else if(n==4){
            cout<<"WORD "<<"   "<<"MEANING"<<endl;
            h.display();
        }
        else if(n==5){
            cout<<"Thank You for using the program!"<<endl;
            break;
        }
        else{
            cout<<"Please enter a valid option from the above menu!!!"<<endl;
        }

    }


    return 0;
}
