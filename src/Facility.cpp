#include "Facility.h"
#include "Exchange.h"
#include "Deal.h"
#include "Part.h"  // Include Part here

Facility::Facility() : _amount(0), _currency(""),_remainingAmount(0), _interestAmount(0) {}

Facility::~Facility() {}

Deal* Facility::getDeal() {
    return _deal;
}

void Facility::setDeal(Deal* deal) {
    _deal = deal;
}

Date Facility::getStartDate() {
    return _startDate;
}

void Facility::setStartDate(Date sd) {
    _startDate = sd;
    _nextStartDate= sd;
}

Date Facility::getEndDate() {
    return _endDate;
}

void Facility::setEndDate(Date ed) {
    _endDate = ed;
}

double Facility::getAmount() {
    return _amount;
}

void Facility::setAmount(double a) {
    _amount = a;
    _remainingAmount = a;
}

string Facility::getCurrency() {
    return _currency;
}

double Facility::getRemaingAmount(){
    return _remainingAmount;
}

void Facility::setCurrency(string c) {
    _currency = c;
}

vector<Lender> Facility::getLenders() {
    return _lenders;
}

void Facility::setLenders(vector<Lender> l) {
    _lenders = l;
}

void Facility::addLender(Lender lender){
    _lenders.push_back(lender);
}

vector<Part*> Facility::getParts() {
    return _parts;
}

Date Facility::getNextStartDate(){return _nextStartDate;}
void Facility::setNextStartDate(Date sd){_nextStartDate = sd;}

void Facility::addPart(Part* part) {
    _parts.push_back(part);
    calculateInterest(part);
    _deal->checkStatus();
    
}

void Facility::calculateInterest(Part* part) {
    if(part->getPaymentAmount() <= _remainingAmount){
        double interestRate = _deal->getAgent().getInterestRate();
        int days = Date::daysBetween(this->getNextStartDate(), part->getDatePayment());
        double dailyInterestRate = interestRate / 365;
        double interest = _remainingAmount * dailyInterestRate * days;

        double amount = Exchange::convert(part->getCurrency(), _currency, part->getPaymentAmount());

        _remainingAmount -= amount;

        _interestAmount += interest;

        _nextStartDate = part->getDatePayment();

        part->setInterestAmountGenarated(interest);

        // add interest to profolio
        for (const auto& pair : _lenderPercentages) {
            string lenderName = pair.first; 
            double pourcentageOnFacility = pair.second;
            double interestLender = (interest * pourcentageOnFacility )/100 ; 
            _deal->getPortFolio()->addInterest(lenderName,interestLender);
        }
    }else{
        std::cout<<"Part amount is greater than remaining amount"<<std::endl;
    }
    
}

void Facility::setLenderPercentage(const string& lenderName, double percentage) {
    _lenderPercentages[lenderName] = percentage;
}

double Facility::getLenderPercentage(const string& lenderName) {
    return _lenderPercentages[lenderName];
}

void Facility::displayInformation() const {
        std::cout << "{ ";
        std::cout << "\"Falicity Start Date\": \""; _startDate.print(); std::cout << "\", ";
        std::cout << "\"End Date\": \""; _endDate.print(); std::cout << "\", ";
        std::cout << "\"Amount\": " << _amount << ", ";
        std::cout << "\"Remaining Amount\": " << _remainingAmount << ", ";
        std::cout << "\"Currency\": \"" << _currency << "\", ";
        std::cout << "\"Interest Amount\": " << _interestAmount << ", ";
        std::cout << "\"Lenders\": [";
        for (int i = 0; i < _lenders.size(); i++) {
            std::cout << "\"" << _lenders[i].getName() << "\"";
            if (i != _lenders.size() - 1) std::cout << ", ";
        }
        std::cout << "] }" << std::endl;
    }



