#include <iostream>
template <typename T>
class Pair
{
    T first, second;

public:
    Pair()
    {
        first = 0;
        second = 0;
    }

    Pair(T f, T s)
    {
        first = f;
        second = s;
    }

    T getFirst()
    {
        return first;
    }

    T getSecond()
    {
        return second;
    }

    void setFirst(T f)
    {
        first = f;
    }

    void setSecond(T s)
    {
        second = s;
    }

    void setPairs(T f, T s)
    {
        first = f;
        second = s;
    }

    void swap()
    {
        T temp = first;
        first = second;
        second = temp;
    }

    void print()
    {
        std::cout << "First: " << first << ", Second: " << second << std::endl;
    }

    ~Pair() {}
};

int main()
{
    Pair<int> p;
    p.setFirst(10);
    p.setSecond(20);
    p.print();

    p.setPairs(30, 40);
    p.print();

    p.swap();
    p.print();

    return 0;
}