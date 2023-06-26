#ifndef DEAL_H
#define DEAL_H

#include <string>
#include <vector>
#include "Borrower.h"
#include "Lender.h"
#include "Date.h"
#include "Lender.h"
#include <map>

class Facility;
class Portfolio;

using namespace std;

enum class DealStatus { terminated, closed };

class Deal {
private:
    string _deal_number;
    Lender _agent;
    vector<Lender*> _pool;
    map<string, double> _lenderPercentages;
    Borrower _borrower;
    double _amount;
    string _currency;
    Date _contract_sign_date;
    Date _contract_end_date;
    DealStatus _status;
    vector<Facility*> _facilities;
    Portfolio* _portfolio;
    string generateDealNumber();
    string getStatusAsString(DealStatus status) const;
   


public:
    Deal();
    ~Deal();

    string getDealNumber() const;
    Lender getAgent();
    void setAgent(const Lender& agent);

    vector<Lender*> getPool();
    void setPool(const vector<Lender*>& pool);

    Borrower getBorrower();
    void setBorrower(const Borrower& borrower);

    double getAmount();
    void setAmount(double amount);

    string getCurrency();
    void setCurrency(const string& currency);

    Date getContractSignDate();
    void setContractSignDate(const Date& contractSignDate);

    Date getContractEndDate();
    void setContractEndDate(const Date& contractEndDate);

    Portfolio* getPortFolio();

    DealStatus getStatus();
    void setStatus(DealStatus status);
    string getStatusString();

    double getLenderPercentage(const string& lenderName);
    void setLenderPercentage(const string& lenderName, double percentage);

    vector<Facility*> getFacilities(); // Change to pointers
    void addFacility(Facility* facility);

    void addLenderToPool(Lender* lender);
    void displayInformation() const;
    void checkStatus();

};

#endif //DEAL_H
