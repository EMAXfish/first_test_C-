#include <gtest/gtest.h>

#include "Executor.h"

TEST(ExecutorTest, test_case1)
{
    std::unique_ptr<ExecutorImpl>executor(static_cast<ExecutorImpl*>(ExecutorImpl::NewExecutor()));
    executor->InitialBegin(0,0,'N');
    //first test
    executor->Execute("FLMMF");
    adas::Pose target_1 {-4,1,heading::W};
    adas::Pose result_1=executor->Query();
    ASSERT_EQ(target_1,result_1);
}

TEST(ExecutorTest, test_case2)
{
    std::unique_ptr<ExecutorImpl>executor_2(static_cast<ExecutorImpl*>(ExecutorImpl::NewExecutor()));
    executor_2->InitialBegin(0,0,'N');
    //first test
    executor_2->Execute("MMFMRMMFM");
    adas::Pose target_2 {5,5,heading::E};
    adas::Pose result_2=executor_2->Query();
    ASSERT_EQ(target_2,result_2);
}