#include "Company.h"

Company::Company(std::string codeID, std::string name, std::string address, std::string phone_number)
    : _codeID(codeID), _name(name), _address(address), _phone_number(phone_number) { }
Company::Company(){}
Company::~Company() { }

std::string Company::getName() const { return _name; }
void Company::setName(std::string name) { _name = name; }

std::string Company::getCodeID() const { return _codeID; }
void Company::setCodeID(std::string codeID) { _codeID = codeID; }

std::string Company::getAddress() { return _address; }
void Company::setAddress(std::string address) { _address = address; }

std::string Company::getPhoneNumber() { return _phone_number; }
void Company::setPhoneNumber(std::string phone_number) { _phone_number = phone_number; }
