
#include <iostream>


void test(int a) {
    std::cout << "Test function called" << std::endl;
    if (a == 0) {
        throw "a is zero";
    }

}

int main() {

    int a = 5;

    try {
        while (a > 0)
        {
            a--;
        }
         test(a);
         std::cout << "a is now: " << a << std::endl;

        }
    catch (const char* msg)
    {
        std::cout << "Caught exception: " << msg << std::endl;
    }
    std::cout << "End of program" << std::endl;
    return 0;
}