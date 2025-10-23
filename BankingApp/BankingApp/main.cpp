#include "UI.h"
#include "Investment.h"
#include <iostream>

using namespace std;

int main() {
    char choice;
    do {
        Investment inv = UI::getUserInputs(); //Get user inputs

        UI::displayDataInputScreen(
            inv // we can pass values directly if we extend UI
        );

        auto noMonthly = inv.calculateWithoutMontlyDeposits(); //creates reports
        auto withMonthly = inv.calculateWithMontlyDeposits();

        // Step 4: Display reports
        UI::displayReport("Balance and Interest Without Additional Monthly Deposits", noMonthly);
        UI::displayReport("Balance and Interest With Additional Monthly Deposits", withMonthly);

        cout << "\nRun again with different inputs? (y/n): "; //asks user if they want to insert different inputs
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
    cout << "\nThank you for using Airgead Banking App!\n"; //exit
    return 0;
}
//EndOfmain.cpp