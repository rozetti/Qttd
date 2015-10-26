#pragma once

#include <ctime>

class IMockableInterface;

class ExampleClass
{
public:
    ExampleClass(IMockableInterface const &);

    time_t getDuration() const;

private:
    IMockableInterface const &m_dependency;
};
