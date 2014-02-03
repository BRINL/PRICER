///////////////////////  MonteCarlo.cpp ////////////////////////
//  Ici, on simule le cours de l'action, on calcule la valeur de l'option, jusqu'à ce que la variation de cette valeur soit inférieure à 0.01 //


#include "MonteCarlo.h"
#include "Genealeatoire.h"
# include <cmath>

/// ????? ////
#if !defined(_MSC_VER)
using namespace std;
#endif

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
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot=movedSpot*exp(Rootvariance*thisGaussian);
        double thisPayoff = thePayOff(thisSpot);
        runningSum+=thisPayoff;
    }
    
    double mean=runningSum/NumberOfPaths;
    
    mean*=exp(-r*Expiry);
    
    return mean;

}