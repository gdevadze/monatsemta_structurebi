#include <iostream>
#include <string.h>

using namespace std;
template <typename T>
struct node{
    T data; 
    node *next;
};

template <typename N>

class list{
    private:
    	node<N> *head, *tail;
    public:
    	list(){
			head=NULL;
			tail=NULL;
		}
		void AddKey(N k)
		{
			node<N> *Elem=new node<N>();
			Elem->data=k;
			if (head==0) {head=Elem;tail=Elem;return;}
			if (head->data>Elem->data)
			{
				Elem->next=head;
				head=Elem;
				return;
			}
			if (tail->data<Elem->data)
			{
				tail->next=Elem;
				tail=Elem;
				return;
			}
			node<N> *y=0, *x=head;
			while (Elem->data>x->data)
			{
				y=x;
				x=x->next;
			}
			Elem->next=x;
			y->next=Elem;
		}
		
		void display(){
			node<N> *temp=new node<N>;
			temp=head;
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
	
		void delete_first(){
			node<N> *temp=new node<N>;
			temp=head;
			head=head->next;
			delete temp;
		}
		void delete_last(){
			node<N> *current=new node<N>;
			node<N> *previous=new node<N>;
			current=head;
			while(current->next!=NULL){
				previous=current;
				current=current->next;	
			}
			tail=previous;
			previous->next=NULL;
			delete current;
		}
		void delete_position(int pos){
			if(pos==1){
				delete_first();
			}
			node<N> *current=new node<N>;
			node<N> *previous=new node<N>;
			current=head;
			for(int i=1;i<pos;i++){
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
		
		N PrintSeparateElement (int pos){
			node<N> *current=new node<N>;
			node<N> *previous=new node<N>;
			current=head;
			for(int i=1;i<pos;i++){
				previous=current;
				current=current->next;
			}
			return current->data;
		}
	
	
	
	
};

double Fasi(string a, int n){
	if(a=="Mwvadi") return n * 1;
	if(a=="Xinkali") return n * 0.5;
	if(a=="Xachapuri") return n * 1.5;
	if(a=="Sacivi") return n * 2;
	if(a=="Ludi") return n * 3;
	if(a=="Wyali") return n * 0.3;
	if(a=="Limonati") return n * 1;
	if(a=="Gvino") return n * 1.2;
	if(a=="Yava") return n * 0.6;
	if(a=="Chai") return n * 2.2;
}

int main(int argc, char** argv) {
	
	list<int> Magidebi;
	//magida
	for(int i=1; i<=10;i++){
		Magidebi.AddKey(i);
	}
	Magidebi.display();
	cout<<endl<<endl;
	//sakvebi
	list<string> Dishes;
	Dishes.AddKey("Mwvadi");
	Dishes.AddKey("Xinkali");
	Dishes.AddKey("Xachapuri");
	Dishes.AddKey("Sacivi");
	Dishes.AddKey("Ludi");
	Dishes.AddKey("Wyali");
	Dishes.AddKey("Limonati");
	Dishes.AddKey("Gvino");
	Dishes.AddKey("Yava");
	Dishes.AddKey("Chai");
	Dishes.display();

	cout<<endl;
	cout<<"Magida #"<<Magidebi.PrintSeparateElement(1)<<endl;
	cout<<Dishes.PrintSeparateElement(3)<< " " << Fasi(Dishes.PrintSeparateElement(3),2)<<" Lari"<<endl;
	cout<<Dishes.PrintSeparateElement(2)<< " " << Fasi(Dishes.PrintSeparateElement(2),2)<<" Lari"<<endl;
	cout<<Dishes.PrintSeparateElement(4)<< " " << Fasi(Dishes.PrintSeparateElement(4),3)<<" Lari"<<endl;
	cout<<"--------------"<<endl;
	cout<<"Sul Jami: " << Fasi(Dishes.PrintSeparateElement(3),2)+Fasi(Dishes.PrintSeparateElement(2),2)+Fasi(Dishes.PrintSeparateElement(4),3);
	return 0;
}
