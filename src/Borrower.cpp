#include "Borrower.h"
#include "iostream"

Borrower::Borrower(std::string codeID, std::string name, std::string address, std::string phone_number, std::string industry) 
    : Company(codeID, name, address, phone_number), _industry(industry){ }
Borrower::Borrower():Company(){}
Borrower::~Borrower() { }

std::string Borrower::getIndustry() { return _industry; }
void Borrower::setIndustry(std::string industry) { _industry = industry; }

void Borrower::displayInformation() const {
    std::cout << "{ \"Borrower Name\": \"" << _name << "\", \"CodeId\": \"" << _codeID << "\", \"Address\": \"" << _address 
              << "\", \"Phone Number\": \"" << _phone_number << "\", \"Industry\": \"" << _industry << "\" }" << std::endl;
}