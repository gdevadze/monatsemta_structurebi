#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node
{
	int Value;
	Node* Left;
	Node* Right;
	Node(){Left=0;Right=0;}
};
class BinTree
{
	private:
		Node* Top;
		void LO(Node *T)
		{
			if ((T->Left==0) && (T->Right==0)) 
			{
				cout<<T->Value<<" ";
			}
			if ((T->Left!=0) && (T->Right==0)) 
			{
				LO(T->Left);
				cout<<T->Value<<" ";
			}
			if ((T->Left==0) && (T->Right!=0)) 
			{
				cout<<T->Value<<" ";
				LO(T->Right);
			}
			if ((T->Left!=0) && (T->Right!=0)) 
			{
				LO(T->Left);
				cout<<T->Value<<" ";
				LO(T->Right);
			}
		}
		void RO(Node *T)
		{
			if ((T->Left==0) && (T->Right==0)) 
			{
				cout<<T->Value<<" ";
			}
			if ((T->Left!=0) && (T->Right==0)) 
			{
				cout<<T->Value<<" ";
				RO(T->Left);
			}
			if ((T->Left==0) && (T->Right!=0)) 
			{
				RO(T->Right);
				cout<<T->Value<<" ";
			}
			if ((T->Left!=0) && (T->Right!=0)) 
			{
				RO(T->Right);
				cout<<T->Value<<" ";
				RO(T->Left);
			}
		}
	public:
		BinTree() {Top=0;}
		void Add(Node *Elem)
		{
			if (Top==0) {Top=Elem;return;}
			Node *y=0, *x=Top;
			while (x!=0)
			{
				y=x;
				if (x->Value<Elem->Value) x=x->Right;
				else
					if (x->Value>Elem->Value) x=x->Left;
					else return;
					
			}
			if (y->Value<Elem->Value) y=y->Right; else y=y->Left;
		}
		void AddKey(int k)
		{
			Node *Elem=new Node();
			Elem->Value=k;
			if (Top==0) {Top=Elem;return;}
			Node *y=0, *x=Top;
			while (x!=0)
			{
				y=x;
				if (x->Value<Elem->Value) x=x->Right;
				else
					if (x->Value>Elem->Value) x=x->Left;
					else return;
					
			}
			if (y->Value<Elem->Value) y->Right=Elem; else y->Left=Elem;
		}
		void LeftOrder()
		{
			LO(Top);
		}
		void RightOrder()
		{
			RO(Top);
		}
};
int main(int argc, char** argv) {
	BinTree *A=new BinTree();
	A->AddKey(7);
	A->AddKey(3);
	A->AddKey(10);
	A->AddKey(2);
	A->AddKey(4);
	A->RightOrder();
	return 0;
}