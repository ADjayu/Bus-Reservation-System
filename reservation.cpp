#include <iostream>
#include <string.h>

#include "bus.cpp"
#include "ticket.cpp"
#include "services.h"

using namespace std;

// GLOBAL FUNCTION
void mainMenu();
void userMenu();
void adminMenu();
void adminLogin();
void viewBookingsMenu();
void welcomeScreen();

// MAIN FUNCTION
int main()
{
    system("cls");
    system("COLOR 0f");

    welcomeScreen();

    return 0;
}

//  WELCOME SCREEN FUNCTION
void welcomeScreen()
{
    system("cls");

    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\033[32m================================================\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t\033[34m||\033[0m                 \033[31mWELCOME TO\033[0m                 \033[34m||\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t\033[34m||\033[0m                   \033[31mJAYU'S\033[0m                   \033[34m||\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t\033[34m||\033[0m           \033[31mBUS RESERVATION SYSTEM\033[0m           \033[34m||\033[0m\n";
    cout << "\t\t\t\t\t\t\t\t\033[32m================================================\033[0m\n\n\n";

    system("pause");
    mainMenu();
}

// MAIN MENU
void mainMenu()
{
    int choice;

    while (1)
    {
        system("cls");

        // MENU ITEMS
        printHeading("MAIN MENU");

        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m1. User Menu\033[0m                                    \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m2. Admin Menu\033[0m                                   \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[31m3. EXIT\033[0m                                         \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n\n";

        cout << "\n\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            userMenu();
            break;

        case 2:
            adminLogin();
            break;

        case 3:
            system("cls");
            cout << "\n\n\n\n\t\t\t\t\t\t\t\t  \033[31m!!...THANK YOU FOR YOUR VALUABLE TIME...!!\033[0m \t\t\t\n";
            cout << "\n\n\t\t\t\t\t\t\t\t     \033[31m!!!...MAY YOU HAVE A NICE DAY...!!!\033[0m      \t\t\t\n\n";
            exit(0);

        default:
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            mainMenu();
        }
    }
}

// ADMIN LOGIN
void adminLogin()
{
    string adminUname, adminPass;

    system("cls");

    printHeading("ADMIN LOGIN");

    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter AdminID:-> ";
    cin >> adminUname;
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Password:-> ";
    cin >> adminPass;

    if (adminUname == "adjayu09" && adminPass == "jayu333")
    {
        adminMenu();
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\t\033[31mINVALID CREDENTIALS...!\033[0m \n";
        system("pause");
        adminLogin();
    }
}

// USER MENU
void userMenu()
{

    int choice;

    while (1)
    {
        system("cls");

        Ticket t;

        // MENU ITEMS
        printHeading("USER MENU");

        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m1. Book Ticket\033[0m                                  \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m2. View Ticket\033[0m                                  \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m3. Cancel Ticket\033[0m                                \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[31m4. BACK\033[0m                                         \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";

        cout << "\n\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            t.bookTicket();
            system("pause");
            break;

        case 2:
            t.showTicketsByPNR();
            system("pause");
            break;

        case 3:
            t.cancelTicket();
            system("pause");
            break;

        case 4:
            system("cls");
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            break;
            userMenu();
        }
    }
}

// ADMIN MENU FUNCTION
void adminMenu()
{
    Bus b;
    Ticket t;

    int choice;

    while (1)
    {
        system("cls");

        printHeading("ADMIN PORTAL");

        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m1. Add Bus\033[0m                                      \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m2. View Buses\033[0m                                   \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m3. Book Ticket\033[0m                                  \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m4. Edit Ticket\033[0m                                  \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m5. Cancel Ticket\033[0m                                \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m6. View Bookings\033[0m                                \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m7. View Bus Details\033[0m                             \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m8. Edit Bus\033[0m                                     \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[32m9. Delete Bus\033[0m                                   \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t \033[31m10. BACK\033[0m                                        \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n\n";

        cout << "\n\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            b.addBus();
            system("pause");
            break;

        case 2:
            b.showAllBus();
            system("pause");
            break;

        case 3:
            t.bookTicket();
            system("pause");
            break;

        case 4:
            t.editTicket();
            system("pause");
            break;

        case 5:
            t.cancelTicket();
            system("pause");
            break;

        case 6:
            viewBookingsMenu();
            break;

        case 7:
            b.viewBusDetails();
            system("pause");
            break;

        case 8:
            b.editBus();
            system("pause");
            break;

        case 9:
            b.deleteBus();
            system("pause");
            break;

        case 10:
            system("cls");
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            adminMenu();
        }
    }
}

// VIEW BOOKINGS MENU FUNCTION
void viewBookingsMenu()
{
    Ticket t;

    int choice;

    while (1)
    {
        system("cls");

        printHeading("VIEW BOOKINGS");

        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t\033[32m 1. By PNR\033[0m                                      \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t\033[32m 2. By Name\033[0m                                      \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t\033[32m 3. By Bus\033[0m                                       \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t\033[32m 4. By Source\033[0m                                    \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t\033[32m 5. By Destination\033[0m                               \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t\033[32m 6. All Bookings\033[0m                                 \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n";
        cout << "\t\t\t\t\t\t\t\t\033[31m 7. BACK\033[0m                                         \n";
        cout << "\t\t\t\t\t\t\t\t\033[33m-------------------------------------------------\033[0m\n\n";

        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            t.showTicketsByPNR();
            system("pause");
            break;

        case 2:
            t.showTicketsByName();
            system("pause");
            break;

        case 3:
            t.showTicketsByBus();
            system("pause");
            break;

        case 4:
            t.showTicketsBySource();
            system("pause");
            break;

        case 5:
            t.showTicketsByDestination();
            system("pause");
            break;

        case 6:
            t.showAllTickets();
            system("pause");
            break;

        case 7:
            system("cls");
            adminMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            viewBookingsMenu();
        }
    }
}
