//
//  Genealeatoire.cpp


#include "Genealeatoire.h"
#include <cstdlib>
#include <cmath>
#include "math.h"
#include "time.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int rdtsc()
{
    __asm__ __volatile__("rdtsc");
    return 0;
}

double uRand()
{
    srand(rdtsc());
    return (rand() / double(RAND_MAX));
}

double gNormale(const double mu, const double sigma2)
{
    double r=sqrt(-2*log(uRand()));
    double t=2*M_PI*(uRand());
    double x=r*sin(t);
    return x;
}


int gPoisson(double lambda)
{
    double L=exp(-lambda);
    double p(1);
    int k(1);
    while (p>L)
    {
        p=p*rand();
        k+=1;
    }
    return (k-1);
}


