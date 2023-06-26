#include <iostream>
#include "Deal.h"
#include "DataManager.h"
#include "Date.h"

using namespace std;

// Forward declarations
void lenderMenu(DataManager &);
void createLender(DataManager &);
void listLenders(DataManager &);

void borrowerMenu(DataManager &);
void createBorrower(DataManager &);
void listBorrowers(DataManager &);

void dealMenu(DataManager &);
Deal *createDeal(DataManager &);
void listDeals(DataManager &);

void facilityMenu(DataManager &);
Facility *createFacility(DataManager &, Deal*);
void listFacilities(DataManager &, Deal*);

void partMenu(DataManager &);
Part *createPart(DataManager &, Facility*);
void listParts(DataManager &, Facility*);
void askCreateFacility(DataManager&, Deal*);
void askCreatePart(DataManager&, Facility*);

void viewDeal(DataManager&);

void viewPortfolio(Portfolio * portfolio);

int main()
{
    // Create Manager
    DataManager manager;

    int choice;
    do
    {
        cout<<endl;
        cout << "Choose an option:\n";
        cout << "1. Manage Lenders\n";
        cout << "2. Manage Borrowers\n";
        cout << "3. Manage Deals\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            lenderMenu(manager);
            break;
        case 2:
            borrowerMenu(manager);
            break;
        case 3:
            dealMenu(manager);
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

void createLender(DataManager &manager)
{
    string codeID, name, address, phone;
    double rate;

    cin.ignore(); // clear the newline character from the input buffer
    cout << "Enter the lender's codeID: ";
    getline(cin, codeID);
    cout << "Enter the lender's name: ";
    getline(cin, name);
    cout << "Enter the lender's address: ";
    getline(cin, address);
    cout << "Enter the lender's phone: ";
    getline(cin, phone);
    cout << "Enter the lender's rate: ";
    cin >> rate;

    manager.createLender(codeID, name, address, phone, rate);
    cout << "Lender successfully created!"<<endl<<endl;
}
void lenderMenu(DataManager &manager)
{
    int choice;
    do
    {
        cout<<endl;
        cout << "1. Create Lender\n";
        cout << "2. List Lenders\n";
        cout << "0. Back\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createLender(manager);
            break;
        case 2:
            listLenders(manager);
            break;
        case 0:
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
    } while (choice != 0);
}
void listLenders(DataManager &manager)
{
    auto lenders = manager.getAllLenders();
    for (const auto &lender : lenders)
    {
        lender->displayInformation();
    }
}

void borrowerMenu(DataManager &manager)
{
    int choice;
    do
    {
        cout<<endl;
        cout << "1. Create Borrower\n";
        cout << "2. List Borrowers\n";
        cout << "0. Back\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createBorrower(manager);
            break;
        case 2:
            listBorrowers(manager);
            break;
        case 0:
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
    } while (choice != 0);
}
void createBorrower(DataManager &manager)
{
    string codeID, name, address, phone, sector;

    cin.ignore(); // clear the newline character from the input buffer
    cout << "Enter the borrower's codeID: ";
    getline(cin, codeID);
    cout << "Enter the borrower's name: ";
    getline(cin, name);
    cout << "Enter the borrower's address: ";
    getline(cin, address);
    cout << "Enter the borrower's phone: ";
    getline(cin, phone);
    cout << "Enter the borrower's sector: ";
    getline(cin, sector);

    manager.createBorrower(codeID, name, address, phone, sector);
    cout << "Borrower successfully created!"<<endl<<endl;
}
void listBorrowers(DataManager &manager)
{
    auto borrowers = manager.getAllBorrowers();
    for (const auto &borrower : borrowers)
    {
        borrower->displayInformation();
    }
}
void dealMenu(DataManager &manager)
{
    int choice;
    do
    {
        cout<<endl;
        cout << "1. Create Deal\n";
        cout << "2. List Deals\n";
        cout << "3. View a Deal\n";
        cout << "0. Back\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Deal *deal = createDeal(manager);
            askCreateFacility(manager, deal);
            break;
        }

        case 2:{}
            listDeals(manager);
            break;
        case 3:
            viewDeal(manager);
            break;
        case 0:
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
    } while (choice != 0);
}

Deal *createDeal(DataManager &manager)
{
    // Implementation depends on how you create a deal in your system
    Deal *deal = manager.createDeal();
    string borrowerCodeID, lenderCodeID, lenderCodeID1;
    double amount;
    string currency;
    int day, month, year;
    int lenderPercentage;

    cout << "Enter borrower's CodeID: ";
    getline(cin, borrowerCodeID);

    Borrower *borrower = manager.findBorrowerByCodeID(borrowerCodeID);
    while (borrower == nullptr)
    {
        cout << "Borrower not found. Please enter a valid borrower codeID: ";
        getline(cin, borrowerCodeID);
        borrower = manager.findBorrowerByCodeID(borrowerCodeID);
    }

    cout << "Enter lender agent's CodeID: ";
    getline(cin, lenderCodeID1);

    Lender *agent = manager.findLenderByCodeID(lenderCodeID1);
    while (agent == nullptr)
    {
        cout << "Lender not found. Please enter a valid lender codeID: ";
        getline(cin, lenderCodeID1);
        agent = manager.findLenderByCodeID(lenderCodeID1);
    }
    cout << "Enter agent percentage for " << agent->getName() << ": ";
    cin>> lenderPercentage;
    cin.ignore();
    deal->setLenderPercentage(agent->getName(), lenderPercentage);

    cout << "Enter lender's pool codeID (-1 to stop): ";
    vector<Lender *> lendersList;
    while (true)
    {
        
        getline(cin, lenderCodeID);
        if (lenderCodeID == "-1")
        {
            break;
        }

        Lender *lender = manager.findLenderByCodeID(lenderCodeID);
        if (lender == nullptr)
        {
            cout << "Lender not found. Please enter a valid lender name: ";
        }
        else
        {
            lendersList.push_back(lender);
            cout << "Enter lender's percentage for " << lender->getName() << ": ";
            cin >> lenderPercentage;
            deal->setLenderPercentage(lender->getName(), lenderPercentage);
            cin.ignore(); // Clear the newline character from the input buffer
            cout << "Enter lender's name (-1 to stop): ";
        }
    }

    cout << "Enter amount: ";
    cin >> amount;
    cout << "Enter currency: ";
    cin >> currency;
    cout << "Enter contract sign date (day month year): ";
    cin >> day >> month >> year;
    cout << "Enter contract end date (day month year): ";
    int endDay, endMonth, endYear;
    cin >> endDay >> endMonth >> endYear;

    deal->setBorrower(*borrower);
    deal->setAgent(*agent);
    deal->setPool(lendersList);
    deal->setAmount(amount);
    deal->setCurrency(currency);
    deal->setContractSignDate(Date(day, month, year));
    deal->setContractEndDate(Date(endDay, endMonth, endYear));
    deal->setStatus(DealStatus::closed);

    cout << "Deal created successfully! Deal number : "<<deal->getDealNumber()<<endl<<endl;

    return deal;
}
void askCreateFacility(DataManager &manager, Deal *deal)
{
    int choice;
    do
    {
        cout<<endl;
        cout << "Do you want to create facility?" << endl;
        cout << "1.Yes\n";
        cout << "2. No\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Facility *facility = createFacility(manager, deal);
            askCreatePart(manager, facility);
            break;
        }

        case 2:
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
    } while (choice != 2);
}

