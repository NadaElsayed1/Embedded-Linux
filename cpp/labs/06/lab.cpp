#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

struct NumberProcessor
{
    std::vector<int> numbers;

    bool readFromFile(const std::string &filename)
    {
        std::ifstream inFile(filename);
        if (!inFile)
        {
            std::cerr << "Unable to open input file: " << filename << std::endl;
            return false;
        }

        int num;
        while (inFile >> num)
        {
            numbers.push_back(num);
        }
        inFile.close();

        return true;
    }

    bool processAndWriteToFile(const std::string &filename)
    {
        if (numbers.empty())
        {
            std::cerr << "No data to process." << std::endl;
            return false;
        }

        int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
        double avg = static_cast<double>(sum) / numbers.size();
        int min = *std::min_element(numbers.begin(), numbers.end());
        int max = *std::max_element(numbers.begin(), numbers.end());

        std::ofstream outFile(filename);
        if (!outFile)
        {
            std::cerr << "Unable to open output file: " << filename << std::endl;
            return false;
        }

        outFile << "------------------------------------------------------------------\n ";
        outFile << "|     Sum      |      Avg      |      Min      |      Max      |\n";
        outFile << "------------------------------------------------------------------\n ";
        outFile << "| " << std::left << std::setw(12) << sum << std::setw(5) << " | "
                << std::left << std::setw(11) << std::fixed << std::setprecision(2) << avg << std::setw(4) << " | "
                << std::left << std::setw(12) << min << std::setw(3) << " | "
                << std::left << std::setw(12) << max << std::setw(4) << "  |" << std::endl;
        outFile << "------------------------------------------------------------------\n ";

        outFile.close();

        return true;
    }
};

int main()
{
    NumberProcessor processor;
    if (!processor.readFromFile("input.txt"))
    {
        return 1;
    }

    if (!processor.processAndWriteToFile("output.txt"))
    {
        return 1;
    }

    return 0;
}
