#pragma once

#include <string>
#include <vector>

class Adder
{
public:
    typedef void (*callback_t)();

    Adder(callback_t callback);
    ~Adder();

    int Do(const int& a, const int& b, const std::string& msg = "");
    int Do(std::vector<int>& v, const std::string& msg = "");

private:
    callback_t _callback;
};