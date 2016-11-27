#ifndef CHECKER
#define CHECKER

// common used headers
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm> // transform
#include <functional>
using namespace std;

class CheckerBase
{
public:
    CheckerBase(string name);
    virtual bool detect(string str)const =0;
    static list<string> avaliable_charsets();
    static list<CheckerBase*> avaliable_checkers();
    static bool contains(string name);
    static CheckerBase* get_checker(string name);
public:
    const string name; // charset_name
protected:
    static map<string,CheckerBase*> all_checkers; // map is easy to find
};

#endif // CHECKER

