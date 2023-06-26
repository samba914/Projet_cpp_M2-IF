#include "Lender.h"
#include "iostream"

Lender::Lender(std::string codeID, std::string name, std::string address, std::string phone_number, double interestRate) 
    : Company(codeID, name, address, phone_number), _interestRate(interestRate) { }

Lender::Lender():Company(){}

Lender::~Lender() { }

double Lender::getInterestRate() { return _interestRate; }
void Lender::setInterestRate(double interestRate) { _interestRate = interestRate; }

void Lender::displayInformation() const {
    std::cout << "{ \"Company Type\": \"Lender\", \"CodeId\": \"" << _codeID << "\", \"Name\": \"" << _name << "\", \"Address\": \"" << _address
              << "\", \"Phone number\": \"" << _phone_number << "\", \"Interest Rate\": \"" << _interestRate << "\" }\n";
}