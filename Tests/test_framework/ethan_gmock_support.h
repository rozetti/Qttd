#pragma once

#pragma GCC diagnostic ignored "-Wmissing-field-initializers" // cgd: gmock generates a few warnings
#include "gmock/gmock.h"
using namespace ::testing;

#include <QtTest>
#include <QSignalSpy>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
#define CGD_SET_MAIN_SOURCE_PATH QTEST_SET_MAIN_SOURCE_PATH
#else
#define CGD_SET_MAIN_SOURCE_PATH
#endif

#define CGD_QTEST_QMOCK_APPLESS_MAIN(TestObject) \
int main(int argc, char *argv[]) \
{ \
    ::testing::GTEST_FLAG(throw_on_failure) = true; \
    ::testing::InitGoogleMock(&argc, argv); \
    TestObject tc; \
    CGD_SET_MAIN_SOURCE_PATH \
    return QTest::qExec(&tc, argc, argv); \
}




