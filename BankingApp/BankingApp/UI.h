//User Interface
#ifndef UI_H
#define UI_H

#include "Investment.h"

class UI {
public:
    static Investment getUserInputs();
    static void displayDataInputScreen(const Investment &inv);
    static void displayReport(const std::string& title, const std::vector<YearReport>& reports);
};
#endif
//EndOfUI.h