#ifndef LENDER_H
#define LENDER_H

#include "Company.h"
#include <vector>

class Lender : public Company {
private:
    double _interestRate;

public:
    Lender();
    Lender(std::string codeID, std::string name, std::string address, std::string phone_number, double interestRate);
    ~Lender();

    double getInterestRate();
    void setInterestRate(double _interestRate);

    void displayInformation() const override;
};

#endif //LENDER_H
