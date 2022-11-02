/*
Matt Burton
csc1720
2/2/21
csc1720/labs/lab04/main.cpp

uses the vectorType class to create and manipulate vectors

compile with g++ -Wall main.cpp vectorType.cpp -o testProg
execute with ./testProg
*/

#include "vectorType.h"
#include <iostream>
using namespace std;

int main()
{
	vectorType vOne;
	vectorType vTwo(1,2,3);

	cout << "Testing the default constructor and the getX(), getY(), and getZ() methods." << endl;
	cout << "x: " << vOne.getX() << " y: " << vOne.getY() << " z: " << vOne.getZ() << endl;

	cout << "Testing the constructor with parameters and the getX(), getY(), and getZ() methods." << endl;
	cout << "x: " << vTwo.getX() << " y: " << vTwo.getY() << " z: " << vTwo.getZ() << endl;

	vTwo.setComps(4, 5, 6);
	cout << "Testing the setComps() method with x = 4, y = 5, z = 6." << endl;
	cout << "x: " << vTwo.getX() << " y: " << vTwo.getY() << " z: " << vTwo.getZ() << endl;

	cout << "Testing the printVector() method." << endl;
	vOne.printVector();
	vTwo.printVector();
	cout << endl;

	cout << "Testing the calcMagnititude() method." << endl;
	cout << vTwo.calcMagnitude() << endl;

	cout << "Testing the scalarMultiply() method with a scale of 3." << endl;
	vTwo.scalarMultiply(3).printVector();
	cout << endl;

	return 0;
}

