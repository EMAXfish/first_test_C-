#include <gtest/gtest.h>
#include "Executor.hpp"
#include"ExecutorImpl.hpp"
/*TEST(ExecutorTest, test_case1)
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

TEST(ExecutorTest, test_case3)
{
    std::unique_ptr<ExecutorImpl>executor_3(static_cast<ExecutorImpl*>(ExecutorImpl::NewExecutor()));
    executor_3->InitialBegin(0,0,'N');
    //first test
    executor_3->Execute("BMMLM");
    adas::Pose target_3 {-1,-2,heading::E};
    adas::Pose result_3=executor_3->Query();
    ASSERT_EQ(target_3,result_3);
}

TEST(ExecutorTest, test_case4)
{
    std::unique_ptr<ExecutorImpl>executor_4(static_cast<ExecutorImpl*>(ExecutorImpl::NewExecutor()));
    executor_4->InitialBegin(0,0,'N');
    //first test
    executor_4->Execute("MLMRMFMLMBMLFMBM");
    adas::Pose target_4 {0,5,heading::N};
    adas::Pose result_4=executor_4->Query();
    ASSERT_EQ(target_4,result_4);
}*/

TEST(Executor911Test, test_case1)
{
    std::unique_ptr<Executor911>executor(static_cast<Executor911*>(Executor911::NewExecutor()));
    executor->InitialBegin(0,0,'N');
    executor->Execute("M");
    adas::Pose target_1 {0,2,heading::N};
    adas::Pose result_1=executor->Query();
    ASSERT_EQ(target_1,result_1);
}
TEST(Executor911Test, test_case2)
{
    std::unique_ptr<Executor911>executor(static_cast<Executor911*>(Executor911::NewExecutor()));
    executor->InitialBegin(0,0,'N');
    executor->Execute("L");
    adas::Pose target_2 {-1,0,heading::W};
    adas::Pose result_2=executor->Query();
    ASSERT_EQ(target_2,result_2);
}
TEST(Executor911Test, test_case3)
{
    std::unique_ptr<Executor911>executor(static_cast<Executor911*>(Executor911::NewExecutor()));
    executor->InitialBegin(0,0,'N');
    executor->Execute("FML");
    adas::Pose target_3 {-1,4,heading::W};
    adas::Pose result_3=executor->Query();
    ASSERT_EQ(target_3,result_3);
}
TEST(Executor911Test, test_case4)
{
    std::unique_ptr<Executor911>executor(static_cast<Executor911*>(Executor911::NewExecutor()));
    executor->InitialBegin(0,0,'N');
    executor->Execute("FBMLM");
    adas::Pose target_4 {-4,-4,heading::E};
    adas::Pose result_4=executor->Query();
    ASSERT_EQ(target_4,result_4);
}