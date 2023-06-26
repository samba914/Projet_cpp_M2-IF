#include "Part.h"


Part::Part() : _facility(nullptr) { } 

Part::~Part() { }

Facility* Part::getFacility() { return _facility; }

void Part::setFacility(Facility* f) { _facility = f; }

double Part::getPaymentAmount() { return _payment_amount; }

void Part::setPaymentAmount(double p) { _payment_amount = p; }

Date Part::getDatePayment() { return _datePayment; }

void Part::setDatePayment(Date datePayment) { _datePayment = datePayment; }  

double Part::getInterestAmountGenarated() { return _interestAmountGenarated; }

void Part::setInterestAmountGenarated(double interestAmountGenarated) { _interestAmountGenarated = interestAmountGenarated; }  

string Part::getCurrency() { return _currency; }

void Part::setCurrency(string currency) { _currency = currency; }

void Part::displayInformation() const {
    std::cout << "{ ";
    std::cout << "\"Part Date of Payment\": \""; _datePayment.print(); std::cout << "\", ";
    std::cout << "\"Payment Amount\": " << _payment_amount << ", ";
    std::cout << "\"Currency\": \"" << _currency << "\", ";
    std::cout << " }" << std::endl;
}

