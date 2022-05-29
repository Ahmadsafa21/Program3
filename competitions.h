//Ahmed Safa
//This file is responsible for keeping the prototypes of my olympic sports



#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;


class competition 
{

    public:
        competition();
        ~competition();
        competition(const char * name, const int &age, const bool &winner);

        friend ostream &operator<< (ostream &out, const competition &from);
        competition &operator=(const competition& source);
        char * getName();

    protected:
        char * name;
        int age;
        bool winner;

};

class shooting : public competition
{
    public:
        shooting();
        shooting(const char * setName, const int &age, const bool &setWinner, const int &targets_shot, const int &meters_away);

        friend ostream &operator<<(ostream &out, const shooting &shooter);
        
        shooting &operator=(const shooting &source);
        shooting &operator+=(const int &source);

        friend bool operator<(const shooting &source1, const shooting &source2);
        friend bool operator<(const shooting &source, const int &shots);
        friend bool operator<(const int &shots, const shooting &source);

        friend bool operator<=(const shooting &source1, const shooting &source2);
        friend bool operator<=(const shooting &source, const int &shots);
        friend bool operator<=(const int &shots, const shooting &source);

        friend bool operator>(const shooting &source1, const shooting &source2);
        friend bool operator>(const shooting &source, const int &shots);
        friend bool operator>(const int &shots, const shooting &source);

        friend bool operator>=(const shooting &source1, const shooting &source2);
        friend bool operator>=(const shooting &source, const int &shots);
        friend bool operator>=(const int &shots, const shooting &source);

        friend bool operator==(const shooting &source1, const shooting &source2);
        friend bool operator==(const shooting &source, const int &shots);
        friend bool operator==(const int &shots, const shooting &source);

        friend bool operator!=(const shooting &source1, const shooting &source2);
        friend bool operator!=(const shooting &source, const int &shots);
        friend bool operator!=(const int &shots, const shooting &source);



    protected:
        int targets_shot;
        int meters_away;
};

class skiing : public competition
{
    public:
        skiing();
        skiing(const char * name, const int &age, const bool &winner, const double &elapsed_time, const double &takeoff_speed, const double &distance_traveled);

        friend ostream &operator << (ostream &out, const skiing &skier);
        friend istream &operator >> (istream &in, const skiing &skier);
        skiing &operator=(const skiing&source);
        skiing &operator+=(const skiing&source);
    


    protected:
        double elapsed_time;
        double takeoff_speed;
        double distance_traveled;

};

class weightlifting: public competition
{
    public:
        weightlifting();
        weightlifting(const char * name, const int &age, const bool &winner, const int &weight_lifted, const string &lift_type);

        friend ostream &operator<<(ostream &out, const weightlifting &lifter);
        weightlifting &operator=(const weightlifting &source);
        weightlifting &operator+=(const weightlifting &source);



    protected:
        int weight_lifted;
        string lift_type;

};






