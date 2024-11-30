#include"Executor.h"
#include<memory>
void Executor::ComputeCoordinate(Inst Change) {
        if (this->FastMod==true&&Change!=F)
        {
            Move();
        }
        
        int dir = static_cast<int>(direction);
        if (Change == Inst::L) {
            dir = (dir - 1 + 4) % 4;
        }
        else if (Change == Inst::R) {
            dir = (dir + 1) % 4;
        }
        direction = static_cast<heading>(dir);

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
        if (Change==Inst::M)
        {
            Move();
        }
        
    }
void Executor::Move() {
        x += xDirection;
        y += yDirection;
    }
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
        this->x=x;this->y=y;this->direction=InitialDirection;this->FastMod=false;
}
void Executor::GetCommands(string commands){
        for (char command : commands) {
        Inst order;
        switch (command) {
        case 'M':
            order = Inst::M;
            break;
        case 'L':
            order = Inst::L;
            break;
        case 'R':
            order = Inst::R;
            break;
        case 'F':
            this->FastMod=!FastMod;
            order=F;
            break;
        default:
            cout << "Invalid command: " << endl;
            continue;
        }
        ComputeCoordinate(order);
    }
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

   
    
int test()

{
    Executor OneCar;
    string commands;
    int x,y;
    char cin_direction;
    cout<<"Enter initial position:(ps:(x,y,direction))"<<endl;
    cin>>x>>y>>cin_direction;
    OneCar.InitialBegin(x,y,cin_direction);
    cout << "Enter commands : ";
    cin >> commands;
    OneCar.InitialBegin(x,y,cin_direction);
    OneCar.GetCommands(commands);
    OneCar.CheckCoordinate();
    cout << endl;
    return 0;
}