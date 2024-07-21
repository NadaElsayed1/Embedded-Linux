#include <iostream>
#include <string>

std::string source_string()
{
    return "The cycle of life is a cycle of cycles";
}

std::string replace_string(std::string text, std::string &concarecy, std::string &rpword)
{
    int pos = 0;
    while ((pos = text.find(concarecy, pos)) != std::string::npos)
    {
        text.replace(pos, concarecy.size(), rpword);
        pos += rpword.size();
    }

    return text;
}

int main()
{
    int position = 0;
    std::string concarecy_word = "cycle";
    std::string rstr;

    std::string str = source_string();
    std::cout << "Here is the Source String: " << str << std::endl;

    std::cout << "Enter the replacing word you want: ";
    std::cin >> rstr;

    str = replace_string(str, concarecy_word, rstr);
    std::cout << "The final string: " << str << std::endl;

    return 0;
}
