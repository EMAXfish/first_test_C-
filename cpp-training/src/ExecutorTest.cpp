#include"Executor.h"
#include"ExecutorImpl.hpp"
#include<memory>
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
        cout << "(" << x << "," << y <<","<<ShowDirection<< ")";
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
    default:cout<<"Invalid initial"<<endl;
    exit(0);
        break;
    }
    ChangeDirection();
        this->x=x;this->y=y;this->direction=InitialDirection;
}

void Executor::FastModAct(){
    FastMod=!FastMod;
}

void Executor::FastModMove(){
   x+=xDirection;
   y+=yDirection;
}

void Executor::Move() {
        if (FastMod)
        {
            FastModMove();
        }
        x += xDirection;
        y += yDirection;
    }

void Executor::TurnLeft(){
    if (FastMod)
    {
            FastModMove();
    }
    int dir = static_cast<int>(direction);
    dir = (dir - 1 + 4) % 4;
    direction = static_cast<heading>(dir);
    ChangeDirection();
}

void Executor::TurnRight(){
    if (FastMod)
    {
            FastModMove();
    }
    int dir = static_cast<int>(direction);
    dir = (dir +1) % 4;
    direction = static_cast<heading>(dir);
    ChangeDirection();
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
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    for (const auto cmd : commands) {
       std::unique_ptr<ICommand>cmder; 
      if (cmd=='F')
      {
       cmder=std::make_unique<FastModeCommand>();
      }
      
      if (cmd =='M')
      {
        cmder=std::make_unique<MoveCommand>();
      }
      if (cmd=='L')
      {
        cmder=std::make_unique<TurnLeftCommand>();
      }
      if (cmd=='R')
      {
        cmder=std::make_unique<TurnRightCommand>();
      }
      if (cmder)
      {
        cmder->DoOperate(*this);
      }
      
      
   }
}

   
