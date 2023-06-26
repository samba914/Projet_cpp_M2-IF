#ifndef BORROWER_H
#define BORROWER_H

#include "Company.h"

class Borrower : public Company {
private:
    std::string _industry;

public:
    Borrower();
    Borrower(std::string codeID, std::string name, std::string address, std::string phone_number, std::string industry);
    ~Borrower();

    std::string getIndustry();
    void setIndustry(std::string industry);

    void displayInformation() const override;

};

#endif //BORROWER_H
