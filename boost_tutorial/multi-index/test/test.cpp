
#include "container.h"
#include "gtest/gtest.h"

class ContainerTest : public testing::Test {
public:
	ContainerTest() : d_e1(1, "Zach"), d_e2(2,"Jed"), d_e3(3, "Alex") {}
protected:
	virtual void SetUp() {
		
		d_ec.add(d_e1);
		d_ec.add(d_e2);
		d_ec.add(d_e3);
	}

	virtual void TearDown() {
		d_ec.clear();
	}

	EmployeeContainer d_ec;
	Employee d_e1;
	Employee d_e2;
	Employee d_e3;

};

TEST_F(ContainerTest, Construction) {
  
	d_ec.printByname();
  	EXPECT_EQ(1, 1);
}


// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?

