#include <iostream>
#include <cmath>

using namespace std;

struct ratPair{
	int M;
	unsigned int N;
};

class Rational{
	private:
		ratPair RP;
		bool myErr;
		void Norm(){
			ratPair TMP=RP;
		}
	public:
		Rational(){
			Set(0,1);
		}
		Rational(ratPair RP){
			Set(RP.M, RP.N);
		}
		
		Rational(int a,int b){
			Set(a,b);
		}
		
		
		void Set(int a, unsigned int b){
				myErr=false;
				RP.M=a;
				if(b==0) {
					myErr=true;
					RP.N=1;
				} else {
					RP.N=b;
					Norm();
				}
		}
		ratPair Get(){
			return RP;
		}
		bool GetErr(){
			return myErr;
		}
		void Display(){
			cout<<"("<<RP.M<<"/"<<RP.N<<")";
		}	
};

Rational operator +(Rational A, Rational B){
	Rational TMP;
	if((A.GetErr()+B.GetErr())) return TMP;
	ratPair AP=A.Get();
	ratPair BP=B.Get();
	TMP.Set(AP.M*BP.N+AP.N*BP.M,AP.N*BP.N);
	return TMP;
}

Rational operator -(Rational A, Rational B){
	Rational TMP;
	if((A.GetErr()+B.GetErr())) return TMP;
	ratPair AP=A.Get();
	ratPair BP=B.Get();
	TMP.Set(AP.M*BP.N-AP.N*BP.M,AP.N*BP.N);
	return TMP;
}
Rational operator *(Rational A, Rational B){
	Rational TMP;
	if((A.GetErr()+B.GetErr())) return TMP;
	ratPair AP=A.Get();
	ratPair BP=B.Get();
	TMP.Set(AP.M*BP.M,AP.N*BP.N);
	return TMP;
}
Rational operator /(Rational A, Rational B){
	Rational TMP;
	if((A.GetErr()+B.GetErr())) return TMP;
	ratPair AP=A.Get();
	ratPair BP=B.Get();
	TMP.Set(AP.M*BP.N,AP.N*BP.M);
	return TMP;
}

bool operator >(Rational A, Rational B){
	
	if((A.GetErr()+B.GetErr())) return false;
	Rational TMP=A-B;
	if(TMP.Get().M>0) return true;
	else return false;

	
}
bool operator <(Rational A, Rational B){
		
	if((A.GetErr()+B.GetErr())) return false;
	Rational TMP=A-B;
	if(TMP.Get().M<0) return true;
	else return false;


}

int main(int argc, char** argv) {
	
	Rational N1 = Rational(1,3);
	Rational N2 = Rational(5,7);
	
	Rational N3 = N1+N2;
	N1.Display(); cout << "+"; N2.Display(); cout <<"="; N3.Display(); cout << endl;
	
	N3 = N1-N2;
	N1.Display(); cout << "-"; N2.Display(); cout <<"="; N3.Display(); cout << endl;
	
	N3 = N1*N2;
	N1.Display(); cout << "*"; N2.Display(); cout <<"="; N3.Display(); cout << endl;
	
	N3 = N1/N2;
	N1.Display(); cout << "/"; N2.Display(); cout <<"="; N3.Display(); cout << endl;
	
	system("pause");
	return 0;
}