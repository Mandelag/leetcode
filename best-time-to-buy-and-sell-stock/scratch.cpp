#include <iostream>
#include <vector>
#include <climits> 


void calculate(const std::vector<int> &data); 

int main() {
    
    std::vector<std::vector<int>> data {
        {0},
        {6,5,4,3,2,1},
        {1,2,3,4,5,6},
        {1,4,100,200}
    };

    for (const auto &datum : data) {
        calculate(datum);
    }


}


void calculate(const std::vector<int> & data) {
    
    int cuan{0};

    int cm{INT_MAX};  // current min

    for (size_t i{0}; i < data.size(); i++) {
       if (data.at(i) < cm) {
           cm = data.at(i);
       }

       int _cuan{data.at(i) - cm}; // current max cuan
       if (_cuan > cuan) {
            cuan = _cuan;
       }
    }


    std::cout << cuan << "\n";
}
