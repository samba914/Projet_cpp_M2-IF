#include "DataManager.h"

DataManager::DataManager()
{
    populateData();
}

Borrower *DataManager::createBorrower(const std::string &codeID, const std::string &name, const std::string &address, const std::string &phone, const std::string &sector)
{
    borrowers.push_back(new Borrower(codeID, name, address, phone, sector));
    return borrowers.back();
}

Lender *DataManager::createLender(const std::string &codeID, const std::string &name, const std::string &address, const std::string &phone, double rate)
{
    lenders.push_back(new Lender(codeID, name, address, phone, rate));
    return lenders.back();
}

Deal *DataManager::createDeal()
{
    deals.push_back(new Deal());
    return deals.back();
}

Facility *DataManager::createFacility()
{
    facilities.push_back(new Facility());
    return facilities.back();
}

Part *DataManager::createPart()
{
    parts.push_back(new Part());
    return parts.back();
}

std::vector<Deal *> &DataManager::getDeals()
{
    return deals;
}
std::vector<Deal *> &DataManager::getDeals(DealStatus status)
{
    return deals;
}

std::vector<Borrower *> &DataManager::getAllBorrowers()
{
    return borrowers;
}

std::vector<Lender *> &DataManager::getAllLenders()
{
    return lenders;
}

std::vector<Facility *> &DataManager::getAllFacilities()
{
    return facilities;
}

std::vector<Part *> &DataManager::getAllParts()
{
    return parts;
}

DataManager::~DataManager()
{
    for (auto deal : deals)
        delete deal;
    for (auto facility : facilities)
        delete facility;
    for (auto part : parts)
        delete part;
}

Borrower *DataManager::findBorrowerByCodeID(const std::string &codeID)
{
    for (auto &borrower : borrowers)
    {
        if (borrower->getCodeID() == codeID)
        {
            return borrower;
        }
    }
    return nullptr; 
}

Lender *DataManager::findLenderByCodeID(const std::string &codeID)
{
    for (auto &lender : lenders)
    {
        if (lender->getCodeID() == codeID)
        {
            return lender;
        }
    }
    return nullptr; 
}

Deal* DataManager::getDealByNumber(const std::string& dealNumber) {
    for (auto& deal : deals) {
        if (deal->getDealNumber() == dealNumber) {
            return deal;
        }
    }
    return nullptr;  
}


