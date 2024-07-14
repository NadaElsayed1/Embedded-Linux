#include <iostream>
#include <string>
int main()
{
    std::string text = "The cycle of life is a cycle of cycles";
    std::string charstr = "cycle";
    int pos = 0;

    std::cout << text << std::endl;

    while ((pos = text.find(charstr, pos)) != std::string::npos)
    {
        text.replace(pos, 5, "circle");
        std::cout << text << std::endl;
    }

    charstr = "circle";
    pos = 0;

    pos = text.find(charstr, pos);
    text.insert(pos, "great ");
    std::cout << text << std::endl;
    pos += 11;
    pos = text.find(charstr, pos);
    text.insert(pos, "never ending ");
    std::cout << text << std::endl;
    return 0;
}