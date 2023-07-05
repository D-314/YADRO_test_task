#include "../inc/qamdemodulator.h"

std::vector<bool> QAMDemodulator::demodulate(const std::vector<std::complex<double>>& constellation)
{
    std::vector<bool> demodulatedBits;

    for (std::complex<double> point : constellation) {

        int GrayCodeI = (int)(round(((1 + point.real() * sqrt(2)) * (numAmpLevels - 1)) / 2));
        int GrayCodeQ = (int)(round(((1 - point.imag() * sqrt(2)) * (numAmpLevels - 1)) / 2));

        int symbol = GrayToBinary(GrayCodeI) * numAmpLevels + GrayToBinary(GrayCodeQ);

        for (unsigned int i = 0; i < bitsPerSymbol; i++) {
            bool bit = (symbol >> (bitsPerSymbol - 1 - i)) & 1;
            demodulatedBits.push_back(bit);
        }
    }

    return demodulatedBits;
}

// This function converts a reflected binary Gray code number to a binary number.
unsigned int QAMDemodulator::GrayToBinary(unsigned int  num)
{
    unsigned int  mask = num;
    while (mask) {           // Each Gray code bit is exclusive-ored with all more significant bits.
        mask >>= 1;
        num   ^= mask;
    }
    return num;
}
