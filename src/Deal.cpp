#include "Deal.h"
#include "Facility.h"
#include <random>
#include "Portfolio.h"

using namespace std;

Deal::Deal() : _deal_number(generateDealNumber()), _amount(0.0), _status(DealStatus::closed)
{
    Portfolio* portfolio = new Portfolio(); 
    portfolio->setDeal(this);
    _portfolio = portfolio; 
}

Deal::~Deal() { }

string Deal::generateDealNumber() {
    static random_device rd;
    static default_random_engine generator(rd());
    static uniform_int_distribution<> dis1(0, 2);
    static uniform_int_distribution<> dis2(1000, 9999);
    
    string letters = "SZB";
    char letter = letters[dis1(generator)];
    int number = dis2(generator);
    return string(1, letter) + to_string(number);
}


string Deal::getDealNumber() const { return _deal_number; }

Lender Deal::getAgent() { return _agent; }
void Deal::setAgent(const Lender& agent) { _agent = agent; }

vector<Lender*> Deal::getPool() { return _pool; }
void Deal::setPool(const vector<Lender*>& pool) { _pool = pool; }

Borrower Deal::getBorrower() { return _borrower; }
void Deal::setBorrower(const Borrower& borrower) { _borrower = borrower; }

double Deal::getAmount() { return _amount; }
void Deal::setAmount(double amount) { _amount = amount; }

string Deal::getCurrency() { return _currency; }
void Deal::setCurrency(const string& currency) { _currency = currency; }

Date Deal::getContractSignDate() { return _contract_sign_date; }
void Deal::setContractSignDate(const Date& contractSignDate) { _contract_sign_date = contractSignDate; }

Date Deal::getContractEndDate() { return _contract_end_date; }
void Deal::setContractEndDate(const Date& contractEndDate) { _contract_end_date = contractEndDate; }

DealStatus Deal::getStatus() {
    checkStatus();
    return _status;
}
string Deal::getStatusString() {
    switch(_status) {
        case DealStatus::terminated:
            return "terminated";
        case DealStatus::closed:
            return "closed";
        default:
            return "unknown";
    }
}

void Deal::setStatus(DealStatus status) { _status = status; }

vector<Facility*> Deal::getFacilities() { // Change to pointers
    return _facilities;
}

void Deal::addFacility(Facility* facility) { // Change this to pointer
    _facilities.push_back(facility);
}

void Deal::addLenderToPool(Lender* lender) {
    _pool.push_back(lender);
}


void Deal::checkStatus(){
    double remainingAmount = 0;
    for(Facility* f : _facilities){
       remainingAmount += f->getRemaingAmount();
    }
    if(remainingAmount == 0)
        _status = DealStatus::terminated;
}

void Deal::setLenderPercentage(const string& lenderName, double percentage) {
    _lenderPercentages[lenderName] = percentage;
}

double Deal::getLenderPercentage(const string& lenderName) {
    return _lenderPercentages[lenderName];
}

Portfolio* Deal::getPortFolio() {
    return _portfolio;
}

void Deal::displayInformation() const {
    std::cout << "{ ";
    std::cout << "\"Deal Number\": \"" << _deal_number << "\", ";
    std::cout << "\"Agent\": \"" << _agent.getName() << "\", ";
    std::cout << "\"Borrower\": \"" << _borrower.getName() << "\", ";
    std::cout << "\"Amount\": " << _amount << ", ";
    std::cout << "\"Currency\": \"" << _currency << "\", ";
    std::cout << "\"Sign Date\": \""; _contract_sign_date.print(); std::cout << "\", ";
    std::cout << "\"End Date\": \""; _contract_end_date.print(); std::cout << "\", ";
    std::cout << "\"Status\": \"" << getStatusAsString(_status) << "\", ";
    std::cout << "\"Lenders\": [";
    for (int i = 0; i < _pool.size(); i++) {
        std::cout << "\"" << _pool[i]->getName() << "\"";
        if (i != _pool.size() - 1) std::cout << ", ";
    }
    std::cout << "] }" << std::endl;
}

string Deal::getStatusAsString(DealStatus status) const {
    if(status == DealStatus::closed){
            return "Closed";
    }else if(status == DealStatus::terminated){
        return "Terminated";
    }else{
        return "Unknown";
    }
}
