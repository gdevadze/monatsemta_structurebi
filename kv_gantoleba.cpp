#include <iostream>
#include <cmath>

using namespace std;

class KvGantoleba{
	private:
		double a;
		double b;
		double c;
	public:
		KvGantoleba(){
			a = 0;
			b = 0;
			c = 0;
		}
		
		KvGantoleba(double a, double b, double c){
			Set(a,b,c);
		}
		
		void Set(double a, double b, double c){
			this->a=a;
			this->b=b;
			this->c=c;
		}
		
		double D(){
			return a*a - 4*a*c;
		}
		
		void X(){
			if(D() < 0)
				cout << "Amonaxsni ar aqvs!" << endl;
					else if(D() > 0){
						cout<< "X1=" << (-b - sqrt(D())) / 2*a << endl;
						cout<< "X2=" << (-b + sqrt(D())) / 2*a << endl;
						}
						else
							cout << -b/2*a << endl;
		}
		
};

int main(int argc, char** argv) {
	
	double a = 0; cout<< "a="; cin >> a;
	double b = 0; cout<< "b="; cin >> b;
	double c = 0; cout<< "c="; cin >> c;
	
	KvGantoleba gant = KvGantoleba(a,b,c);
	gant.X();
	
	
	return 0;
}