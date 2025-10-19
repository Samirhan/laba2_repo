#include <iostream>
#include <windows.h>


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const char* lang = "C++";
    std::cout << "САУ " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        std::cout << "i = " << i << std::endl;
    }
    std::cout << "hello 01" << std::endl;
    return 0;
}
