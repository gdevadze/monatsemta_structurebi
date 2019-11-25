#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

class QUEUE{
	private:
		Node *First;
		Node *Last;
	public:
		QUEUE(){
			First = 0;
			Last = 0;
		}
		
		void AddQueue(int k){
			Node *temp = new Node;
			temp->data=k;
			temp->next=0;
			if (Last==0){
				First=temp;
				Last=temp;
			}else{
				Last->next=temp;
				Last=temp;
			}
		}
		
		void washla(){
			if(Last != 0){
				Node *x = First;
				First=First->next;
				if(First==0){
					Last=0;
				}
			}
			else{
				cout << "Rigi carielia" << endl;
			}
		}
		
		void PrintQueue(){
			Node *temp = First;
			while(temp!=0){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
};

int main(int argc, char** argv) {
	QUEUE A;
	A.AddQueue(5);
	A.AddQueue(7);
	A.AddQueue(10);
	A.AddQueue(11);
	A.AddQueue(12);
	A.PrintQueue();
	A.washla();
	A.PrintQueue();
	A.AddQueue(20);
	A.PrintQueue();
	return 0;
}
