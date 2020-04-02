// V. Rivera Casanova
// CSCE 121
// Yhang 512

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

void readPrefs(std::string fileName, int ngames, int prefs[]);
void readPlan(std::string fileName, int plan[]);
int computeFunLevel(int start, int duration, int prefs[], int plan[]);
int findBestVacation(int duration, int prefs[], int plan[]);


#endif