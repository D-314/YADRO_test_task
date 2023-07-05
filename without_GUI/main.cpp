#include <iostream>
#include <iomanip>

#include <vector>
#include <complex>
#include <random>
#include <cmath>

#include <ctime>

#include "../QAM_lib/inc/qammodulator.h"
#include "../QAM_lib/inc/awgn.h"
#include "../QAM_lib/inc/qamdemodulator.h"

std::vector<bool> generateRandomBits(int N) {
    static int counter = 0;
    counter ++;
    std::vector<bool> randomBits;

    // Получаем текущее системное время в секундах
    time_t currentTime = time(nullptr);

    // Используем текущее время в качестве входных данных
    srand(static_cast<unsigned int>(currentTime+counter));

    for (int i = 0; i < N; i++) {
        // Генерируем случайный бит (0 или 1)
        bool bit = rand() % 2;

        // Сохраняем бит в векторе
        randomBits.push_back(bit);
    }

    return randomBits;
}

int main() {
    unsigned int ModIndex = 64, bitsPerSymbol=log2(ModIndex);

    QAMModulator modulator(ModIndex);  // Создаем модулятор QAM с размером созвездия 16
    AWGN awgn_channel;
    QAMDemodulator demodulator(ModIndex);  // Создаем демодулятор QAM с размером созвездия 16

    std::vector<double> BER, SNR;
	
	std::cout << std::setprecision(2) << std::fixed;
	
    for (double snr = 0; snr < 21; snr += 0.25) {
        SNR.push_back(snr);
        awgn_channel.set_SNR_dB(snr);
        int errors = 0; int  transmits = 0;
        double noise = 0;

        while ((errors < 10000) && (transmits < 100000)) {

            transmits += bitsPerSymbol;

            std::vector<bool> bits = generateRandomBits(bitsPerSymbol);
            std::vector<std::complex<double>> modulated = modulator.modulate(bits);  // Модуляция QAM
            std::vector<std::complex<double>> noisy = awgn_channel.addNoise(modulated);  // Добавление шума
            std::vector<bool> demodulated = demodulator.demodulate(noisy);  // Демодуляция QAM

            for (unsigned int i = 0; i < bitsPerSymbol; i++) {
                if (bits[i] != demodulated[i]) errors++;
            }

            for (unsigned int i = 0; i < 1; i++) {
                noise += std::abs(noisy[i] - modulated[i]);
            }
        }

        noise = noise/transmits;

        BER.push_back((float)errors/transmits);

        std::cout << '\t' << SNR.back() << '\t' << BER.back() << '\t' << errors << '/' << transmits << '\t' <<  noise << std::endl;
    }
    return 16;
}
