#pragma once
#include"Executor.hpp"

class ExecutorImpl final : public Executor
{
public:

void Execute(const std::string& commands) noexcept;
};

int test(void);