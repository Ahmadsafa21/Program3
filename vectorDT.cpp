#include "vectorDT.h"

//Ahmad Safa
//This file is responsible to manage the vectors for the
//other athletes in my program!



istream &operator>>(istream &in, vectorDT &source)
{
    source.input();
    return in;
}

vectorDT::vectorDT()
{
}

vectorDT::~vectorDT()
{
    for (size_t i =0; i < liftingAthletes.size(); ++i)
        delete liftingAthletes[i]; 

    for (size_t i =0; i < skiingAthletes.size(); ++i)
        delete skiingAthletes[i];
}
void vectorDT::insertLifter(const char * name, const int &age, const bool &winner, const int &weight_lifted, const string &lift_type)
{
    curr = new weightlifting(name, age, winner, weight_lifted, lift_type);

    liftingAthletes.push_back(curr);

}

void vectorDT::displayLifters()
{
    for (size_t i =0; i < liftingAthletes.size(); ++i)
        cout << *liftingAthletes[i] << endl;
}

void vectorDT::display()
{
    for (size_t i =0; i < skiingAthletes.size(); ++i)
        cout << *skiingAthletes[i] << endl;
}
void vectorDT::input()
{
    double time = 0;
    double takeoff_speed = 0;
    double distance_traveled = 0;
    int age = 0;
    bool winner;
    char * name;
    char * temp_name;
    char userAnswer;
    temp_name = new char[26];

    try
    {        
        cin.clear();
        cout << "Enter the athletes name: ";
        cin.getline(temp_name, 100);
        if(!temp_name)
            throw(temp_name);
        name = new char[strlen(temp_name)+1];
        strcpy(name, temp_name);

        cout << "\nEnter the time it took in seconds (s): ";
        cin >> time;
        if (time < 0)
            throw(time);

        cout << "\nEnter the takeoff speed (km/h): ";
        cin >> takeoff_speed;
        if (takeoff_speed < 0)
            throw(takeoff_speed);

        cout << "\nEnter the distance traveled in meters (m) ";
        cin >> distance_traveled;
        if(distance_traveled < 0)
            throw(distance_traveled);

        cout << "\nEnter the athelete's age: ";
        cin >> age;
        if (age < 0)
            throw (age);

        cout << "\nWas this athlete the winner? (y/n): ";
        cin >> userAnswer;
        if (userAnswer == 'y')
            winner = true;
        else if (userAnswer == 'n')
            winner = false;
        else
            throw(userAnswer);
        cin.clear();
    }
    catch(char)
    {
        cout << "Wrong entry, setting athlete as non winner." << endl;
        winner = false;
    }
    catch(...)
    {
        cout << "Invalid entry exception handler called!\nAborting." <<endl;
        return ;
    }
    
    cout << endl;

    temp = new skiing(name, age, winner, time, takeoff_speed, distance_traveled);
    
    skiingAthletes.push_back(temp);
    delete [] name;
    delete [] temp_name;
}
