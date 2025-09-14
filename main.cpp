#include <iostream>
/*
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
    */

void PrintName(std:: string& name)
{
    std::cout << name << std::endl;
}
int main() 
{
    std::string firstName = "Gustavo";
    std::string lastName = "Alatriste";

    std::string fullName = firstName + lastName;

    PrintName(fullName);

    return 0;
}   