#include <iostream>
#include <sstream>
#include <algorithm>

int main() {
    std::cout << "Hello World\n";

    std::string a_string{"THIS is AA string :)"};
    std::string_view sv{"GGWP"};
    std::cout << a_string << "\n" << sv << "\n";

    std::ostringstream buf; 

    buf << "H" << "e" << "ll" << "o" << " S" << "e" << "k" << "ai";
    std::cout << buf.str() << "\n";

    auto buf_copy{ buf.str() };
    std::cout << "again, " << buf_copy << "\n"; 

    std::transform(std::begin(buf_copy), std::end(buf_copy), std::begin(buf_copy), ::toupper);
    std::cout << buf_copy << "\n";

    // This is intriguing, the std::string fill constructor
    std::string ggwp(100, '.');
    std::cout << ggwp << "\n";
}
