#include "Exchange.h"
#include <stdexcept>

// Initialisation des taux de change
std::map<std::pair<std::string, std::string>, double> Exchange::exchangeRates = {
    {{ "USD", "EUR" }, 0.85},
    {{ "EUR", "USD" }, 1.18},
    {{ "USD", "JPY" }, 109.57},
    {{ "JPY", "USD" }, 0.0091},
    {{ "EUR", "JPY" }, 129.32},
    {{ "JPY", "EUR" }, 0.0077}
};

double Exchange::convert(std::string fromCurrency, std::string toCurrency, double amount) {
    if(fromCurrency == toCurrency){
        return amount;
    }
    if (exchangeRates.find({fromCurrency, toCurrency}) != exchangeRates.end()) {
        return amount * exchangeRates[{fromCurrency, toCurrency}];
    } else {
        throw std::invalid_argument("Exchange rate not available for these currencies.");
    }
}
