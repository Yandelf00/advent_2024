#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    int result = 0;
    bool isActive = true;

    std::ifstream inputFile("inputest.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::regex pattern(R"((mul\((\d+),(\d+)\))|(do\(\))|(don't\(\)))");

    std::string line;

    while (std::getline(inputFile, line)) {
        std::sregex_iterator it(line.begin(), line.end(), pattern);
        std::sregex_iterator end;

        while (it != end) {
            std::smatch match = *it;

            if (match[1].matched) {
                if (isActive) {
                    int intNum1 = std::stoi(match[2]);
                    int intNum2 = std::stoi(match[3]);
                    int tmp = intNum1 * intNum2;
                    result += tmp;
                }
            } else if (match[4].matched) {
                isActive = true;
            } else if (match[5].matched) {
                isActive = false;
            }

            ++it;
        }
    }

    inputFile.close();

    std::cout << "Final Result: " << result << std::endl;
    return 0;
}
