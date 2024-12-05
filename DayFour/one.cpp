#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>

int helper(std::map<std::vector<int>, char> mymap, int x, int y){
    int result = 0;
    int cmpt = 0;
    std::vector<char> myvec = {'M', 'A', 'S'};
    for(int i=0; i < 3 ; i++){
        if(mymap.find({y, x+1+i})!=mymap.end()){
            if(mymap[{y, x+1+i}] == myvec[i]){
              cmpt++;
            }
        }
        if(cmpt == 3){
            result++;
            cmpt=0;
        }
    }
    cmpt = 0;
    for(int i=0; i < 3 ; i++){
        if(mymap.find({y, x-1-i})!=mymap.end()){
            if(mymap[{y, x-1-i}] == myvec[i]){
              cmpt++;
            }
        }
        if(cmpt == 3){
            result++;
            cmpt=0;
        }
    }
    cmpt = 0;
    for(int i=0; i < 3 ; i++){
        if(mymap.find({y+i+1, x})!=mymap.end()){
            if(mymap[{y+i+1, x}] == myvec[i]){
              cmpt++;
            }
        }
        if(cmpt == 3){
            result++;
            cmpt = 0;
        }
    }
    cmpt = 0;
    for(int i=0; i < 3 ; i++){
        if(mymap.find({y-i-1, x})!=mymap.end()){
            if(mymap[{y-i-1, x}] == myvec[i]){
              cmpt++;
            }
        }
        if(cmpt == 3){
            result++;
            cmpt = 0;
        }
    }
    cmpt = 0;
    for(int i=0; i < 3 ; i++){
        if(mymap.find({y-i-1, x-1-i})!=mymap.end()){
            if(mymap[{y-i-1, x-1-i}] == myvec[i]){
              cmpt++;
            }
        }
        if(cmpt == 3){
            result++;
            cmpt = 0;
        }
    }
    cmpt = 0;
    for(int i=0; i < 3 ; i++){
        if(mymap.find({y-i-1, x+1+i})!=mymap.end()){
            if(mymap[{y-i-1, x+1+i}] == myvec[i]){
              cmpt++;
            }
        }
        if(cmpt == 3){
            result++;
            cmpt = 0;
        }
    }
    cmpt = 0;
    for(int i=0; i < 3 ; i++){
        if(mymap.find({y+i+1, x-1-i})!=mymap.end()){
            if(mymap[{y+i+1, x-1-i}] == myvec[i]){
              cmpt++;
            }
        }
        if(cmpt == 3){
            result++;
            cmpt = 0;
        }
    }
    cmpt = 0;
    for(int i=0; i < 3 ; i++){
        if(mymap.find({y+i+1, x+1+i})!=mymap.end()){
            if(mymap[{y+i+1, x+1+i}] == myvec[i]){
              cmpt++;
            }
        }
        if(cmpt == 3){
            result++;
            cmpt = 0;
        }
    }
    cmpt = 0;
    return result;
}

int main(){
    int tmp;
    int result = 0;
    int y = 0;
    std::map<std::vector<int>, char> mymap;
    std::vector<char> vec_one;
    std::ifstream inputFile("test.txt");
    if(!inputFile){
        std::cerr<<"Error : cannot open file ! "<<std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(inputFile, line)){
        std::stringstream ss(line);
        char c;
        while(ss >> c){
            vec_one.push_back(c);
        }
        for(int i=0; i<vec_one.size(); i++){
            mymap[{y, i}] = vec_one[i];
        }
        vec_one.clear();
        y++;
    }    
    for(const auto& pair : mymap){
        if(pair.second == 'X'){
            result += helper(mymap, pair.first[1], pair.first[0]);
        }
    }
    std::cout<<"this is reslut : "<<result<<std::endl;
}

/*for (const auto& pair : mymap) {*/
/*    std::cout << "Coordinate: ("*/
/*              << pair.first[0] << ", " << pair.first[1]*/
/*              << ") -> Value: " << pair.second << '\n';*/
/*}*/


