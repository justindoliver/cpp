#pragma once

class Dependency
{
public:
    virtual void doTheThing( int x)
    {
        
    }
    virtual void doTheOtherThing( int y, int z )
    {

    }
    virtual int doTheSuperThing( const std::string& stringArg )
    {
        return 1;
    }    
};