void DataManager::populateData()
{
    // Create lenders
    Lender *creditAgricole = new Lender("CA", "Credit Agricole", "12 Place des Etats-Unis, Montrouge, France", "+33143162324", 5);
    Lender *sg = new Lender("SG", "Societe Generale", "29 Boulevard Haussmann, Paris, France", "+33142142000", 5);
    Lender *bnp = new Lender("BNP", "BNP Paribas", "16 Boulevard des Italiens, Paris, France", "+33142983000", 5);
    lenders.push_back(creditAgricole);
    lenders.push_back(sg);
    lenders.push_back(bnp);

    // Create borrower
    Borrower *airFrance = new Borrower("AF", "Air France", "45 Rue de Paris, 75000 Paris, France", "+33123456789", "Aerospace");
    borrowers.push_back(airFrance);

    // Create a deal
    Deal *deal = new Deal();
    deal->setAgent(*creditAgricole);
    deal->setBorrower(*airFrance);
    deal->setAmount(10000);
    deal->setCurrency("USD");
    deal->setContractSignDate(Date(23, 05, 2023));
    deal->setContractEndDate(Date(31, 12, 2024));
    deal->setStatus(DealStatus::closed);
    std::vector<Lender *> pool{sg, bnp};
    deal->setPool(pool);
    deal->setLenderPercentage(creditAgricole->getName(), 50);
    deal->setLenderPercentage(sg->getName(), 25);
    deal->setLenderPercentage(bnp->getName(), 25);
    deals.push_back(deal);

    // Create first facility
    Facility *facility1 = new Facility();
    facility1->setDeal(deal);
    facility1->setStartDate(Date(04, 12, 2023));
    facility1->setEndDate(Date(10, 06, 2024));
    facility1->setAmount(4000);
    facility1->setCurrency("USD");
    facility1->addLender(*sg);
    facility1->addLender(*bnp);
    facility1->setLenderPercentage(sg->getName(), 50.0);
    facility1->setLenderPercentage(bnp->getName(), 50.0);
    deal->addFacility(facility1);
    facilities.push_back(facility1);

    // Create parts for first facility
    Part *part1 = new Part();
    part1->setFacility(facility1);
    part1->setPaymentAmount(500);
    part1->setDatePayment(Date(01, 02, 2024));
    part1->setCurrency("USD");
    parts.push_back(part1);

    Part *part2 = new Part();
    part2->setFacility(facility1);
    part2->setPaymentAmount(500);
    part2->setDatePayment(Date(01, 03, 2024));
    part2->setCurrency("USD");
    parts.push_back(part2);

    Part *part3 = new Part();
    part3->setFacility(facility1);
    part3->setPaymentAmount(3000);
    part3->setDatePayment(Date(01, 05, 2024));
    part3->setCurrency("USD");
    parts.push_back(part3);

    // Add parts to facility
    facility1->addPart(part1);
    facility1->addPart(part2);
    facility1->addPart(part3);

    // Create second facility
    Facility *facility2 = new Facility();
    facility2->setDeal(deal);
    facility2->setStartDate(Date(11, 06, 2024));
    facility2->setEndDate(deal->getContractEndDate());
    facility2->setAmount(6000);
    facility2->setCurrency("USD");
    facility2->addLender(*creditAgricole);
    facility2->addLender(*sg);
    facility2->addLender(*bnp);
    facility2->setLenderPercentage(creditAgricole->getName(), 83.33);
    facility2->setLenderPercentage(sg->getName(), 8.335);
    facility2->setLenderPercentage(bnp->getName(), 8.335);
    facilities.push_back(facility2);

    // Create parts for second facility
    Part *part4 = new Part();
    part4->setFacility(facility2);
    part4->setPaymentAmount(2000);
    part4->setDatePayment(Date(01, 07, 2024));
    part4->setCurrency("USD");
    parts.push_back(part4);

    Part *part5 = new Part();
    part5->setFacility(facility2);
    part5->setPaymentAmount(4000);
    part5->setDatePayment(Date(01, 10, 2024));
    part5->setCurrency("USD");
    parts.push_back(part5);

    // Add parts to second facility
    facility2->addPart(part4);
    facility2->addPart(part5);
    deal->addFacility(facility2);

    // Create another deal
    Deal *deal2 = new Deal();
    deal2->setAgent(*sg);
    deal2->setBorrower(*airFrance);
    deal2->setAmount(15000);
    deal2->setCurrency("EUR");
    deal2->setContractSignDate(Date(01, 01, 2024));
    deal2->setContractEndDate(Date(31, 12, 2025));
    deal2->setPool({creditAgricole, bnp});
    deal2->setLenderPercentage(sg->getName(), 40);
    deal2->setLenderPercentage(creditAgricole->getName(), 30);
    deal2->setLenderPercentage(bnp->getName(), 30);
    deals.push_back(deal2);

    // Create first facility for second deal
    Facility *facility3 = new Facility();
    facility3->setDeal(deal2);
    facility3->setStartDate(Date(02, 01, 2024));
    facility3->setEndDate(Date(30, 06, 2025));
    facility3->setAmount(8000);
    facility3->setCurrency("EUR");
    facility3->addLender(*creditAgricole);
    facility3->addLender(*bnp);
    facility3->setLenderPercentage(creditAgricole->getName(), 50.0);
    facility3->setLenderPercentage(bnp->getName(), 50.0);
    facilities.push_back(facility3);

    // Create parts for first facility of second deal
    Part *part6 = new Part();
    part6->setFacility(facility3);
    part6->setPaymentAmount(4000);
    part6->setDatePayment(Date(01, 03, 2024));
    part6->setCurrency("EUR");
    parts.push_back(part6);

    Part *part7 = new Part();
    part7->setFacility(facility3);
    part7->setPaymentAmount(4000);
    part7->setDatePayment(Date(01, 05, 2024));
    part7->setCurrency("EUR");
    parts.push_back(part7);

    // Add parts to first facility of second deal
    facility3->addPart(part6);
    facility3->addPart(part7);
    deal2->addFacility(facility3);

    // Create second facility for second deal
    Facility *facility4 = new Facility();
    facility4->setDeal(deal2);
    facility4->setStartDate(Date(01, 07, 2025));
    facility4->setEndDate(deal2->getContractEndDate());
    facility4->setAmount(7000);
    facility4->setCurrency("EUR");
    facility4->addLender(*creditAgricole);
    facility4->addLender(*sg);
    facility4->setLenderPercentage(creditAgricole->getName(), 30.0);
    facility4->setLenderPercentage(sg->getName(), 70.0);
    facilities.push_back(facility4);

    // Create parts for second facility of second deal
    Part *part8 = new Part();
    part8->setFacility(facility4);
    part8->setPaymentAmount(3500);
    part8->setDatePayment(Date(30, 07, 2025));
    part8->setCurrency("EUR");
    parts.push_back(part8);

    /*Part *part9 = new Part();
    part9->setFacility(facility4);
    part9->setPaymentAmount(3500);
    part9->setDatePayment(Date(01, 11, 2025));
    part9->setCurrency("EUR");
    parts.push_back(part9);*/

    // Add parts to second facility of second deal
    facility4->addPart(part8);
    //facility4->addPart(part9);
    deal2->addFacility(facility4);
}
