// Exchange.h

#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <map>
#include <string>

class Exchange {
private:
    static std::map<std::pair<std::string, std::string>, double> exchangeRates;

public:
    static double convert(std::string fromCurrency, std::string toCurrency, double amount);
};

#endif //EXCHANGE_H
