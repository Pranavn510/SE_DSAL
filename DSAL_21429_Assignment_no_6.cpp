

//============================================================================
// Name        : DSAL_21429_Assignment_no_6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
class graph;
class node{
     int ver;
     int weight;
     node *next;
     friend class graph;

     node(){
    	 ver=0;
    	 weight=0;
    	 next=NULL;
     }
     node(int ver, int weight){
    	 this->ver=ver;
    	 this->weight=weight;
    	 next=NULL;
     }
     node(int ver){
    	 this->ver=ver;
    	 next=NULL;
     }


};

class graph{
public:
	int vertices;
	node **adjList;
	int *visited;

	graph(){
		cout<<"Enter The No of Vertices.:- ";
		cin>>this->vertices;
		adjList= new node*[vertices];
        visited=new int[vertices];

		for(int i=0;i<this->vertices;i++){
			adjList[i]=NULL;
			visited[i]=0;
		};
	}

	void disp(){
		for(int i=0;i<this->vertices;i++){
			cout<<i<<"\t";
			if(adjList[i]){
				node* temp=adjList[i];
				while(temp){

				cout<<temp->ver<<"-"<<temp->weight<<"  ->--->-  ";
				temp=temp->next;

				}
				cout<<endl;
			}
			else{
				cout<<"----"<<endl;
			}
		}
	}
	  void deletevisited(){
			for(int i=0;i<this->vertices;i++){
				visited[i]=0;
			}}

	       int countVisited(){
	    	   int count=0;
	    	   for(int i=0;i<this->vertices;i++){
	    	   			if(visited[i]==1){
	    	   				count++;
	    	   			}
	    	   		}

	    	   return count;
	       }
	void insert(int src,int ver,int w){
	    node *nn= new node(ver,w);
		node *temp=adjList[src];
		if(temp!=NULL){
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=nn;
		}
		else{
			adjList[src]=nn;
		}
	}
	void createUndirected(){
		int edges;
		cout<<"Enter The No of Edges in UnDirected Graph ";
		cin>>edges;

		for(int i=0;i<edges;i++){
			int ver1,ver2,w;
			cout<<"Enter The Vetex 1 of edge";
			cin>>ver1;
			cout<<"Enter The Vertex 2 of the edge ";
			cin>>ver2;
			cout<<"Enter The Weight of the Edge.";
			cin>>w;
			insert(ver1,ver2,w);
			insert(ver2,ver1,w);
		}
	}

	void createDirected(){
		int edges;
		cout<<"Enter The No of Edges in Directed Graph ";
		cin>>edges;

	    for(int i=0;i<edges;i++){
		int src,ver,w;
		cout<<"Enter The Source Vetex  of edge";
		cin>>src;
		cout<<"Enter The Destination Vertex  of the edge ";
		cin>>ver;
		cout<<"Enter The Weight of the Edge.";
		cin>>w;
		insert(src,ver,w);

		}
	}
	void  Degree(int ver){
			node *temp=adjList[ver];



				int outcount=0;
				while(temp){
					outcount++;
					temp=temp->next;
				}
				cout<<"The OutDegree of "<<ver<<" is "<<outcount<<endl;

				int incount=0;
				for(int i=0;i<vertices;i++){
					node* temp=adjList[i];
					while(temp){
						if(temp->ver==ver){
							incount++;
						}
					temp=temp->next;
					}
				}
				cout<<"The INDegree of "<<ver<<" is "<<incount<<endl;


		}

	void dfsTaversal_Iterative(int start){
		stack <node*> st;

		node *fst=new node(start);

		st.push(fst);
		visited[start]=1;
		while(!st.empty()){
			node* vert=st.top();
			cout<<vert->ver<<" ";
			st.pop();

			if(adjList[vert->ver]!=NULL){
				node *temp=adjList[vert->ver];
				while(temp){
					if(visited[temp->ver]==0){
						st.push(temp);
						visited[temp->ver]=1;
					}
					temp=temp->next;
				}
			}
		}


		for(int i=0;i<this->vertices;i++){
			visited[i]=0;
		}

	}

	 void bfsTraversal_Iterative(int s){
		 node *start=new node(s);
		 queue <node*>Q;
		 Q.push(start);
		 visited[s]=1;

		 while(!Q.empty()){
			 node* vert=Q.front();
			 cout<<vert->ver<<" ";
			 Q.pop();

			 if(adjList[vert->ver]!=NULL){
			 node *temp=adjList[vert->ver];
			 while(temp){
			 	if(visited[temp->ver]==0){
			 		Q.push(temp);
			        visited[temp->ver]=1;
			 		}
			 	temp=temp->next;
			 	}
			}
		 }
		 for(int i=0;i<this->vertices;i++){
		 			visited[i]=0;
		 		}
	 }
	 bool isStrongly(){
	 		 bool flag=true;

	 		 for(int i=0;i<vertices;i++){
	 			 dfsTaversal_Iterative(adjList[i]->ver);
	 			 if(countVisited()!=vertices){
	 				  flag=false;
	 				  break;
	 			 }
	 		 }
	 		 deletevisited();

	 		 if(flag){
	 			 return true;
	 		 }
	 		 else{
	 			 return false;
	 		 }
	 	 }


};
	 bool isDisconnected( node **Gph ,int vertices){
		bool flag=false;

		for(int i=0;i<vertices;i++){
			if(Gph[i]==NULL){
				flag=true;
			}
		}
		return flag;
	 }




int main() {


     graph g1;
     int choice ;
         cout<<"-----------MENU-----------------"<<endl;
         cout<<"1.Create Directed Graph."<<endl;
         cout<<"2.Create UnDirected Graph."<<endl;
         cout<<"3.Display Adjacency List."<<endl;
         cout<<"4.DFS Traversl."<<endl;
         cout<<"5.BFS Traversal"<<endl;
         cout<<"6.Dregree of a vertex."<<endl;



         while(true){
        	 cout<<"Enter The Choice From The Menu. ";
        	 cin>>choice;
        	 switch (choice){
        		 case 1:
        			 g1.createDirected();
        			 break;

        		 case 2:
        			 g1.createUndirected();
        			 break;

        		 case 3:
        			 g1.disp();
        			 break;
        		 case 4:
        			 cout<<"Enter The Staring Node."<<endl;
        			 int start;
        			 cin>>start;
        			 g1.dfsTaversal_Iterative(start);

        			 break;

        		 case 5:
        			 cout<<"Enter The Staring Node."<<endl;
        			 int st;
        			 cin>>st;
        			 g1.bfsTraversal_Iterative(st);

        			 break;
        		 case 6:
        			 cout<<"Enter The vetrex."<<endl;
        			 int s;
        			 cin>>s;
        			 g1.Degree(s);
        			 break;
        		 case 7:
        					 if(g1.isStrongly()){
        						 cout<<"The Graph is Strongly Connected "<<endl;
        					 }
        					 else{
        						 cout<<"The Graph is Not Strongly connected."<<endl;
        					 }
        					 break;

        	 }

         }

	return 0;
}
