#include <iostream>
#include <memory>

void procces_carry_over(char * p, int & carry_over);

int main(int argc, char ** argv) {
    // since both are not const, we will modify them in our algorithm to save space O(1)
    std::string a{"1"}; 
    std::string b{"110"};

  
    // O(n) process

    std::string * large_refs; // https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
    int minimum_size;
    if(a.size() > b.size()) {
        large_refs = &a;
        minimum_size = b.size();
    } else {
       large_refs = &b;
       minimum_size = a.size();
    }

    // handle sum at both string's intersection
    int carry_over{0};
    for (int i{0}; i < minimum_size; i++) {
        char * p = &(*large_refs)[large_refs->size() - 1 - i];
        procces_carry_over(p, carry_over);

        const char v1 = a.at(a.size() - 1 - i);
        const char v2 = b.at(b.size() - 1 - i);
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
    
    // handle the rest of the (largest) string..
    for (int i{(int)large_refs->size() - 1 - minimum_size}; i >= 0; i--) {
        procces_carry_over(&(*large_refs)[i], carry_over);
    }
    // char hello;
    std::cout << "Result: ";

    // if there is still a carry over, we add prefix
    if (carry_over == 1) {
        std::cout << "1";
    }
    std::cout << *large_refs << "\n";
}

void procces_carry_over(char * p, int & carry_over) {
    if (*p == '0' && carry_over == 1) {
        *p = '1';
        carry_over = 0;
    } else if (*p == '1' && carry_over == 1) {
        *p = '0';
    } 
}

