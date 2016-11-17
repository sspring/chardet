#ifndef BIG5CHECKER
#define BIG5CHECKER

#include <vector>
#include <functional>

#define Big5_two_byte_func(min,max) \
    [](const uchar* s){ushort value=(*s<<8)+s[1];return value>=min && value<= max;}

std::vector<std::function<bool(const uchar*)> > Big5_two_byte_detect = {
        Big5_two_byte_func(0xa140,0xa3bf),
        Big5_two_byte_func(0xa440,0xc67e),
        Big5_two_byte_func(0xc940,0xf9d5)};

class Big5Checker:public CharsetChecker
{
public:
    Big5Checker():
        CharsetChecker()
    {
        this->charset_name = "big5";
    }

    bool detect(std::string str)const
    {
        int current_index = -1;
        int length = str.length();
        const uchar* buffer = (const uchar*)str.c_str();
        while(current_index+1 < length)
        {
            if(*buffer <= 0x7F)
            {
                current_index += 1;
                buffer += 1;
            }
            if(check_two_bytes(buffer))
            {
                current_index += 2;
                buffer += 2;
            }
            else
            {
                break;
            }
        }
        return (current_index+1 == length);
    }
private:
    bool check_two_bytes(const uchar* buffer)const
    {
        for(auto f:Big5_two_byte_detect)
        {
            if(f(buffer))
            {
                return true;
            }
        }
        return false;
    }
};
Big5Checker _big5checker = Big5Checker();

#endif // BIG5CHECKER

