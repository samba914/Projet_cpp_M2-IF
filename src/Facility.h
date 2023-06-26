#ifndef FACILITY_H
#define FACILITY_H

#include <map>
#include <string>
#include <vector>
#include "Lender.h"
#include "Date.h"
#include "Portfolio.h"

class Deal;
class Part; // Forward declaration

using namespace std;

class Facility {
    private:
        Deal* _deal;
        Date _startDate;
        Date _nextStartDate;
        Date _endDate;
        double _amount;
        double _remainingAmount;
        string _currency;
        double _interestAmount;
        vector<Lender> _lenders;
        map<string, double> _lenderPercentages;
        vector<Part*> _parts; 
        void calculateInterest(Part* part); 


    public:
        Facility();
        ~Facility();

        Deal* getDeal();
        void setDeal(Deal* deal);

        Date getStartDate();
        void setStartDate(Date sd);

        Date getNextStartDate();
        void setNextStartDate(Date sd);

        Date getEndDate();
        void setEndDate(Date ed);

        double getAmount();
        void setAmount(double a);

        string getCurrency();
        void setCurrency(string c);

        vector<Lender> getLenders();
        void setLenders(vector<Lender> l);
        void addLender(Lender lender);


        double getRemaingAmount();

        vector<Part*> getParts(); 

        void addPart(Part* part); 
       

        void displayInformation() const;

        double getLenderPercentage(const string& lenderName);

        void setLenderPercentage(const string& lenderName, double pourcentage);
};

#endif
