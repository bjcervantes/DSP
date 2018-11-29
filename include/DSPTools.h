#ifndef DSPTOOLS_H
#define DSPTOOLS_H


class DSPTools
{
    // properties

    // Methods
 public:
   DSPTools();
   virtual ~DSPTools();
   double calc_signal_mean(double *sig_src_arr, int sig_length);
   double calc_signal_variance(double* sig_src_arr, double sig_mean, int sig_length);
};

#endif // DSPTOOLS_H
