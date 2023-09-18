#include "ButterworthFilter.h"
#include <iostream>
#include <vector>

int main() {
    int order = 4;
    double cutoffFreq = 0.1;

    ButterworthFilter butterworth(order, cutoffFreq);

    std::vector<double> inputData = {1.0, 2.0, 3.0, 4.0, 5.0};

    std::cout << "Input data: ";
    for (double val : inputData) {
        std::cout << val << " ";
    }
    std::cout << "\nFiltered data: ";

    for (double val : inputData) {
        double filteredVal = butterworth.filter(val);
        std::cout << filteredVal << " ";
    }

    std::cout << std::endl;

    return 0;
}