//Ahmed Safa
//This file is responsible for managing the data for my binary search tree




#include "competitions.h"


class node
{
    public:


        node();
        node(const char * name);
        ~node();
        node(const node &from);

        node *& getLeft();
        void setLeft(node * left);

        node *& getRight();
        void setRight(node * right);

        char * getName();
        void setName(char * name);

        shooting * getData();
        void setData(shooting * data);

        void setColor(const string &color);
        string getColor();
    protected:
        node * left;
        node * right;
        string color;
        shooting * player_data;

};


class RBT //Red black tree
{
    public:
        RBT();
        ~RBT();
        RBT(const RBT &from);

        int insert(const char * setName, const int &age, const bool &setWinner, const int &targets_shot, const int &meters_away);
        void reColor(node * targetNode);
        void fix_tree(node * targetNode);
        bool search(const char * name);
        bool search(const char * name, node * curr);

        void left_rotate(node * rotate_at, node * newNode);
        void right_rotate(node * rotate_at, node * newNode);

        void display();

    protected:
        node * root;
        node * parent;
        node * grandParent;
        node * temp_parent;
        node * uncle;
        bool left;

        int insert(const char * setName, const int &age, const bool &setWinner, const int &targets_shot, const int &meters_away, node * curr);
        void removeAll(node *& root);
        bool checkParent();
        void display(node * curr);
        node *& getParentNode(node * curr, node * curr_root);
};

