#include "Investment.h"
#include <cmath>
Investment::Investment(double init, double monthly, double annualRate, int yrs){  //initializer
	initialInvestment = init;
	monthlyDeposit = monthly;
	annualInterestRate = annualRate;
	years = yrs;
}
vector<YearReport> Investment::calculateWithoutMontlyDeposits() const { //report WITHOUT monthly depos, only initial depo compounded
	vector<YearReport> reports;
	double balance = initialInvestment;

	for (int i = 1; i <= years; i++) {  //annual interest rate of fixed #
		double interest = balance * annualInterestRate;
		balance += interest;
		reports.push_back({ i, balance, interest });
	}
	return reports;
}
vector<YearReport> Investment::calculateWithMontlyDeposits() const { //report WITH monthly depos, all depos added and compounded annually
	vector<YearReport> reports;
	double balance = initialInvestment;
	double monthlyRate = annualInterestRate / 12.0;

	for (int i = 1; i <= years; i++) {
		double interestAccrued = 0.0;
		for (int m = 1; m <= 12; m++) {
			balance += monthlyDeposit; 
			double interest = balance * monthlyRate;
			balance += interest;
			interestAccrued += interest;
		}
		reports.push_back({i, balance, interestAccrued});
	}
	return reports;
}
//EndOfInvestment.cpp