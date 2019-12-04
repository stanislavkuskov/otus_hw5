#include <iostream>
#include <vector>
#include <list>
#include <tuple>


template<class T>
std::enable_if_t<std::is_integral_v<T>, std::string> print_ip(const T &);

template<class T>
std::enable_if_t<std::is_floating_point_v<T>, std::string> print_ip(const T &);


void print_ip(const char &ip)
{
    std::cout << ip << std::endl;
}

void print_ip(const short &ip)
{
    std::cout << ip << std::endl;
}

void print_ip(const long &ip)
{
    std::cout << ip << std::endl;
}

void print_ip(const std::string &ip)
{
    std::cout << ip << std::endl;
}

void print_ip(const int &ip)
{
    std::cout << ip << std::endl;
}

void print_ip(const double &ip)
{
    std::cout << ip << std::endl;
}

template <typename T>
void print_ip(const std::vector<T> &ip)
{
    for (const T& oct: ip){
        std::cout << oct << ".";
    }
    std::cout << std::endl;
}

template <typename T>
void print_ip(const std::list<T> &ip)
{
    for (const T& oct: ip){
        std::cout << oct << ".";
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

    print_ip(std::string("192.168.1.1"));
    std::cout << std::endl;

    print_ip(std::vector<int>{192, 168, 1, 1});
    std::cout << std::endl;

    print_ip(std::vector<std::string>{"192", "168", "1", "1"});
    std::cout << std::endl;

    print_ip(std::list<int>{192, 168, 1, 3});
    std::cout << std::endl;

    print_ip(std::list<std::string>{"192", "168", "1", "3"});
    std::cout << std::endl;

}
