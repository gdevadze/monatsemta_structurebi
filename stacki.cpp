#include <iostream>


struct Node {
	int data;
	Node *next;
};
using namespace std;

class Stack {
	private:
		Node *Top;
	public:
		Stack(){
			Top=0;
		}
		
		void Push(int k){
			
			Node *tmp;
			tmp=new Node();
			tmp->data=k;
			tmp->next=Top;
			Top=tmp;
		}
		
		void Pop(){
			
			if(Top!=0){
				Node *tmp=Top;
				Top=Top->next;
				
			}
		}
		
		void print (){
			Node *tmp=Top;
			if (tmp==0) cout<<"steki carielia";
			while (tmp->next!=0){
				cout<<tmp->data<<"---";
				tmp=tmp->next;
			}
			cout<<tmp->data;
		}
		
		int GetTop(){
			int p=Top->data;
			
			return p;
		}
};



int main(int argc, char** argv) {
	Stack *a=new Stack();
	Stack *b=new Stack();
	Stack *c=new Stack();
	
    int m; cout<<"M="; cin>>m;
    int n; cout<<"N="; cin>>n;
	
	for (int i=0; i<m; i++){
	   int s; cout<<i<<"elementi= "; cin>>s;
	   a->Push(s);
	}
	
	for (int i=0; i<n; i++){
	   int s; cout<<i<<"elementi= "; cin>>s;
	   b->Push(s);
	}
	
    for (int i=0; i<m; i++){
    	c->Push(a->GetTop());
    	a->Pop();
	}
	
    for (int i=0; i<n; i++){
    	c->Push(b->GetTop());
    	b->Pop();
	}

	c->print();
	
	system("pause");
	return 0;
}
