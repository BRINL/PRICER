//
//  MonteCarlo.h

#ifndef __PRICER__MonteCarlo__
#define __PRICER__MonteCarlo__

#include <iostream>
#include "PayOff.h"



class MonteCarlo
{
    public :
    MonteCarlo();
};

class MonteCarloB : public MonteCarlo
{
    public :
            MonteCarloB(int TypeOption, double Strike, double Expiry, double Spot, double Vol, double r, long NumberOfPaths);
            double PrixCallB();
    ~MonteCarloB();
    
    private :
    double m_Strike;
    double m_Expiry;
        double m_Spot;
        double m_Vol;
        double m_r;
        long m_NumberOfPaths;
        PayOffCall *m_PayOff;
        int m_TypeOption;
};




/*
double SimpleMonteCarlo(const PayOff& thePayOff, double Expiry, double Spot, double Vol, double r, unsigned long NumberOfPaths);

*/

#endif /* defined(__PRICER__MonteCarlo__) */
