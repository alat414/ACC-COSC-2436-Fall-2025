#include <iostream>
#include <string.h>
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
    

void PrintName(const std:: string& name)
{
    std::cout << "[lvalue] " << name << std::endl;
}
void PrintName(std:: string&& name)
{
    std::cout << "[rvalue] " << name << std::endl;
}
int main() 
{
    std::string firstName = "Gustavo";
    std::string lastName = "Alatriste";

    std::string fullName = firstName + lastName;

    PrintName(fullName);
    PrintName(firstName + lastName);

    std::cin.get();
    
}  

*/
class String
{
    public:
       String() = default;
       String(const char* string)
       {
            printf("Created!\n");
            m_Size = strlen(string);
            m_Data = new char[m_Size];
            memcpy(m_Data, string, m_Size);
       }

       String(const String& other)
       {
            printf("Copied!\n");
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);
       }
       
       String(String&& other) noexcept
       {
            printf("Moved!\n");
            m_Size = other.m_Size;
            m_Data = other.m_Data;
           
            other.m_Size = 0;
            other.m_Data = nullptr;
       }

       String& operator = (String&& other) noexcept
       {
            printf("Moved!\n");

            if (this != &other)
            {
                delete[] m_Data;

                m_Size = other.m_Size;
                m_Data = other.m_Data;
           
                other.m_Size = 0;
                other.m_Data = nullptr;
            }

            return *this;
       }
       ~String()
       {
            printf("Deleted!\n");
            delete m_Data;
       }

       void Print()
       {
            for (uint32_t i = 0; i < m_Size; i++)
            {
                printf("%c", m_Data[i]);
            }
            printf("\n");
       }
    private:
        char* m_Data;
        uint32_t m_Size;
};

class Entity
{
    public:
        Entity(const String& name)
            : m_Name(name)
        {

        }
        Entity(String && name)
            : m_Name(std::move(name))
        {

        }
        void Print()
        {
            m_Name.Print();
        }
    private:
        String m_Name;

};

int main()
{
    Entity entity("Gustavo");
    entity.Print();

    String string = "Good Afternoon";
    String dest;

    string.Print();
    dest.Print(); 

    dest = std::move(string);
    string.Print();
    dest.Print();
    
    std::cin.get();
}