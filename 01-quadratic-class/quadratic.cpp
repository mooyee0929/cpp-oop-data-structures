#include "quadratic.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void QUADRATIC::print()
{
	cin >> a >> b >> c;
	cout<<a<<"x^2";
	if(b>=0){
		cout<<"+"<<b<<"x";
	}
	else{
		cout<<b<<"x";
	}

	if(c>=0){
		cout<<"+"<<c<<endl;
	}
	else{
		cout<<c<<endl;
	}
	//PRINT QUADRATIC FORMULA
	
}

void QUADRATIC::add(QUADRATIC q)
{
	cin >> a >> b >> c;
	a += q.a;
	b += q.b;
	c += q.c;

	cout<<a<<"x^2";
	if(b>=0){
		cout<<"+"<<b<<"x";
	}
	else{
		cout<<b<<"x";
	}

	if(c>=0){
		cout<<"+"<<c<<endl;
	}
	else{
		cout<<c<<endl;
	}
	//ADD TWO QUADRATIC FORMULAS
	
}

void QUADRATIC::discriminant()
{
	cin >> a >> b >> c;
	double D = b*b-4*a*c;
	if (D > 0) {
		double root1, root2;
		root1 = (-b + sqrt(D)) / double(2 * a);
		root2 = (-b - sqrt(D)) / double(2 * a);
		cout << "There are two roots: " << root1 << ", " << root2 << endl;
	}
	else if( D < 0){
		double root1, root2;
		root1 = (sqrt(-D)) / double(2 * a);
		root2 = (sqrt(-D)) / double(2 * a);
		cout << "There are two complecx root: " << double(-b) / double(2 * a) << " + " << root1 << "i" << ", " << double(-b) / double(2 * a) << " - " << root2 << "i"<<endl;
	}
	else {
		double root1;
		root1 = (-b + sqrt(D)) / double(2 * a);
		cout << "There is a double root: " << root1 << endl;
	}
	
}