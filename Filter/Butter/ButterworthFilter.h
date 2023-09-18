#ifndef BUTTERWORTH_FILTER_H
#define BUTTERWORTH_FILTER_H

#include <vector>

class ButterworthFilter {
private:
    int order;
    double cutoffFreq;
    std::vector<double> bCoefficients;
    std::vector<double> aCoefficients;
    std::vector<double> xHistory;
    std::vector<double> yHistory;

    void calculateCoefficients();

public:
    ButterworthFilter(int filterOrder, double cutoffFrequency);
    double filter(double input);

private:
    int choose(int n, int k);
};

#endif // BUTTERWORTH_FILTER_H