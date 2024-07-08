#include <iostream>
template <typename T1, typename T2>
class keyValuePair
{
    T1 key;
    T2 value;

public:
    keyValuePair()
    {
        key = 0;
        value = 0;
    }

    keyValuePair(T1 k, T2 v)
    {
        key = k;
        value = v;
    }

    T1 getkey()
    {
        return key;
    }

    T2 getvalue()
    {
        return value;
    }

    void setkey(T1 k)
    {
        key = k;
    }

    void setvalue(T2 v)
    {
        value = v;
    }

    void setkeyValuePairs(T1 k, T2 v)
    {
        key = k;
        value = v;
    }

    void print()
    {
        std::cout << "key: " << key << ", value: " << value << std::endl;
    }

    ~keyValuePair() {}
};

int main()
{
    keyValuePair<int, int> p;
    p.setkey(10);
    p.setvalue(20);
    p.print();

    p.setkeyValuePairs(30, 40);
    p.print();

    return 0;
}