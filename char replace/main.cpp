#include <iostream>
#include <string>

string string::charReplace(char c1, char c2) {
    while(this->find(c1) != std::string::npos) {
        this->replace(this->find(c1), 1, c2);
    }
    return *this;
}


int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}
