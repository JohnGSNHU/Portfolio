#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <vector>
#include <string>
using namespace std;

struct YearReport {
    int year;
    double yearEndBalance;
    double yearEndInterest;
};

class Investment {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterestRate;
    int years;

public:
    Investment(double init, double monthly, double annualRate, int yrs);
    vector<YearReport> calculateWithoutMontlyDeposits() const;
    vector<YearReport> calculateWithMontlyDeposits() const;
    double getInitialInvestment() const { return initialInvestment; }
    double getMonthlyDeposit() const { return monthlyDeposit; }
    double getAnnualInterestRate() const { return annualInterestRate; }
    int getYears() const { return years; }
};
#endif
//EndOfInvestment.h