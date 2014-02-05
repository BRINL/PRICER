///////////////////////  MonteCarlo.cpp ////////////////////////
//  Ici, on simule le cours de l'action, on calcule la valeur de l'option, jusqu'à ce que la variation de cette valeur soit inférieure à 0.01 //


#include "MonteCarlo.h"
#include "PayOff.h"
#include "Genealeatoire.h"
#include <cstdlib>
#include <cmath>

using namespace std;

MonteCarlo::MonteCarlo(){};

MonteCarloB ::MonteCarloB(int TypeOption, double Strike, double Expiry, double Spot, double Vol, double r, long NumberOfPaths) :  m_Strike(Strike), m_Expiry(Expiry), m_Spot(Spot), m_Vol(Vol), m_r(r), m_NumberOfPaths(NumberOfPaths), m_PayOff(0), m_TypeOption(TypeOption)
{
    m_PayOff = new PayOffCall(Strike);
}

MonteCarloB::~MonteCarloB()
{
    delete m_PayOff;
}



double MonteCarloB::PrixCallB()
{
    double variance = m_Vol*m_Vol*m_Expiry;
    double Rootvariance = sqrt(variance);
    double demivar = -0.5*variance;
    
    double movedSpot = m_Spot*exp(m_r*m_Expiry+demivar);  // On calcule le plus possible toutes ces valeurs avant le MC car ainsi, elles ne seront pas recalculer à chaque boucle ! //
    double thisSpot;
    double runningSum=0;
    
    for (unsigned long i=0; i<m_NumberOfPaths;i++)
    {
        Normale  simu1(3,8);
        double thisGaussian = simu1.gNormale();
        thisSpot=movedSpot*exp(Rootvariance*thisGaussian);
        *m_PayOff= PayOffCall(m_Strike);
        double PayOffMC=m_PayOff->CalPayOff(thisSpot);
        runningSum+=PayOffMC;
        
    }
    
    double mean=runningSum/m_NumberOfPaths;
    
    mean*=exp(-m_r*m_Expiry);
    
    return mean;
}

/*
double SimpleMonteCarlo(const PayOff& thePayOff, double Expiry, double Spot, double Vol, double r, unsigned long NumberOfPaths)

{
    double variance = Vol*Vol*Expiry;
    double Rootvariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    
    double movedSpot = Spot*exp(r*Expiry+itoCorrection);  // On calcule le plus possible toutes ces valeurs avant le MC car ainsi, elles ne seront pas recalculer à chaque boucle ! //
    double thisSpot;
    double runningSum=0;
    
    for (unsigned long i=0; i<NumberOfPaths;i++)
    {
        Normale  simu1(3,8);
        double thisGaussian = simu1.gNormale();
        thisSpot=movedSpot*exp(Rootvariance*thisGaussian);
        double thisPayoff = thePayOff(thisSpot);
        runningSum+=thisPayoff;
    }
    
    double mean=runningSum/NumberOfPaths;
    
    mean*=exp(-r*Expiry);
    
    return mean;

}
*/