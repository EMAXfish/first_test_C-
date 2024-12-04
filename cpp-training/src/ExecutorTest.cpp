#include"Executor.h"
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
      if (cmd=='F')
      {
        std::unique_ptr<FastModeCommand>cmder=
        std::make_unique<FastModeCommand>();
        cmder->DoOperate(*this);
      }
      
      if (cmd =='M')
      {
        std::unique_ptr<MoveCommand>cmder=
        std::make_unique<MoveCommand>();
        cmder->DoOperate(*this);
      }
      if (cmd=='L')
      {
        std::unique_ptr<TurnLeftCommand>cmder=
        std::make_unique<TurnLeftCommand>();
        cmder->DoOperate(*this);
      }
      if (cmd=='R')
      {
        std::unique_ptr<TurnRightCommand>cmder=
        std::make_unique<TurnRightCommand>();
        cmder->DoOperate(*this);
      }
      
   }
}

   
