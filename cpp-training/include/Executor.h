#pragma once
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
    R,
    F
};

namespace adas {
    struct Pose {
        int x;
        int y;
        heading direction;
        Pose(int x, int y, heading direction) : x(x), y(y), direction(heading::N) {}
        bool operator==(const Pose& other) const {
            return x == other.x && y == other.y && direction == other.direction;
        }
    };
}

class Executor
{
private:
    int x, y;
    int xDirection, yDirection;
    heading direction;
    char ShowDirection;

public:
    bool FastMod;
    Executor():x(0), y(0), xDirection(0), yDirection(0), direction(heading::N),ShowDirection('N'),FastMod(false) {}
    void Move() ;
    void CheckCoordinate() ;
    void InitialBegin(int x,int y,char cin_direction);
    static Executor* NewExecutor() {
    return new Executor();}
    adas::Pose Query()const{
        return adas::Pose(this->x,this->y,this->direction);
    }
    void FastModAct();
    void FastModMove();
    void TurnLeft();
    void TurnRight();
    void ChangeDirection();
    
};

int test(void);