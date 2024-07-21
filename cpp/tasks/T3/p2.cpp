#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Vertex
{
private:
    int x;
    int y;

public:
    Vertex() : x(0), y(0) {}

    void set_random()
    {
        // to generate a random number between [-100 : 100]
        x = rand() % 201 - 100;
        y = rand() % 201 - 100;
    }
    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }

    std::string to_string()
    {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0))); // initializes the random number generator with a starting value (seed)
    // time(0) returns the current time in seconds,time value is then explicitly converted to an unsigned int and it passed to the srand function as the seed for the random number generator.
    for (int i = 0; i < 5; ++i)
    {
        Vertex v;
        v.set_random();
        std::cout << "Vertex " << i + 1 << ": " << v.to_string() << std::endl;
    }

    return 0;
}
