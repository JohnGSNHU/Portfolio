#include "UI.h"
#include "Investment.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

Investment UI::getUserInputs() {
    double init, monthly, rate;
    int yrs;

    cout << "------------- Data Input -------------\n";
    cout << "Initial Investment Amount: $";
    cin >> init;

    cout << "Monthly Deposit: $";
    cin >> monthly;

    cout << "Annual Interest (%): ";
    cin >> rate;

    cout << "Number of years: ";
    cin >> yrs;

    // convert percentage to decimal
    rate = rate / 100.0;

    return Investment(init, monthly, rate, yrs);
}
void UI::displayDataInputScreen(const Investment& inv) {
    cout << "\n------------- Data Input -------------\n";
    cout << "Initial Investment Amount: $" << fixed << setprecision(2) << inv.getInitialInvestment() << endl;
    cout << "Monthly Deposit: $" << inv.getMonthlyDeposit() << endl;
    cout << "Annual Interest: " << inv.getAnnualInterestRate() * 100 << "%" << endl;
    cout << "Number of years: " << inv.getYears() << endl;
    cout << "Press any key to continue . . .\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
void UI::displayReport(const string& title, const vector<YearReport>& reports) {
    cout << "\n========================================================\n";
    cout << title << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------\n";

    for (auto& r : reports) {
        cout << r.year << "\t$" << fixed << setprecision(2) << r.yearEndBalance << "\t\t\t$" << r.yearEndInterest << endl;
    }
}
//EndOfUI.cpp