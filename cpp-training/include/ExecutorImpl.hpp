#pragma once
#include"Executor.h"

class ExecutorImpl final : public Executor
{
public:

void Execute(const std::string& commands) noexcept;
};

int test(void);