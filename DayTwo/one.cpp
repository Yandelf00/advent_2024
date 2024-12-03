#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

int main(){
    int cmpt = 0;
    int x, y;
    std::ifstream inputFile("input.txt");
    if(!inputFile){
        std::cerr<<"Error : cannot open file"<<std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(inputFile, line)){
        std::stringstream ss(line);
        int num;
        if(ss >> num){
            x = num;    
        }
        if(ss >> num){
            y = num;    
        }
        if(x<y){
            bool res = true;
            int min = y;
            if(std::abs(x - y) > 3) res = false;
            while(ss>>num){
                if(min >= num || std::abs(min - num) > 3) res = false;
                min = num;
            }
            if(res == true) cmpt++;
        }
        if(x>y){
            bool res = true;
            int min = y;
            if(std::abs(x - y) > 3) res = false;
            while(ss>>num){
                if(min <= num || std::abs(min - num) > 3) res = false;
                min = num;
            }
            if(res == true) cmpt++;
        }
    }
    std::cout<<cmpt<<std::endl;
    return 0;
}