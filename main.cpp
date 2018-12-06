#include <iostream>
#include "waveforms.h"
#include "DSPTools.h"
#include "stdio.h"

using namespace std;

const int SIG_LENGTH = 320;

double MEAN = 0.0;
double VARIANCE = 0.0;
double STD;

int main()
{
    DSPTools m_DSP;
    MEAN = m_DSP.calc_signal_mean(InputSignal_f32_1kHz_15kHz, SIG_LENGTH);
    VARIANCE = m_DSP.calc_signal_variance(InputSignal_f32_1kHz_15kHz, MEAN, SIG_LENGTH);
    STD = m_DSP.calc_signal_std(VARIANCE);
    printf("\n\n Mean = %lf\n variance=%lf\n Standard-Deviation=%lf\n\n", MEAN, VARIANCE, STD);
    return 0;
}
