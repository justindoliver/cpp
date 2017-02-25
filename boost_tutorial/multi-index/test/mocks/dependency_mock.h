#include <gmock/gmock.h>
#include <dependency.h>
#include <string>

class MockDependency : public Dependency
{
  public:
    MOCK_METHOD1(doTheThing, void(int x));
    MOCK_METHOD2(doTheOtherThing, void(int, int));
    MOCK_METHOD1(doTheSuperThing, int(const std::string &));
};