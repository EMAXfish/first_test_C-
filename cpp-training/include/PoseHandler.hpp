#pragma once
#include"Executor.hpp"
namespace adas{
class PoseHandler final:public Executor
{
    public:
      PoseHandler(const Pose&pose)noexcept;
      PoseHandler(const PoseHandler&)=delete;
      PoseHandler& operator=(const PoseHandler&)=delete;

    public:
      void Move()noexcept;
      void FastModAct()noexcept;
      void TurnLeft()noexcept;
      void TurnRight()noexcept;
      void ChangeDirection()noexcept;
      bool IsFast(void) const noexcept;
      Pose Quevy()noexcept;
    
    private:
      Pose pose;


};
 

};
