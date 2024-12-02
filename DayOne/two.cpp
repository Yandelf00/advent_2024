#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>

int main(){
    int tmp;
    int result = 0;
    std::vector<int> vec_one, vec_two;
    std::map<int, int> myMap;
    std::ifstream inputFile("input.txt");
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
    for(int i : vec_two){
        if (myMap.find(i) != myMap.end()){
            myMap[i] += 1;
        } else {
            myMap[i] = 1; 
        }
    }

    for(int i : vec_one){
        if (myMap.find(i) != myMap.end()){
            result += i * myMap[i];
        }
    }
    std::cout<<result<<std::endl;
    return 0;
}