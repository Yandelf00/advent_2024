#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>

int helper(std::map<std::pair<int,int>, char> mymap, int x, int y){
    int result = 0;
    auto it1 = mymap.find({y+1, x+1});
    auto it2 = mymap.find({y-1, x-1});
    auto it3 = mymap.find({y-1, x+1});
    auto it4 = mymap.find({y+1, x-1});
    bool condition = (it1 != mymap.end() && it2 != mymap.end() && it3 != mymap.end() && it4 != mymap.end());
    if(condition){
        if(it1->second == 'M' && it4->second == 'M' && it2->second == 'S' && it3->second == 'S') return 1;
        if(it1->second == 'M' && it4->second == 'S' && it2->second == 'S' && it3->second == 'M') return 1;
        if(it1->second == 'S' && it4->second == 'M' && it2->second == 'M' && it3->second == 'S') return 1;
        if(it1->second == 'S' && it4->second == 'S' && it2->second == 'M' && it3->second == 'M') return 1;

    }
    return result;
}

int main(){
    int tmp;
    int result = 0;
    int y = 0;
    std::map<std::pair<int, int>, char> mymap;
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
        if(pair.second == 'A'){
            result += helper(mymap, pair.first.second , pair.first.first);
        }
    }
    std::cout<<"this is reslut : "<<result<<std::endl;
}
