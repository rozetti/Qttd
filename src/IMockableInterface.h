#pragma once

#include <ctime>

class IMockableInterface
{
public:
    virtual time_t getStartTime() const = 0;
    virtual time_t getEndTime() const = 0;

protected:
    ~IMockableInterface() {}
};
