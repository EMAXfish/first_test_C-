#include "hello.h"
#include"iostream"
using namespace std;
enum  class heading {
    N,//0
    E,//1
    S,//2
    W//3
};
enum Inst {
    M,
    L,
    R
};
class CAR
{
private:
    int x, y;
    int x_direction, y_diretion;
    heading direction;
    char ShowDirection;

public:
    CAR(/* args */);
    void ComputeCoordinate(Inst Change) {
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
            x_direction = 0;
            y_diretion = 1;
            break;
        case heading::E:
            x_direction = 1;
            y_diretion = 0;
            break;
        case heading::S:
            x_direction = 0;
            y_diretion = -1;
            break;
        case heading::W:
            x_direction = -1;
            y_diretion = 0;
            break;
        }
        if (Change==Inst::M)
        {
            Move();
        }
        
    }
    void Move() {
        x += x_direction;
        y += y_diretion;
    }
    void CheckCoordinate() {
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
    void InitialBegin(int x,int y,heading cin_direction){
        this->x=x;this->y=y;this->direction=cin_direction;
    }
};

CAR::CAR()
{
    this->x = 0;this->y = 0;
    this->x_direction = 0;this->y_diretion = 0;
    this->direction = heading::N;
}

int test()
{
    CAR OneCar;
    string commands;
    int x,y;
    char cin_direction;
    heading InitialDirection;
    cout<<"Enter initial position:(ps:(x,y,direction))"<<endl;
    cin>>x>>y>>cin_direction;
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
    OneCar.InitialBegin(x,y,InitialDirection);
    cout << "Enter commands : ";
    cin >> commands;

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
        default:
            cout << "Invalid command: " << endl;
            continue;
        }

        OneCar.ComputeCoordinate(order);
    }

    OneCar.CheckCoordinate();
    cout << endl;
    return 0;
}
