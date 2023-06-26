#ifndef PART_H
#define PART_H

#include "Date.h"
#include <string>

class Facility;  // Forward declaration

using namespace std;

class Part {
private:
    Facility* _facility; // Change this to pointer to avoid circular dependency
    Date _datePayment;
    double _payment_amount;
    string _currency;
    double _interestAmountGenarated;

public:
    Part();
    ~Part();

    Facility* getFacility(); // Change this to pointer
    void setFacility(Facility* f); // Change this to pointer

    double getPaymentAmount();
    void setPaymentAmount(double p);

    Date getDatePayment();
    void setDatePayment(Date datePayment);

    double getInterestAmountGenarated();
    void setInterestAmountGenarated(double interestAmountGenarated);

    void setCurrency(string currency);
    string getCurrency();

    void displayInformation() const ;
};

#endif //PART_H
