#ifndef ISO2022_JP_H
#define ISO2022_JP_H

#include <tuple>
#include "checker.h"

typedef function<bool(const uchar* str)> iso2022_jp_func_type;
typedef pair<int,iso2022_jp_func_type> iso2022_jp_pair;

class ISO2022_JPChecker:CheckerBase
{
public:
    ISO2022_JPChecker();
    bool detect(string str) const;
private:
    tuple<bool,iso2022_jp_pair> check_flag(const char* &str)const;
};

#endif // ISO2022_JP_H
