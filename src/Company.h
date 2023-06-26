#ifndef COMPANY_H
#define COMPANY_H

#include <string>

class Company {
protected:
    std::string _codeID;
    std::string _name;
    std::string _address;
    std::string _phone_number;

public:
    Company();
    Company(std::string codeID, std::string name, std::string address, std::string phone_number);;
    virtual ~Company();

    std::string getName() const;
    void setName(std::string name);

    std::string getCodeID() const;
    void setCodeID(std::string codeID);

    std::string getAddress();
    void setAddress(std::string address);

    std::string getPhoneNumber();
    void setPhoneNumber(std::string phone_number);

    virtual void displayInformation() const = 0; 

};

#endif //COMPANY_H
