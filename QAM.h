#ifndef QAM_H
#define QAM_H

#include <cmath>

class QAM {
protected:
    unsigned int constellationSize; // количество точек в созвездии
    int numAmpLevels; // количество уровней амплитуд отдельно для каждой составляющей
    unsigned int bitsPerSymbol;
public:
    QAM(int size) : constellationSize(size), numAmpLevels(sqrt(constellationSize)), bitsPerSymbol(log2(constellationSize)) {}
};

#endif // QAM_H
