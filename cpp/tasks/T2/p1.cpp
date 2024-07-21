#include <iostream>
#include <string>

class Car
{
private:
    std::string company_name;
    std::string model;
    int year;

public:
    Car() : company_name(""), model(""), year(0)
    {
        std::cout << "Let's begin.." << std::endl;
    }

    void set_company_name(const std::string &cn)
    {
        company_name = cn;
    }

    void set_model(const std::string &m)
    {
        model = m;
    }

    void set_year(int y)
    {
        year = y;
    }

    std::string get_company_name() const
    {
        return company_name;
    }

    std::string get_model() const
    {
        return model;
    }

    int get_year() const
    {
        return year;
    }

    ~Car() {}
};

int main()
{
    Car c1;
    c1.set_company_name("Fiat");
    c1.set_model("Tipo");
    c1.set_year(2023);

    std::cout << c1.get_company_name() << " " << c1.get_model() << " " << c1.get_year() << std::endl;

    return 0;
}
