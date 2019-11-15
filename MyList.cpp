#include <iostream>
using namespace std;
struct Node{
	int Value;
	Node *Next;
	Node(){Next=0;Value=0;}
};

class MyList{
	private:
		Node *First;
		Node *Last;
	public:
		MyList() {First=0;Last=0;}
		void Add(Node *Elem)
		{
			if (First==0) {First=Elem;Last=Elem;return;}
			if (First->Value>Elem->Value)
			{
				Elem->Next=First;
				First=Elem;
				return;
			}
			if (Last->Value<Elem->Value)
			{
				Last->Next=Elem;
				Last=Elem;
				return;
			}
			Node *y=0, *x=First;
			while (Elem->Value>x->Value)
			{
				y=x;
				x=x->Next;
			}
			Elem->Next=x;
			y->Next=Elem;
		}
		void AddKey(int k)
		{
			Node *Elem=new Node();
			Elem->Value=k;
			if (First==0) {First=Elem;Last=Elem;return;}
			if (First->Value>Elem->Value)
			{
				Elem->Next=First;
				First=Elem;
				return;
			}
			if (Last->Value<Elem->Value)
			{
				Last->Next=Elem;
				Last=Elem;
				return;
			}
			Node *y=0, *x=First;
			while (Elem->Value>x->Value)
			{
				y=x;
				x=x->Next;
			}
			Elem->Next=x;
			y->Next=Elem;
		}
		void Remove(int k)
		{
			if (First==0) return ;
			if (First->Value==k)
			{
				Node *x=First->Next;
				First->Next=0;
				First=x;
				if (First==0) Last=0;
			}
		}
		void Print()
		{
			Node *x=First;
			if (First==0) return ;
			while (x->Next!=0)
			{
				cout<<x->Value<<"->";
				x=x->Next;
			}
			cout<<x->Value;
		}
};

int main(){
	Node *X1=new Node();
	Node *X2=new Node();
	Node *X3=new Node();
	MyList *A=new MyList();
	MyList *B=new MyList();

	for(int i=3;i<=100;i+=3)
	A->AddKey(i);
	
	A->Print();
	//cout<<endl;
	//A->Remove();
	//A->Print();
	//cout<<endl;
	//B->Print();
	cout<<endl;
	system("pause");
	return 0;
}

