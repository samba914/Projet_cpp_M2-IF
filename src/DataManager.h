#ifndef DataMANAGER_H
#define DataMANAGER_H

#include "Deal.h"
#include "Lender.h"
#include "Borrower.h"
#include "Facility.h"
#include "Part.h"
#include <vector>

class DataManager {
private:
    std::vector<Deal*> deals;
    std::vector<Borrower*> borrowers;
    std::vector<Lender*> lenders;
    std::vector<Facility*> facilities;
    std::vector<Part*> parts;
    void populateData();

public:
    DataManager();
    Borrower* createBorrower(const std::string& codeID, const std::string& name, const std::string& address, const std::string& phone, const std::string& sector);
    Lender* createLender(const std::string& codeID, const std::string& name, const std::string& address, const std::string& phone, double rate);
    Deal* createDeal();
    Facility* createFacility();
    Part* createPart();
    Borrower* findBorrowerByCodeID(const std::string& codeID);
    Lender* findLenderByCodeID(const std::string& codeID);
    std::vector<Deal*>& getDeals();
    std::vector<Deal*>& getDeals(DealStatus);
    std::vector<Borrower*>& getAllBorrowers();
    std::vector<Lender*>& getAllLenders();
    std::vector<Facility*>& getAllFacilities();
    std::vector<Part*>& getAllParts();
    Deal* getDealByNumber(const std::string& dealNumber);
    
    ~DataManager();
};

#endif
