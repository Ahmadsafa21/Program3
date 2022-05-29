//Ahmad Safa
//This class is responsible for managing my vector data structure

#include "database.h"
class vectorDT
{
    public:
        vectorDT();
        ~vectorDT();

        friend istream &operator>>(istream &in, vectorDT &source);
        friend ostream &operator<<(ostream &out, vectorDT &source);

        void input();
        void display();

        void insertLifter(const char * name, const int &age, const bool &winner, const int &weight_lifted, const string &lift_type);
        void displayLifters();

    protected:
        vector<skiing*> skiingAthletes;
        vector <weightlifting*> liftingAthletes;
        skiing * temp;
        weightlifting * curr;
         
};
