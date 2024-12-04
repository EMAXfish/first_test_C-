#include"Executor.h"
class ExecutorImpl final : public Executor
{
private:
class ICommand
    {
    public:
    virtual ~ICommand() = default;
    virtual void DoOperate(ExecutorImpl& executor) const noexcept = 0;
  };
public:
void Execute(const std::string& commands) noexcept;
class MoveCommand final:public ICommand
    {
    public:
        void DoOperate(ExecutorImpl& executor) const noexcept override
        {
            executor.Move();
        }
    };
class TurnLeftCommand final:public ICommand
{
public:
    void DoOperate(ExecutorImpl& executor) const noexcept override
    {
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
            /* code */
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

int test(void);