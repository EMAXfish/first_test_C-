#include <gtest/gtest.h>

#include "Executor.h"

TEST(ExecutorTest, test_case1)
{
    std::unique_ptr<Executor>executor(Executor::NewExecutor());
    executor->InitialBegin(0,0,'N');
    //first test
    executor->GetCommands("MMLMM");
    adas::Pose target_1 {-2,2,heading::W};
    adas::Pose result_1=executor->Query();
    ASSERT_EQ(target_1,result_1);
}