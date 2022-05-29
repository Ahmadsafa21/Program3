#include "competitions.h"
#include <cstring>
#include <iostream>

//Ahmad Safa
//This file is the cpp that will be responsible for 
//setting up the functions for my hierarchy


competition::competition():
    name{nullptr},
    age{0},
    winner{false}
{
}

competition::competition(const char * name, const int &age, const bool &winner):
    name {new char [strlen(name)+1] },
    age{age},
    winner{winner}
{
    strcpy(this->name, name);
}

competition::~competition()
{
    if(name)
        delete [] name;
}

ostream &operator << (ostream &out, const competition &from)
{
    out << "Name: " << from.name << endl;
    out << "Age: " << from.age << endl;
    if (from.winner)
        out << "This athlete won the competition" << endl;
    else
        out << "This athlete was not the winner" << endl;

    return out;
}

char * competition::getName()
{
    return name;
}

competition &competition::operator=(const competition &source)
{
    if (this == &source)
        return *this;

    this->name = new char[strlen(source.name)+1];
    strcpy(this->name, source.name);

    this->age = source.age;
    this->winner = source.winner;

    return *this;
}



shooting::shooting():
    targets_shot{0},
    meters_away{0}
{
}

shooting::shooting(const char *setName, const int &age, const bool &setWinner, const int &targets_shot, const int &meters_away):
    competition(setName, age, setWinner),
    targets_shot{targets_shot},
    meters_away{meters_away}
{
}

ostream &operator <<(ostream &out, const shooting &shooter)
{
    out << static_cast<const competition&>(shooter);
    out << "Targets shot: " << shooter.targets_shot << endl;
    out << "Player was standing " << shooter.meters_away << " meters away" << endl;

    return out;
}

shooting &shooting::operator=(const shooting &source)
{
    if (this == &source)
        return *this;

    this->targets_shot = source.targets_shot;
    this->meters_away = source.meters_away;

    return *this;
}

shooting&shooting::operator+=(const int &source)
{
    this->targets_shot += source;
    return *this;
}

bool operator<(const shooting &source1, const shooting &source2) 
{
    if (source1.targets_shot < source2.targets_shot)
        return true;
    return false;
}
bool operator<(const shooting &source, const int &shots)
{
    if (source.targets_shot < shots)
        return true;
    return false;
}

bool operator<(const int &shots, const shooting &source)
{
    if (shots < source.targets_shot)
        return true;
    return false;
}

bool operator<=(const shooting &source1, const shooting &source2) 
{
    if (source1.targets_shot <= source2.targets_shot)
        return true;
    return false;
}

bool operator<=(const shooting &source, const int &shots)
{
    if (source.targets_shot <= shots)
        return true;
    return false;
}
bool operator<=(const int &shots, const shooting &source)
{
    if (shots <= source.targets_shot)
        return true;
    return false;
}

bool operator>(const shooting &source1, const shooting &source2) 
{
    if (source1.targets_shot > source2.targets_shot)
        return true;
    return false;
}
bool operator>(const shooting &source, const int &shots)
{
    return (source.targets_shot > shots);
}

bool operator>(const int &shots, const shooting &source)
{
    return(shots > source.targets_shot);
}

bool operator>=(const shooting &source1, const shooting &source2) 
{
    
    return (source1.targets_shot >= source2.targets_shot);
}
    
bool operator>=(const shooting &source, const int &shots)
{
    return (source.targets_shot >= shots);
}

bool operator>=(const int &shots, const shooting &source)
{
    return (shots >= source.targets_shot);
}
bool operator==(const shooting &source1, const shooting &source2) 
{
    
    return (source1.targets_shot == source2.targets_shot);
}
bool operator==(const shooting &source, const int &shots)
{
    return (source.targets_shot == shots);
}
bool operator==(const int &shots, const shooting &source)
{
    return (shots == source.targets_shot);
}

bool operator!=(const shooting &source1, const shooting &source2) 
{
    if (source1.targets_shot != source2.targets_shot)
        return true;
    return false;
}

bool operator!=(const shooting &source, const int &shots)
{
    return (source.targets_shot != shots);
}

bool operator!=(const int &shots, const shooting &source)
{
    return (shots != source.targets_shot);
}




skiing::skiing(const char * name, const int &age, const bool &winner, const double &elapsed_time, const double &takeoff_speed, const double &distance_traveled):
    competition(name, age, winner),
    elapsed_time{elapsed_time},
    takeoff_speed{takeoff_speed},
    distance_traveled{distance_traveled}
{
}

ostream &operator << (ostream &out, const skiing &skier)
{

//    competition::operator<<(out, skier);
    out << static_cast<const competition&> (skier); // Calls the operator<< for the base class
    out << "Elapsed Time: " << skier.elapsed_time << " seconds" << endl;
    out << "Take off Speed: " << skier.takeoff_speed << "km/h" <<endl;
    out << "Distance traveled " << skier.distance_traveled << "meters" << endl;

    return out;
}

skiing &skiing ::operator=(const skiing &source)
{
    if (this == &source)
        return *this;

    this->elapsed_time = source.elapsed_time;
    this->takeoff_speed = source.takeoff_speed;
    this->distance_traveled = source.distance_traveled;

    return *this;
}

skiing &skiing::operator+=(const skiing &source)
{
    this->elapsed_time += source.elapsed_time;
    this->takeoff_speed += source.takeoff_speed;
    this->distance_traveled += source.distance_traveled;

    return *this;
}

istream &operator>>(istream &in, const skiing &skier)
{
//    in >> skier.elapsed_time;

    return in;
}

weightlifting::weightlifting():
    weight_lifted{0},
    lift_type{"empty"}
{
}

weightlifting::weightlifting(const char * name, const int &age, const bool &winner, const int &weight_lifted, const string &lift_type):
    competition(name, age, winner),
    weight_lifted{weight_lifted},
    lift_type{lift_type}
{
}

ostream &operator<<(ostream &out, const weightlifting &lifter)
{
    out << static_cast<const competition&>(lifter);
    out << "Weight lifted: " << lifter.weight_lifted<< endl;
    out << "Lift type: " << lifter.lift_type << endl;

    return out;
}

weightlifting &weightlifting::operator=(const weightlifting &source)
{
    if (this == &source)
        return *this;

    this->weight_lifted = source.weight_lifted;
    this->lift_type = source.lift_type;


    return *this;
}

weightlifting &weightlifting::operator +=(const weightlifting &source)
{
    this->weight_lifted += source.weight_lifted;
    this->lift_type += source.lift_type;

    return *this;
}













