//
//  MonteCarlo.h


#ifndef __PRICER__MonteCarlo__
#define __PRICER__MonteCarlo__

#include <iostream>
#include "PayOff.h"


double SimpleMonteCarlo(const PayOff& thePayOff, double Expiry, double Spot, double Vol, double r, unsigned long NumberOfPaths);



#endif /* defined(__PRICER__MonteCarlo__) */
