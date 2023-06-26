#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <vector>
#include <map>

class Deal;

class Portfolio {
private:
    Deal *_deal;
    // Mapping from lender name to the amount of interest they have earned.
    std::map<std::string, double> _interests;

public:
    Portfolio();
    ~Portfolio();

    void setDeal(Deal* d);

    double getIterestTotalAmount();
// Add interest to a lender's total.
    void addInterest(std::string lenderName, double interest);

    // Get the total interest earned by a lender.
    double getInterestLender(std::string lenderName);

    std::map<std::string, double> getInterestMap();

};

#endif //PORTFOLIO_H
