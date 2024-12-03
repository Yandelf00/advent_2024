#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

bool inc(std::vector<int> vec){
    int i=0;
    int j=1;
    int bound = 1;
    while(j<vec.size()){
        if(vec[i]>=vec[j] || std::abs(vec[i]-vec[j])>3){
            bound--;    
            if(bound<0) return false;
            j++;
        }else{
            i = j;
            j++;
        }

    }
    return true;    
}

bool dec(std::vector<int> vec){
    int i=0;
    int j=1;
    int bound = 1;
    while(j<vec.size()){
        if(vec[i]<=vec[j] || std::abs(vec[i]-vec[j])>3){
            bound--;    
            if(bound<0) return false;
            j++;
        }else{
            i = j;
            j++;
        }

    }
    return true;    
}

int main(){
    int cmpt = 0;
    std::vector<int> vec, rev_vec;
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
            rev_vec.push_back(num);
        }
        std::reverse(rev_vec.begin(), rev_vec.end());
        if(inc(vec) || dec(rev_vec) || inc(rev_vec) || dec(vec)){
            cmpt++;
        }
        vec.clear();
        rev_vec.clear();
    }
    std::cout<<cmpt<<std::endl;
    
    return 0;
}