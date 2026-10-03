//
// Created by 33651 on 03/10/2026.
//

#include "../../inc/room/InfoConsoleRoom.h"
using namespace std;

void InfoConsoleRoom::displayStarterOptions(int generationIndex, const vector<string> &starterOptions) {
    cout << "Choisissez un starter parmi ceux de la generation " << generationIndex << ":" << endl;
    for (int j = 0; j < starterOptions.size(); j++) {
        cout << "    [" << j+1 << "]: " << starterOptions.at(j) << endl;
    }
    cout << "Choisissez '1', '2' ou '3' :" << endl;
}

void InfoConsoleRoom::displayStarterErrorMessage() {
    cerr << "L'entrée n'est pas valide" << endl;
    cout << "Choisissez '1', '2' ou '3' :" << endl;
}

void InfoConsoleRoom::displayStarterChosenMessage(const string &name) {
    cout << "Vous avez choisi " << name << "." << endl;
}
