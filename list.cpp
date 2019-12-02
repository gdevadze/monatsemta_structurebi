#include <iostream>
#include <string.h>

using namespace std;

struct node{
    string data; 
    node *next;
};
class list{
    private:
    	node *head, *tail;
    public:
    	list(){
			head=NULL;
			tail=NULL;
		}
		void AddKey(string k)
		{
			node *Elem=new node();
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
			node *y=0, *x=head;
			while (Elem->data>x->data)
			{
				y=x;
				x=x->next;
			}
			Elem->next=x;
			y->next=Elem;
		}
		
		void display(){
			node *temp=new node;
			temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
	
		void delete_first(){
			node *temp=new node;
			temp=head;
			head=head->next;
			delete temp;
		}
		void delete_last(){
			node *current=new node;
			node *previous=new node;
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
			node *current=new node;
			node *previous=new node;
			current=head;
			for(int i=1;i<pos;i++){
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
	
};
  
int main(int argc, char** argv) {
	list obj;
	obj.AddKey("Papunidze");
	obj.AddKey("Devadze");
	obj.AddKey("Beridze");
	obj.display();
	cout<<endl;
	obj.delete_position(1);
	obj.display();

	cout<<endl;
	obj.AddKey("Meskhidze");
	obj.display();
	

	return 0;
}
