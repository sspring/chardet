#include "checker.h"

template<typename T>
auto get_keys(const T& m)
    ->list<typename T::key_type>
{
    list<typename T::key_type> ret;
    std::transform(begin(m),end(m),std::back_inserter(ret),
                   [](T::value_type v){
                    return v.first;
    });
    return ret;
}

template<typename T>
auto get_values(const T& m)
    ->list<typename T::mapped_type>
{
    list<typename T::mapped_type> ret;
    std::transform(begin(m),end(m),std::back_inserter(ret),
                   [](T::value_type v){
                    return v.second;
    });
    return ret;
}

map<string,CheckerBase*> CheckerBase::all_checkers = map<string,CheckerBase*>();
CheckerBase::CheckerBase(string name)
    :name(name)
{
    all_checkers[name]=this;
}

list<CheckerBase *> CheckerBase::avaliable_checkers()
{
    return get_values(all_checkers);
}

list<string> CheckerBase::avaliable_charsets()
{
    return get_keys(all_checkers);
}

bool CheckerBase::contains(string name)
{
    auto it = all_checkers.find(name);
    return it!=all_checkers.end();
}

CheckerBase *CheckerBase::get_checker(string name)
{
    auto it = all_checkers.find(name);
    if(it == all_checkers.end())
    {
        return nullptr;
    }
    else
    {
        return it->second;
    }
}
