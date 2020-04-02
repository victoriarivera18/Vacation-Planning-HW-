// V. Rivera Casanova
// CSCE 121
// Yhang 512

# include <iostream>
# include <string>
# include <fstream>
#include <stdexcept>
using std::string;
using std::cout, std::cin, std::endl;
using std::runtime_error;

# include "functions.h"
# include "provided.h"


// main 
int main() {
    int ngames;
    int duration;
    int start;

    // name of input files
    string gTitles;
    string prefsT;
    string plansT;
    string exc = "Invalid input.";
    string exc2 = "";

    string gameTitles[200];
    int prefs[MAX_NB_GAMES];
    int plan[366];
    
    // checks to see if input is valid
    try{
        cout << "Please enter the number of games and the duration: ";
        cin >> ngames;
        cin >> duration;

        if (ngames > 200 || ngames <= 0) {
            throw exc;
        } else if (duration > 365 || duration <= 0) {
            throw exc;
        } else {  // if input nums for ngmaes and duration are valid
            cout << "Please enter name of file with titles: ";
            cin >> gTitles;

            cout << "Please enter name of file with preferences: ";
            cin >> prefsT;

            cout << "Please enter name of file with plan: ";
            cin >> plansT;
        }

        readGameTitles(gTitles, ngames, gameTitles);
        readPrefs(prefsT, ngames, prefs);
        readPlan(plansT, plan);
    } catch (string exc) {  // catches invalid argument
        cout << exc << endl;
        return 0;
    } catch (runtime_error& error){  // catches runtime error
        cout << error.what() << endl;
        return 0;
    }
    
    start = findBestVacation(duration, prefs, plan);
    cout << "Best start day is " << start << endl;
    cout << "Games to be played:" << endl;
    printGamesPlayedInVacation(start, duration, plan, gameTitles, ngames);

    return 0;
}