#include <iostream>

int& GetValue()
{
    static int value = 17;
    return value;
}

int main()
{
    int i = GetValue();
    GetValue() = 7;
}