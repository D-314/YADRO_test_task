#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <vector>
#include <complex>
#include <random>
#include <cmath>
#include <ctime>
#include <QCustomPlot/qcustomplot.h>
#include "qammodulator.h"
#include "awgn.h"
#include "qamdemodulator.h"

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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iMultiSelect);
    ui->customPlot->axisRect()->setupFullAxesBox();
    connect( ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect( ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
    ui->customPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
    ui->customPlot->yAxis2->setScaleType(QCPAxis::stLogarithmic);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->customPlot->clearGraphs();//Если нужно, то очищаем все графики
    ui->customPlot->addGraph();//основной график
    unsigned int ModIndex = (int)ui->spinBox->value();
    unsigned int bitsPerSymbol=log2(ModIndex);
    QAMModulator modulator(ModIndex);  // Создаем модулятор QAM с размером созвездия 16
    AWGN awgn_channel;
    QAMDemodulator demodulator(ModIndex);  // Создаем демодулятор QAM с размером созвездия 16
    std::vector<double> BER, SNR;
    for (int idx = 0; idx < 21; idx ++) {
        SNR.push_back(idx);
        awgn_channel.set_SNR_dB((double)idx);
        int errors = 0; int  transmits = 0;
        std::complex<double> noise = 0;
        while ((errors < 10000) && (transmits < 100000)) {
            transmits += bitsPerSymbol;
            std::vector<bool> bits = generateRandomBits(bitsPerSymbol);
            std::vector<std::complex<double>> modulated = modulator.modulate(bits);  // Модуляция QAM
            std::vector<std::complex<double>> noisy = awgn_channel.addNoise(modulated);  // Добавление шума
            //std::vector<std::complex<double>> noisy = modulated;//awgn_channel.addNoise(modulated);  // Добавление шума
            std::vector<bool> demodulated = demodulator.demodulate(noisy);  // Демодуляция QAM
            for (unsigned int i = 0; i < bitsPerSymbol; i++) {
                if (bits[i] != demodulated[i]) errors++;
                noise += std::complex<double>(std::abs(noisy[i].real() - modulated[i].real()), std::abs(noisy[i].imag() - modulated[i].imag()));
            }
        }
        noise = std::complex<double>(noise.real()/(bitsPerSymbol*transmits), noise.imag()/(bitsPerSymbol*transmits));
        BER.push_back((float)errors/transmits);
        std::cout << '\t' << SNR.back() << '\t' << BER.back() << '\t' << errors << '/' << transmits << '\t' <<  noise << std::endl;
        ui->customPlot->graph(0)->addData(SNR.back(), BER.back()); //добавляем точки на график
    }

}

