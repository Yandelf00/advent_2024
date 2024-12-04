#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    int result = 0;
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::regex pattern(R"(mul\((\d+),(\d+)\))");
    std::string line;

    while (std::getline(inputFile, line)) {
        std::sregex_iterator it(line.begin(), line.end(), pattern);
        std::sregex_iterator end;

        while (it != end) {

            std::smatch match = *it;
            std::string num1 = match[1]; 
            std::string num2 = match[2]; 
            int intNum1 = std::stoi(num1);
            int intNum2 = std::stoi(num2);
            int tmp = intNum1 * intNum2;
            result += tmp;

            ++it;
        }
    }

    inputFile.close(); 

    std::cout<<result<<std::endl;
    return 0;
}