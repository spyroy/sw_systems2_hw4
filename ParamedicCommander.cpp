#include <iostream>
#include <string>
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "Board.hpp"

using namespace std;

void ParamedicCommander::abillity(vector<vector<Soldier *>> &b, std::pair<int,int> dest,int player){
    if(dest.first+1 < b.size() && b[dest.first+1][dest.second]!=nullptr && b[dest.first+1][dest.second]->getPlayer() == player){
        b[dest.first+1][dest.second]->Take_Hit(-50,b,{dest.first+1,dest.second});
    }
    if(dest.second+1 < b[0].size() && b[dest.first][dest.second+1]!=nullptr && b[dest.first][dest.second+1]->getPlayer() == player){
        b[dest.first][dest.second+1]->Take_Hit(-50,b,{dest.first,dest.second+1});
    }
    if(dest.first+1 < b.size() && dest.second+1 < b[0].size() && b[dest.first+1][dest.second+1]!=nullptr && b[dest.first+1][dest.second+1]->getPlayer() == player){
        b[dest.first+1][dest.second+1]->Take_Hit(-50,b,{dest.first+1,dest.second+1});
    }
    if(dest.first-1 >= 0 && b[dest.first-1][dest.second]!=nullptr && b[dest.first-1][dest.second]->getPlayer() == player){
        b[dest.first-1][dest.second]->Take_Hit(-50,b,{dest.first-1,dest.second});
    }
    if(dest.second-1 >= 0 && b[dest.first][dest.second-1]!=nullptr && b[dest.first][dest.second-1]->getPlayer() == player){
        b[dest.first][dest.second-1]->Take_Hit(-50,b,{dest.first,dest.second-1});
    }
    if(dest.first-1 >= 0 && dest.second-1 >= 0 && b[dest.first-1][dest.second-1]!=nullptr && b[dest.first-1][dest.second-1]->getPlayer() == player){
        b[dest.first-1][dest.second-1]->Take_Hit(-50,b,{dest.first-1,dest.second-1});
    }
    if(dest.first-1 >= 0 && dest.second+1 < b[0].size() && b[dest.first-1][dest.second+1]!=nullptr && b[dest.first-1][dest.second+1]->getPlayer() == player){
        b[dest.first-1][dest.second+1]->Take_Hit(-50,b,{dest.first-1,dest.second+1});
    }
    if(dest.first+1 < b.size() &&  dest.second-1 >= 0 && b[dest.first+1][dest.second-1]!=nullptr && b[dest.first+1][dest.second-1]->getPlayer() == player){
        b[dest.first+1][dest.second-1]->Take_Hit(-50,b,{dest.first+1,dest.second-1});
    }


    for(int i =0;i<b.size();i++){
	    for(int j=0;j<b.at(0).size();j++){   
            if(b[i][j] != nullptr && b[i][j]->getInstance() == "Paramedic" && b[i][j]->getPlayer() == player){
                b[i][j]->abillity(b,pair<int,int>{i,j},player);
            }
        }
    }
}