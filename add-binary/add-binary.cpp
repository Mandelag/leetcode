#include <iostream>
#include <string>
#include <bitset>
#include <cmath> 

int main(int argc, char ** argv) {
    // I've been had!!! 
    // Forget to see the input data properly
    const std::string a{"0001"};
    const std::string b{"0010"};
    const std::size_t size{a.size() + b.size()};

    try {
        const std::bitset<64> _a{a};
        const std::bitset<64> _b{b};
        const std::bitset<64> _r{_a.to_ulong() + _b.to_ulong()};

        const std::string result{_r.to_string()};
        std::cout << "the result is: " << result << "\n";

        const std::string processed_result{result.substr(result.size() - (std::log2(size) + 1), result.size())};

        std::cout << "the processed result is: " << processed_result << "\n";

    } catch (const std::invalid_argument & ex) {
        // TODO
        std::cerr << "ggwp" << "\n";
    } catch (const std::out_of_range & ex) {
        // TODO
        std::cerr << "hehe" << "\n";
    }
}

