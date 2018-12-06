#include "DSPTools.h"
#include <math.h>

DSPTools::DSPTools()
{
}

DSPTools::~DSPTools()
{
}

double DSPTools::calc_signal_mean(double *sig_src_arr, int sig_length)
{
    double mean = 0.;

    for(int i = 0; i<sig_length; i++)
    {
        mean += sig_src_arr[i];
    }

    mean /= (double)sig_length;

    return mean;
}

double DSPTools::calc_signal_variance(double* sig_src_arr, double sig_mean, int sig_length)
{
    double variance = 0.0;
    for(int i= 0; i<sig_length; i++)
    {
        variance += pow((sig_src_arr[i] - sig_mean), 2);
    }
    variance /= (sig_length - 1);
    return variance;
}

double DSPTools::calc_signal_std(double signal_variance)
{
    return sqrt(signal_variance);
}
