#include <iostream>

using namespace std;

void a_b_shualedi(int a, int b){
	for(int i=a; i<=b; i++){
		if(i % 2 == 0)
			cout << i << " ";	
	}
}

int main(int argc, char** argv) {
    
	int A; cout << "A="; cin >> A;
	int B; cout << "B="; cin >> B;
	a_b_shualedi(A,B);
	
	return 0;
}