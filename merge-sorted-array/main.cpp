#include <iostream>
#include <vector>
#include <algorithm> 
#include <iterator> 
#include <climits>

int main() {
    size_t lx{7};
    std::vector<int> x{5, 6, 10, 12, 20, 90, 100, 0, 0, 0, 0, 0};
    
    size_t ly{5};
    std::vector<int> y{3, 6, 9, 99, 101};

    std::vector<int> xcopy;
    xcopy.reserve(x.size());

    // std::copy(std::begin(x), std::end(x), std::back_inserter(xcopy));
    

    size_t j{0};

    for (size_t i{0};i < lx || j < ly;) {
        int vx{INT_MAX};
        int vy{INT_MIN};

        if (i < lx) {
            vx = x.at(i);
        } 

        if (j < ly) {
            vy = y.at(j);
        }

        if (vx < vy) {
            xcopy.push_back(vx);
            i++;
            continue;
        }
        xcopy.push_back(vy);
        j++;
    }


    for (const auto &i : xcopy) {
        std::cout << i << ", ";
    }

}
