#pragma once
#include"ExecutorImpl.hpp"
namespace adas{
    class ICommand
    {
    public:
    virtual ~ICommand() = default;
    virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
  };
class MoveCommand final:public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            if (executor.FastMod==true)
        {
            executor.Move();
        }
            executor.Move();
        }
    };
class TurnLeftCommand final:public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.FastMod==true)
        {
            executor.Move();
        }
        executor.TurnLeft();
    }
};
class TurnRightCommand final:public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.FastMod==true)
        {
            executor.Move();
        }
        
        executor.TurnRight();
    }
};
class FastModeCommand final:public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        executor.FastModAct();
    }
};

};