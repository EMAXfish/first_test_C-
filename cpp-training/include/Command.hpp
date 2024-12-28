#pragma once
#include"ExecutorImpl.hpp"
namespace adas{
    class ICommand
    {
    public:
    virtual ~ICommand() = default;
    virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
    virtual void DoOperate911(Executor911& executor)const noexcept = 0;
    virtual void DoOperateBus(ExecutorBus& executor)const noexcept =0;
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
        void DoOperate911(Executor911& executor) const noexcept override
        {
            executor.Move();
            if (executor.FastMod==true)
        {
            executor.Move();
        }
            executor.Move();
        }
        void DoOperateBus(ExecutorBus& executor) const noexcept override
        {
            executor.Move();
            if (executor.FastMod==true)
        {
            executor.Move();
        }
        }
    };
class TurnLeftCommand final:public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.FastMod)
        {
            executor.Move();
        }
        if (executor.BackMod)
        {
            executor.TurnRight();
        }
        else 
        {
            executor.TurnLeft();
        }
    }
    void DoOperate911(Executor911& executor) const noexcept override
        {
            if (executor.FastMod==true)
        {
            executor.Move();
        }
            if (executor.BackMod)
        {
            executor.TurnRight();
        }
        else 
        {
            executor.TurnLeft();
        }
            executor.Move();
        }
    void DoOperateBus(ExecutorBus& executor) const noexcept override
        {
            if (executor.FastMod==true)
        {
            executor.Move();
        }
            executor.Move();
            if (executor.BackMod)
        {
            executor.TurnRight();
        }
        else 
        {
            executor.TurnLeft();
        }
        }
};
class TurnRightCommand final:public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        if (executor.FastMod)
        {
            executor.Move();
        }
        if (executor.BackMod)
        {
            executor.TurnLeft();
        }
        else
        {
        executor.TurnRight();
        }
        
    }
    void DoOperate911(Executor911& executor) const noexcept override
        {
            if (executor.FastMod==true)
        {
            executor.Move();
        }
            if (executor.BackMod)
        {
            executor.TurnLeft();
        }
        else
        {
        executor.TurnRight();
        }
            executor.Move();
        }
    void DoOperateBus(ExecutorBus& executor) const noexcept override
        {
            if (executor.FastMod==true)
        {
            executor.Move();
        }
         executor.Move();
            if (executor.BackMod)
        {
            executor.TurnLeft();
        }
        else
        {
        executor.TurnRight();
        }
        }
};
class FastModeCommand final:public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        executor.FastModAct();
    }
    void DoOperate911(Executor911& executor) const noexcept override
    {
        executor.FastModAct();
    }
    void DoOperateBus(ExecutorBus& executor) const noexcept override
    {
        executor.FastModAct();
    }
};
class BackModeCommand final:public ICommand
{
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
        executor.BackModAct();
    }
    void DoOperate911(Executor911& executor) const noexcept override
    {
        executor.BackModAct();
    }
    void DoOperateBus(ExecutorBus& executor) const noexcept override
    {
        executor.BackModAct();
    }
};


};