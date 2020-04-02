// V. Rivera Casanova
// CSCE 121
// Yhang 512

# include <iostream>
# include <fstream>
# include <string>
# include <stdexcept>
# include "functions.h"

using std::runtime_error;
using std::invalid_argument;
using std::ifstream;
using std::string;
using std::cout, std::cin, std::endl;

void readPrefs(string fileName, int ngames, int prefs[]) {
    ifstream ifs(fileName);
    int gameid;
    int rating;
    int index;

    for (int k = 0; k < ngames; k++){  //sets every element equal to zero in the beginning
        prefs[k] = 0;
    }

    if (!ifs.is_open()) {
        throw runtime_error("Invalid preference file.");
    }

    while (!ifs.eof()) {
            if (!ifs.fail()) {  //checks if end of line reached
                ifs >> gameid;

                if (gameid >= 0 && gameid < (ngames - 1)) {  // checks if game id is valid
                    index = gameid;
                }

                ifs >> rating;  // gets the second entry in the line (rating)

                if (rating >= 0 || rating <= 5) {  // checks if rating is valid
                    prefs[index] = rating ;
                }
            } else {  // once end of line is reach loop will clear stream state
                ifs.clear();
                ifs.good();
            } 
    }
}

void readPlan(string fileName, int plan[]) {
    ifstream ifs (fileName);
    int day = 0;
    int game;
    plan[day] = 0;

    if (!ifs.is_open()) {
        throw runtime_error("Invalid plan file.");
    }

    

    while (!ifs.eof()) {
        
        if (!ifs.fail()) {  //checks if end of line reached
            ifs >> day;  // gets first entry
            ifs >> game;  // if not fail then it gets teh second entry in line
            plan[day] = game;
        } else {  // once end of line is reach loop will clear stream state
            ifs.clear();
            ifs.good();
        } 
    }    

}

int computeFunLevel(int start, int duration, int prefs[], int plan[]) {
    int temp = 1;
    int sum = 0;
    int planOnGivenDay;

    if ((start + duration) > 366) {
            throw invalid_argument("");  //where to catch it
    } else {
        while (temp <= duration) {  
            planOnGivenDay = prefs[plan[start]];  // gets game planned on dat temp
            sum = sum + planOnGivenDay;  // adds num at index planOnGivenDay in the prefs array to funLevel
            start += 1;  // moves to next days plan 
            temp += 1;  // adds one to duration count until duration is reached
        }
        return sum;
    }
}

int findBestVacation(int duration, int prefs[], int plan[]) {
    int highestFunLevel = 0;
    int tempFun = 0;
    int bestStart = 1;
    int i = 1;
    string exc2 = "";

    try {
        highestFunLevel = computeFunLevel(i, duration, prefs, plan);
        i += 1; 

        while (i + duration <= 366) {  // (e.g) i = 365, duration = 1 needs to work
            tempFun = computeFunLevel(i, duration, prefs, plan);
            if (tempFun > highestFunLevel) {
                highestFunLevel = tempFun;
                bestStart = i;
            }
            i += 1;
        }
    } catch (string exc2) {
        return bestStart;
    }
    return bestStart;
}