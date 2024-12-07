#include"Executor.hpp"
#include"ExecutorImpl.hpp"
#include<memory>
#include <unordered_map>
#include"Command.hpp"
void Executor::CheckCoordinate() {
        switch (direction) {
        case heading::N:
           ShowDirection='N';
            break;
        case heading::E:
            ShowDirection='E';
            break;
        case heading::S:
            ShowDirection='S';
            break;
        case heading::W:
            ShowDirection='W';
            break;
        }
        std::cout << "(" << x << "," << y <<","<<ShowDirection<< ")";
    }

void Executor::InitialBegin(int x,int y,char cin_direction){
    heading InitialDirection;
    switch (cin_direction)
    {
    case 'N':
        InitialDirection=heading::N;
        break;
    case 'E':
        InitialDirection=heading::E;
        break;
    case 'W':
        InitialDirection=heading::W;
        break;
    case 'S':
        InitialDirection=heading::S;
        break;
    default:std::cout<<"Invalid initial"<<std::endl;
    exit(0);
        break;
    }
    ChangeDirection();
        this->x=x;this->y=y;this->direction=InitialDirection;
}

void Executor::FastModAct(){
    FastMod=!FastMod;
}

void Executor::Move() {
        x += xDirection;
        y += yDirection;
    }

void Executor::TurnLeft(){
    int dir = static_cast<int>(direction);
    dir = (dir - 1 + 4) % 4;
    direction = static_cast<heading>(dir);
    ChangeDirection();
}

void Executor::TurnRight(){
    int dir = static_cast<int>(direction);
    dir = (dir +1) % 4;
    direction = static_cast<heading>(dir);
    ChangeDirection();
}

void Executor::BackModAct(){
    xDirection*=-1;
    yDirection*=-1;
    BackMod=!BackMod;
}

void Executor::ChangeDirection(){
    switch (direction) {
        case heading::N:
            xDirection = 0;
            yDirection = 1;
            break;
        case heading::E:
            xDirection = 1;
            yDirection = 0;
            break;
        case heading::S:
            xDirection = 0;
            yDirection = -1;
            break;
        case heading::W:
            xDirection = -1;
            yDirection = 0;
            break;
        }
    if (BackMod)
    {
        xDirection*=-1;
        yDirection*=-1;
    }
    
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    std::unordered_map<char,std::unique_ptr<adas::ICommand>>cmderMap;
    cmderMap.emplace('M', std::make_unique<adas::MoveCommand>());
    cmderMap.emplace('L', std::make_unique<adas::TurnLeftCommand>());
    cmderMap.emplace('R', std::make_unique<adas::TurnRightCommand>());
    cmderMap.emplace('F', std::make_unique<adas::FastModeCommand>());
    cmderMap.emplace('B', std::make_unique<adas::BackModeCommand>());

    for (const auto cmd : commands) {
       const auto it=cmderMap.find(cmd);

       if (it!=cmderMap.end())
       {
        it->second->DoOperate(*this);
       }
       
      
      
   }
}


