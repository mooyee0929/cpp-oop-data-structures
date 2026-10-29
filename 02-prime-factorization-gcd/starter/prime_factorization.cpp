#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class PrimeFactorization {
private:
	int num1, num2;
	vector<int> num1_factor, num2_factor;
	
public:
	PrimeFactorization() {
		//TO_DO: initial constructor
	}
	PrimeFactorization(int _a, int _b) {
		//TO_DO: _a means the first integer and _b means the second integer
	}
	void Get_Prime_Factorization() {
		//TO_DO: Prime factorization num1 and num2, push result to the num1_factor and num2_factor.
	}

	void Print_Prime_Factorization() {
		//TO_DO: Print num1_factor and num2_factor.
	}

	void Print_GCD() {
		//TO_DO: Use num1_factor and num2_factor to find GCD and print the result.
	}

};

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		cout << "num1 = " << a << endl;
		cout << "num2 = " << b << endl;

		PrimeFactorization PF(a, b);

		PF.Get_Prime_Factorization();
		PF.Print_Prime_Factorization();
		PF.Print_GCD();

		cout << endl;

	}

	system("PAUSE");
	return 0;
}
