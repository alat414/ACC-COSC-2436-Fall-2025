#include <iostream>
#include <cstring>

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
        ~String()
        {
            delete m_Data;

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
    private:
        String m_Name;

};