void askCreatePart(DataManager &manager, Facility *facility)
{
    int choice;
    do
    {
        cout << "Do you want to create part?" << endl;
        cout << "1.Yes\n";
        cout << "2. No\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Part *part = createPart(manager, facility);
            break;
        }

        case 2:
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
    } while (choice != 2);
}

Part *createPart(DataManager &manager, Facility *facility)
{
    int day, month, year;
    double paymentAmount;
    string currency;

    // Get payment date
    cout << "Enter the payment date for the part (DD MM YYYY): ";
    cin >> day >> month >> year;
    Date paymentDate(day, month, year);

    // Get payment amount
    cout << "Enter the payment amount for the part: ";
    cin >> paymentAmount;

    // Get currency
    cout << "Enter the currency for the part: ";
    cin >> currency;

    // Create the part
    Part *part = manager.createPart();
    part->setFacility(facility);
    part->setDatePayment(paymentDate);
    part->setPaymentAmount(paymentAmount);
    part->setCurrency(currency);

    // Add the part to the facility
    facility->addPart(part);

    cout << "Part has been created successfully!" <<endl<<endl;

    return part;
}

void listDeals(DataManager &manager)
{
    auto deals = manager.getDeals();
    for (const auto &deal : deals)
    {
        deal->displayInformation();
        cout << endl;
    }
}

