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
        auto expected = 1729 - 42;

        SomeMock mock;
        EXPECT_CALL(mock, getStartTime()).WillOnce(Return(42));
        EXPECT_CALL(mock, getEndTime()).WillOnce(Return(1729));

        ExampleClass sut(mock);

        auto actual = sut.getDuration();

        QCOMPARE(actual, expected);
    }
};

CGD_QTEST_QMOCK_APPLESS_MAIN(ExampleClassTests)

#include "ExampleClassTests.moc"
