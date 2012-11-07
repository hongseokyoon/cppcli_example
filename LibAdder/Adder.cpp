#include "StdAfx.h"
#include "Adder.h"

#include <iostream>

using namespace std;

Adder::Adder(callback_t callback)
    : _callback(0)
{
    _callback = callback;
}

Adder::~Adder()
{
}

int Adder::Do(const int& a, const int& b, const std::string& msg)
{
    int result = a + b;
    cout << a << " + " << b << " = " << result << endl;
    if (!msg.empty()) 
    {
        cout << "This is your message: " << msg << endl;
    }

    if (_callback) _callback();

    return result;
}

int Adder::Do(std::vector<int>& v, const std::string& msg)
{
    int result = 0;

    for (vector<int>::size_type i = 0; i < v.size(); ++i) result += v[i];

    cout << "Sum is " << result << endl;
    if (!msg.empty()) 
    {
        cout << "This is your message: " << msg << endl;
    }

    if (_callback) _callback();

    return result;
}