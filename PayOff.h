//
//  PayOff.h


#ifndef __PRICER__PayOff__
#define __PRICER__PayOff__

class PayOff // Classe mère PAYOFF

{
    public :
    PayOff();
};


class PayOffCall : public PayOff

{
    public :
        PayOffCall(double Strike);
        virtual double CalPayOff(double Spot) const;
        virtual ~PayOffCall(){} // Destructeur sans delete (pas d'allocation dynamique)
    private :
        double m_Strike;
};

class PayOffPut : public PayOff
{
    public :
        PayOffPut(double Strike);
        virtual double CalPayOff(double Spot) const ;
        virtual ~PayOffPut(){}
    private :
    double m_Strike;
  };

#endif


    
    
    
    

