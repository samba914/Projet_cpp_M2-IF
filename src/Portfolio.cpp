#include "Portfolio.h"
#include "Deal.h"

Portfolio::Portfolio() { }

Portfolio::~Portfolio() { }

void Portfolio::setDeal(Deal* d) { _deal = d; }

double Portfolio::getIterestTotalAmount(){
    double sum = 0.0;
    for (const auto& pair : _interests) {
        sum += pair.second;
    }
    return sum;
}

void Portfolio::addInterest(std::string lenderName, double interest) {
    // If the lender already has some interest, add to it. Otherwise, set the interest.
    if (_interests.find(lenderName) != _interests.end()) {
        _interests[lenderName] += interest;
    } else {
        _interests[lenderName] = interest;
    }
}

double Portfolio::getInterestLender(std::string lenderName) {
    // If the lender has some interest, return it. Otherwise, return 0.
    if (_interests.find(lenderName) != _interests.end()) {
        return _interests[lenderName];
    } else {
        return 0.0;
    }
}


 std::map<std::string, double> Portfolio::getInterestMap(){
    return _interests;
 }