Facility *createFacility(DataManager &manager, Deal *deal)
{
    int day, month, year;
    double amount;
    string currency;
    string lenderCodeID;
    int lenderPercentage;

    // Saisir les informations de la facilité
    cout << "Enter the start date of the facility (DD MM YYYY): ";
    cin >> day >> month >> year;
    Date startDate(day, month, year);

    cout << "Enter the end date of the facility (DD MM YYYY): ";
    cin >> day >> month >> year;
    Date endDate(day, month, year);

    cout << "Enter the amount of the facility: ";
    cin >> amount;

    cout << "Enter the currency of the facility: ";
    cin >> currency;

    // Créer la facilité
    Facility *facility = manager.createFacility();
    facility->setDeal(deal);
    facility->setStartDate(startDate);
    facility->setEndDate(endDate);
    facility->setAmount(amount);
    facility->setCurrency(currency);

    // Ajouter les prêteurs à la facilité
    char addMoreLenders;
    do
    {
        cout << "Enter the codeID of a lender to add to the facility: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, lenderCodeID);

        Lender *lender = manager.findLenderByCodeID(lenderCodeID);
        if (lender)
        {
            cout << "Enter the percentage of the facility for this lender: ";
            cin >> lenderPercentage;
            facility->addLender(*lender);
            facility->setLenderPercentage(lender->getName(), lenderPercentage);
        }
        else
        {
            cout << "No lender found with that name. Please try again.\n";
        }
        cout << "Add more lenders? (Y/N): ";
        cin >> addMoreLenders;
    } while (addMoreLenders == 'Y' || addMoreLenders == 'y');

    deal->addFacility(facility);
    cout << "Facility created successfully!"<<endl<<endl;

    return facility;
}

void viewDeal(DataManager& manager){
    string dealNumber;
    cout <<endl<< "Enter deal number : ";
    cin >> dealNumber;

    Deal *deal = manager.getDealByNumber(dealNumber);
    while (deal == nullptr)
    {
        cout <<endl<< "Enter deal number : ";
        cin >> dealNumber;
        deal = manager.getDealByNumber(dealNumber);
    }

    deal->displayInformation();

    int choice;
    do
    {
        cout<<endl;
        cout << "1. Create Facility\n";
        cout << "2. View list facility\n";
        cout << "3. View interest portfolio\n";
        cout << "0. Back\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createFacility(manager,deal);
            break;
        case 2:
            listFacilities(manager, deal);
            break;
        case 3:
            viewPortfolio(deal->getPortFolio());
            break;
        case 0:
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
    } while (choice != 0);


}
void listFacilities(DataManager& manager, Deal* deal){
    auto facilities = deal->getFacilities();
    cout<<deal->getFacilities().size();
    int i=0;
    cout<<endl;
    for (const auto &facility : facilities)
    {
        i++;
        cout<<i<<". ";
        facility->displayInformation();
        cout << endl;
    }

    int choice;
    int facilityId;
    Facility * facility;
    do
    {
        cout<<endl;
        cout << "1. Create part\n";
        cout << "2. View list part\n";
        cout << "0. Back\n";
        cin >> choice;

        if(choice == 1 || choice ==2){
            cout << "Enter facility id number : "<<endl;
            cin>>facilityId;
            while(facilityId<1 || facilityId > facilities.size()){
                cout << "Enter Valid facility id number : "<<endl;
                cin>>facilityId;
            }
            facility = facilities[facilityId-1];
        }


        switch (choice)
        {
        case 1:
            createPart(manager,facility);
            break;
        case 2:
            listParts(manager, facility);
            break;
        case 0:
            break;
        default:
            cout << "Invalid option, please try again.\n";
            break;
        }
    } while (choice != 0);
}

void listParts(DataManager & manager, Facility* facility){
    auto parts = facility->getParts();
    int i=0;
    for (const auto &part : parts)
    {
        part->displayInformation();
        cout << endl;
    }
}

void viewPortfolio(Portfolio * portfolio){
    map<std::string, double> interestMap = portfolio->getInterestMap();
    cout<<endl<<"Total interest : "<<portfolio->getIterestTotalAmount()<<endl;
    cout<<"Repartition :"<<endl;
    for (const auto& pair : interestMap) {
        cout<<" "<<pair.first<<" -> "<<pair.second<<endl;
    }
}