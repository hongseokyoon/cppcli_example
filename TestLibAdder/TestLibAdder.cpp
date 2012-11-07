// TestLibAdder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../LibAdder/Adder.h"
#include <iostream>

#pragma comment(lib, "../Debug/LibAdder.lib")

using namespace std;

void my_callback()
{
    cout << "This is user defined callback function." << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    Adder adr(my_callback);
    cout << "(1)" << endl;
    adr.Do(1, 2);
    cout << endl << "(2)" << endl;
    adr.Do(v, "Hongseok's message");

	return 0;
}

