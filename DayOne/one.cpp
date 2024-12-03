#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>


int main(){
    int tmp;
    int result = 0;
    std::vector<int> vec_one, vec_two;
    std::ifstream inputFile("inputthird.txt");
    if(!inputFile){
        std::cerr<<"Error : cannot open file ! "<<std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(inputFile, line)){
        std::stringstream ss(line);
        int num;
        if(ss >> num){
            vec_one.push_back(num);
        }
        if(ss >> num){
            vec_two.push_back(num);
        }
    }
    std::sort(vec_one.begin(), vec_one.end());
    std::sort(vec_two.begin(), vec_two.end());
    for (int i = 0 ; i < vec_one.size() ; i++){
        tmp = std::abs(vec_one[i] - vec_two[i]);
        result += tmp;
    }

    std::cout<<result<<std::endl;
    inputFile.close();
    return 0;
}