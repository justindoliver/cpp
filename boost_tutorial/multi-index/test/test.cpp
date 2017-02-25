
#include "container.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mocks/dependency_mock.h"

using ::testing::Return;

class ContainerTest : public testing::Test
{
  public:
    ContainerTest() : d_ec(&d_mockDependency), d_e1(1, "Zach"), d_e2(2, "Jed"), d_e3(3, "Alex") {}
  protected:
    virtual void SetUp()
    {
        EXPECT_CALL(d_mockDependency, doTheThing(::testing::_)).Times(::testing::Exactly(3));
        d_ec.add(d_e1);
        d_ec.add(d_e2);
        d_ec.add(d_e3);
    }

    virtual void TearDown()
    {
        d_ec.clear();
    }

    MockDependency d_mockDependency;
    EmployeeContainer d_ec;
    Employee d_e1;
    Employee d_e2;
    Employee d_e3;
};

TEST_F(ContainerTest, add)
{
    EXPECT_CALL(d_mockDependency, doTheThing(::testing::_)).Times(::testing::Exactly(1));

    Employee e0(0, "Beth");
    EXPECT_TRUE(d_ec.add(e0));
}

TEST_F(ContainerTest, addDuplicate)
{
    EXPECT_CALL(d_mockDependency, doTheThing(::testing::_)).Times(::testing::Exactly(1));

    EXPECT_FALSE(d_ec.add(d_e1));
}

TEST_F(ContainerTest, printById)
{

    d_ec.printById();
    EXPECT_EQ(1, 1);
}

TEST_F(ContainerTest, printByname)
{

    EXPECT_CALL(d_mockDependency, doTheOtherThing(::testing::_, ::testing::_)).Times(::testing::AtLeast(2));
    d_ec.printByname();
    EXPECT_EQ(1, 1);
}

TEST_F(ContainerTest, findName)
{

    EXPECT_CALL(d_mockDependency, doTheSuperThing(::testing::StrEq("theArgument")))
        .Times(::testing::Exactly(2))
        .WillOnce(Return(100))
        .WillOnce(Return(200));

    Employee e;
    EXPECT_TRUE(d_ec.findByName("Zach", e));
    EXPECT_EQ("Zach", e.name);
    EXPECT_FALSE(d_ec.findByName("Bob", e));
}
