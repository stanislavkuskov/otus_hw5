#include <iostream>
#include <vector>
#include <list>
#include <tuple>


// для string
void print_ip(const std::string& ip)
{
    std::cout << ip << std::endl;
}

// для остальных (char, short etc)
template<typename T> std::enable_if_t <std::is_integral_v<T>, void>
print_ip(const T & ip){
//    https://stackoverflow.com/questions/1680365/integer-to-ip-address-c
//  full-stackoverflow developement
    std::cout <<
    ((ip >> 24) & 0xFF) << "." <<
    ((ip >> 16) & 0xFF) << "." <<
    ((ip >> 8) & 0xFF) << "." <<
    (ip & 0xFF) <<
    std::endl;
}

// для вектора и листа
template<typename T>
std::enable_if_t <
        std::is_same_v<T, std::vector<typename T::value_type>> ||
        std::is_same_v<T, std::list<typename T::value_type>>,
        void>
print_ip(const T& ip)
{
    for (auto oct = ip.cbegin(); oct != ip.cend(); ++oct)
    {
        if (oct != ip.cbegin())
        {
            std::cout << ".";
        }
        std::cout << *oct;
    }
    std::cout << std::endl;
}


int main() {

    print_ip(char(-1));
    std::cout << std::endl;

    print_ip(short(0));
    std::cout << std::endl;

    print_ip(int(2130706433));
    std::cout << std::endl;

    print_ip(long(8875824491850138409));
    std::cout << std::endl;

    print_ip(std::string("1.1.1.1"));
    std::cout << std::endl;

    print_ip(std::vector<int>{192, 168, 1, 1});
    std::cout << std::endl;

    print_ip(std::list<int>{192, 168, 1, 3});
    std::cout << std::endl;

}
