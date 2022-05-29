#include "interface.h"
#include <iomanip>

//Ahmad Safa
//This file is responsible for making the menu interface
//for the user


void interface::buildAthletes()
{

    shootingAthletes.insert("Ahmad", 19, true, 27, 40);
    shootingAthletes.insert("Ghazal", 17, false, 6, 40);
    shootingAthletes.insert("Yasmina", 39, false, 8, 40);
    shootingAthletes.insert("Peter", 29, false, 13, 40);
    shootingAthletes.insert("Robert", 18, false, 15, 40);

//    shootingAthletes.insert("Rania", 29, false, 3, 42);
//    shootingAthletes.insert("Charlie", 79, false, 17, 42);
//    shootingAthletes.insert("Yousof", 19, true, 5, 13);


    otherAthletes.insertLifter("Paul", 28, false, 125, "Power Snatch");
    otherAthletes.insertLifter("Karl", 22, false, 160, "Power Clean");
    otherAthletes.insertLifter("Anna", 25, false, 175, "Push Jerk");
    otherAthletes.insertLifter("Allen", 21, false, 115, "Push Jerk");
    otherAthletes.insertLifter("Levadovski", 20, true, 195, "Squat Snatch");

}

void interface::getUserInput()
{
    char quit = 'p';
    char * name = new char[50];
    cout << "\nPlease enter the skiing athletes." << endl;


    while (quit != 'n')
    {
        cin >> otherAthletes;
        cout << "Do you want to add more athletes? (y/n) :" ;
        cin >> quit;

        if (quit == 'n')
        {
            cout << "Do you want to look for an athlete in the shooting competition ? (y/n) : " ;
            cin >> quit;
            if (quit == 'y')
            {
                cout << "\nBelow are the shooting athletes\n" << endl;
                shootingAthletes.display();
                cout << "Enter athlete's name: ";
                cin >> name;
                if (shootingAthletes.search(name) )
                    cout << "Athlete found!" << endl;
                else
                    cout << "Athlete not found!" << endl;
            }
            return;
        }
        if(quit != 'y')
            return;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << endl;
    otherAthletes.display();
}


void interface::display()
{
    cout << endl << setfill('-') << setw(25) << "-" << " Olympics 2021 " << setfill('-') << setw(25) << "-" << endl;
    cout << "\nShooting athletes that have competed in olympics 2021" << endl;
    cout << endl << setfill('-') << setw(65) << "-" << endl;
    shootingAthletes.display();

    cout << endl << setfill('-') << setw(65) << "-" << endl;
    cout << " \nSkiing athletes that have competed in olympics 2021" << endl;
    cout << endl << setfill('-') << setw(65) << "-" << endl;
    otherAthletes.display();

    cout << endl << setfill('-') << setw(65) << "-" << endl;
    cout << " \nWeighlifting athletes that have competed in olympics 2021" << endl;
    cout << endl << setfill('-') << setw(65) << "-" << endl;
    otherAthletes.displayLifters();
}

