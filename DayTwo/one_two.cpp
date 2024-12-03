#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

bool inc(std::vector<int> vec){
    int i=0;
    int j=1;
    while(j<vec.size()){
        if(vec[i]>vec[j] || std::abs(vec[i]-vec[j])>3 || vec[i]==vec[j]){
            return false;
        }
        i++;
        j++;
    }
    return true;    
}

bool dec(std::vector<int> vec){
    int i=0;
    int j=1;
    while(j<vec.size()){
        if(vec[i]<vec[j] || std::abs(vec[i]-vec[j])>3 ||vec[i]==vec[j]){
           return false;
        }
        i++;
        j++;
    }
    return true;    
}

int main(){
    int cmpt = 0;
    std::vector<int> vec;
    std::ifstream inputFile("input.txt");
    if(!inputFile){
        std::cerr<<"Error : cannot open file"<<std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(inputFile, line)){
        std::stringstream ss(line);
        int num; 
        while(ss >> num){
            vec.push_back(num);
        }
        if(inc(vec) || dec(vec)){
            cmpt++;
        }
        vec.clear();
    }
    std::cout<<cmpt<<std::endl;
    
    return 0;
}