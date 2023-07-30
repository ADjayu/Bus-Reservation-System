#ifndef SERVICES_H
#define SERVICES_H

#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

void printHeading(string header)
{
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\033[35m==========================================================\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t                       \033[36m" << header << "\033[0m                     \n";
    cout << "\t\t\t\t\t\t\t\t\033[35m==========================================================\033[0m\n\n";
}

string generatePNR(int n)
{
    srand(time(0));

    string pnr;

    int randomNo = rand() % n;

    pnr = "PNR" + to_string(randomNo);

    return pnr;
}

string getCurrentDate()
{
    time_t t = time(NULL);
    tm *tPtr = localtime(&t);

    return to_string(tPtr->tm_mday) + "-" + to_string((tPtr->tm_mon) + 1) + "-" + to_string((tPtr->tm_year) + 1900);
}
#endif // UTILS_H
