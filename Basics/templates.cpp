#include <iostream>
template <typename T, typename U>

auto max(T x, U y) {
    return (x > y) ? x : y;
}

int main(){
    std::cout << max(5, 6) << std::endl;
    std::cout << max(5.5, 6.6) << std::endl;
    std::cout << max(5, 6.6) << std::endl;
    std::cout << max(5.5, 6) << std::endl;
    std::cout << max('a', 'b') << std::endl;
    std::cout << max("Hello", "World") << std::endl;
    return 0;
}