#include"Executor.hpp"
#include"ExecutorImpl.hpp"
#include<memory>
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
    for (const auto cmd : commands) {
       std::unique_ptr<adas::ICommand>cmder; 
      if (cmd=='F')
      {
       cmder=std::make_unique<adas::FastModeCommand>();
      }
      
      if (cmd =='M')
      {
        cmder=std::make_unique<adas::MoveCommand>();
      }
      if (cmd=='L')
      {
        cmder=std::make_unique<adas::TurnLeftCommand>();
      }
      if (cmd=='R')
      {
        cmder=std::make_unique<adas::TurnRightCommand>();
      }
      if (cmd=='B')
      {
        cmder=std::make_unique<adas::BackModeCommand>();
      }
      
      if (cmder)
      {
        cmder->DoOperate(*this);
      }
      
      
   }
}


