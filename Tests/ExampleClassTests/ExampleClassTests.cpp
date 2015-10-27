#include "qttest_gmock_support.h"

#include "ExampleClass.h"
#include "IMockableInterface.h"

class SomeMock : public IMockableInterface
{
public:
    MOCK_CONST_METHOD0(getStartTime, time_t());
    MOCK_CONST_METHOD0(getEndTime, time_t());
};

class ExampleClassTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:

    void getStartTime_returnsStartTime()
    {
        const long start = 42;
        const long end = 1729;

        auto expected = end - start;

        SomeMock mock;
        EXPECT_CALL(mock, getStartTime()).WillOnce(Return(start));
        EXPECT_CALL(mock, getEndTime()).WillOnce(Return(end));

        ExampleClass sut(mock);

        auto actual = sut.getDuration();

        QCOMPARE((long)actual, (long)expected);
    }
};

CGD_QTEST_QMOCK_APPLESS_MAIN(ExampleClassTests)

#include "ExampleClassTests.moc"
