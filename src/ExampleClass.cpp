#include "ExampleClass.h"
#include "IMockableInterface.h"

ExampleClass::ExampleClass(const IMockableInterface &dependency) :
    m_dependency(dependency)
{
}

time_t ExampleClass::getDuration() const
{
    return m_dependency.getEndTime() - m_dependency.getStartTime();
}

#include "ExampleClass.h"
