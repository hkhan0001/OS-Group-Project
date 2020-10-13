#include <iostream>
#include <cstddef>
#include <cstdint>

using namespace std;

class Memory
{
    private:
        uint8_t storage[2048];
    public:
        Memory()
        {
            for(int i = 0; i < 2047; i++)
            {
                storage[i] = 0;
            }
        }
        void store(uint8_t hex);
        void isFull();
        uint8_t pass(int index);
};

void Memory :: store(uint8_t hex)
{
    Memory check;
    check.isFull();
    for(int i = 0; i < 2047; i++)
    {
        if(storage[i] == 0)
        {
            storage[i] = hex;
            break;
        }
    }
}

uint8_t Memory :: pass(int index)
{
    Memory check;
    uint8_t p;
    p = storage[index];
    return p;
    storage[index] = 0;
}

void Memory :: isFull()
{
    for(int i = 0 ; i < 2048 ; i++)
    {
        if(storage[0] != 0 && storage[2047] != 0)
        {
            cout << "RAM FULL";
            storage[i] = 0;
            cout << "CLEARED";
        }
        else
        {
            cout << "NOT FULL";
            break;
        }
    }
}

int main()
{
    Memory test;
    
    int index = 0;
    uint8_t hex = 0xEE;
    
    test.store(hex);
    uint8_t res = test.pass(0);
    
    cout << "The result Stored was: " << unsigned(res);
}

