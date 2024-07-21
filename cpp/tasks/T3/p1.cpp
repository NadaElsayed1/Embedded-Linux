#include <iostream>
#include <cstdlib>
#include <ctime>

struct Vertex
{
    int x;
    int y;
};

int main()
{
    srand(time(0));

    for (int i = 0; i < 5; ++i)
    {
        Vertex v;
        v.x = rand() % 201 - 100;
        v.y = rand() % 201 - 100;
        std::cout << "Vertex " << i + 1 << ": (" << v.x << ", " << v.y << ")" << std::endl;
    }

    return 0;
}
