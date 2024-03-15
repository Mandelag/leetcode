#include <iostream>


int main(int argc, char ** argv) {
    std::string a{"010001"}; // both are not const, since we will modify them in our algorithm
    std::string b{"111101"};

   
    std::string * large_refs; // https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
    int minimum_length;
    if(a.size() > b.size()) {
        large_refs = &a;
        minimum_length = b.size();
    } else {
       large_refs = &b;
       minimum_length = a.size();
    }
    std::cout << *large_refs << "\n";
    std::cout << minimum_length << "\n";

    int carry_over{0};

    for (int i{0}; i < minimum_length; i++) {
        const char v1 = a.at(a.size() - 1 - i);
        const char v2 = b.at(b.size() - 1 - i);

        char * p = &(*large_refs)[large_refs->size() - 1 - i];

        if (*p == '0' && carry_over == 1) {
            *p = '1';
            carry_over = 0;
        } else if (*p == '1' && carry_over == 1) {
            *p = '0';
            carry_over = 0;
        }

        if (v1 == '0' && v2 == '0') {
            continue;
        }
        if (v1 == '1' && v2 == '1') {
            *p = '0';
            carry_over = 1;
            continue;
        } 
        *p = '1';
    }
    
    if (carry_over == 1) {
        std::cout << "result: " << "1" << (*large_refs) << "\n";
        return 0; 
    }
    std::cout << "result: " << (*large_refs) << "\n";
}

