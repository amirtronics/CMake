#include "ButterworthFilter.h"
#include <cmath>

ButterworthFilter::ButterworthFilter(int filterOrder, double cutoffFrequency)
    : order(filterOrder), cutoffFreq(cutoffFrequency) {
    calculateCoefficients();
}

void ButterworthFilter::calculateCoefficients() {
    bCoefficients.resize(order + 1);
    aCoefficients.resize(order + 1);

    double wc = tan(M_PI * cutoffFreq);
    double denom = 1.0 + sqrt(2.0) * wc + wc * wc;

    for (int i = 0; i <= order; ++i) {
        bCoefficients[i] = pow(wc, order - i);
        aCoefficients[i] = (i % 2 == 0 ? 1.0 : -1.0) * (order * choose(order, i)) / denom;
    }
}

double ButterworthFilter::filter(double input) {
    xHistory.push_back(input);
    yHistory.push_back(0.0);

    for (int i = 0; i <= order; ++i) {
        if (xHistory.size() > i) {
            yHistory.back() += bCoefficients[i] * xHistory[xHistory.size() - i - 1];
        }
        if (yHistory.size() > i && i > 0) {
            yHistory.back() -= aCoefficients[i] * yHistory[yHistory.size() - i - 1];
        }
    }

    return yHistory.back();
}

int ButterworthFilter::choose(int n, int k) {
    int res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}