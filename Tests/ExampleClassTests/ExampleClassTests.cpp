#include "ethan_gmock_support.h"

#include "SutClass.h"
#include "ISomeClass.h"

class SomeMock : public ISomeClass
{
public:
    MOCK_CONST_METHOD0(getStartTime, time_t());
    MOCK_CONST_METHOD0(getEndTime, time_t());
};

class SomeClassTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:

    void getStartTime_returnsStartTime()
    {
        auto expected = 42;

        SomeMock mock;
        EXPECT_CALL(mock, getStartTime()).WillOnce(Return(expected));
        
        SomeClass sut;
        sut.setSomeDependency(&mock);

        auto actual = sut.getTime();

        QCOMPARE(actual, expected);
    }
};

CGD_QTEST_QMOCK_APPLESS_MAIN(SomeClassTests)

#include "SomeClassTests.moc"
