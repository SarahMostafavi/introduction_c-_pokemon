//
// Created by 33651 on 03/10/2026.
//

#include "../../inc/room/InfoConsoleRoom.h"
#include "../../inc/GameEngine.h"
using namespace std;

void InfoConsoleRoom::displayStarterOptions(int generationIndex, const vector<string> &starterOptions) {
    cout << "Choisissez un starter parmi ceux de la generation " << generationIndex +1<< ":" << endl;
    for (int j = 0; j < starterOptions.size(); j++) {
        cout << "    [" << j+1 << "]: " << starterOptions.at(j) << endl;
    }
    cout << "Choisissez '1', '2' ou '3' :" << endl;
}

void InfoConsoleRoom::displayInvalidEntryMessage() {
    cerr << "L'entrée n'est pas valide" << endl;
}

void InfoConsoleRoom::displayStarterErrorMessage() {
    cout << "Choisissez '1', '2' ou '3' :" << endl;
}

void InfoConsoleRoom::displayStarterChosenMessage(const string &name) {
    cout << "Vous avez choisi " << name << "." << endl;
}

void InfoConsoleRoom::displayCenterRoomWelcomeMessage() {
    cout << "Bienvenue dans le centre pokemon!" << endl;
    cout << "Vous pouvez choisir : " << endl;
    cout << "   '1' : Voir/Modifier l'equipe" << endl;
    cout << "   '2' : Recuperer des pokeballs"<< endl;
    cout << "   '3' : Recuperer des potions de soin"<< endl;
    cout << "   '4' : Aller en mode exploration"<< endl;
    cout << "   '5' : Aller combattre dans l'arene pokemon"<< endl;
    cout << "Selectionnez votre action : " <<endl;

}

void InfoConsoleRoom::displayCenterRoomErrorMessage() {
    displayInvalidEntryMessage();
    displayCenterRoomWelcomeMessage();
}

void InfoConsoleRoom::displayGetAdditionalPokeballsMessage(GameEngine& engine) {
    cout << "1 pokeball est ajoutee a votre inventaire." << endl;
    cout << "Vous avez " << engine.getPlayer().getNumberOfPokeballs() << " pokeballs dans votre inventaire." << endl;
}

void InfoConsoleRoom::displayGetAdditionalHealPotionsMessage(GameEngine& engine) {
    cout << "3 potions de soin sont ajoutees a votre inventaire." << endl;
    cout << "Vous avez " << engine.getPlayer().getNumberOfHealPotion() << " potions de soin dans votre inventaire." << endl;
}

void InfoConsoleRoom::displayModifyTeamPlayerMessage(GameEngine& engine) {
    engine.getPlayer().getTeam().displayInfoTeam();
    cout << "Voulez vous modifier votre equipe? " << endl;
    cout <<"Entrez 'y' ou 'n' :" << endl;
}

void InfoConsoleRoom::displayPlayerPartyMessage(GameEngine &engine) {
    cout << "Voici votre party : " << endl;
    cout <<"----------------- Party ------------------" << endl;
    engine.getPlayer().getParty().displayInfoParty();
    cout <<"----------------- Party ------------------" << endl;
    cout << "Quel pokemon voulez vous ajouter à l'equipe? (indice de la party [?]) " << endl;
}

void InfoConsoleRoom::displayAddingInTeamMessage(GameEngine &engine){
    cout << "Voici votre équipe : " << endl;
    engine.getPlayer().getTeam().displayInfoTeam();
    cout << "Ou voulez vous placer le pokemon selectionne? (emplacement dans la team [?])  " << endl;
}

void InfoConsoleRoom::displayPartyEmptyMessage() {
    cout << "Vous n'avez plus de pokemon dans la party, vous ne pouvez pas en ajouter." << endl;
}
