#include <iostream>
#include <cstring>
#include <string>

class String
{
    public:
        // Default constructor
        String() : m_Data(nullptr), m_Size(0) 
        {

        }
        // Creating string value
        String(const char* string)
        {
            printf("Created!\n");
            m_Size = strlen(string);
            m_Data = new char[m_Size + 1];
            memcpy(m_Data, string, m_Size);
            m_Data[m_Size] = '\0';
        }
        // Copying string value
        String(const String& other)
        {
            printf("Copied!\n");
            m_Size = other.m_Size;
            m_Data = new char[m_Size + 1];
            memcpy(m_Data, other.m_Data, m_Size + 1);     
        }
        // Moving string value to a different location
        String(String && other) noexcept
        {
            printf("Moved!\n");
            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Size = 0;
            other.m_Data = nullptr;
        }
        // Temporary location for moved string value
        String& operator=(String&& other) noexcept
        {
            printf("Moved!\n");

            if(this!= &other)
            {
                delete[] m_Data;
                m_Size = other.m_Size;
                m_Data = other.m_Data;

                other.m_Size = 0;
                other.m_Data = nullptr;
            }

            return *this;
        }
        // Destructor for string value previously used.
        ~String()
        {
            printf("Deleted!\n");
            delete[] m_Data;
        }
        // Print statement for string value
        void Print()
        {
            if (m_Data)
            {
                for (uint32_t i = 0; i < m_Size; i++)
                {
                    printf("%c", m_Data[i]);
                }
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
        Entity(String&& name)
            : m_Name(std::move(name))
        {
        }
        
        void PrintName()
        {
            m_Name.Print();
        }
    private:
        String m_Name;
};

int main()
{
    //Entity entity(String("Gustavo"));
    //entity.PrintName();

    String orange = "Orange";
    String dest;

    orange.Print();
    dest.Print();

    dest = std::move(orange);

    orange.Print();
    dest.Print();

    std::cin.get();
}   