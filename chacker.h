#ifndef CHECKER
#define CHECKER

#include <string>

class CharacterChacker
{
public:
    virtual bool detect(std::string str)=0;
public:
    std::string character_name;
};

#endif // CHECKER

