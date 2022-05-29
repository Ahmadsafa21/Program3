#include "database.h"
#include <iostream>
#include <cstring>

//Ahmad Safa
//This file is the cpp file that will manage the functions
//for my database, which is my red black tree!

node::node():
    left{nullptr},
    right{nullptr},
    color{"red"},
    player_data{nullptr}
{
}
node::~node()
{
    delete player_data;
}
    

node *& node::getLeft()
{
    return left;
}

void node::setLeft(node * left)
{
    this->left = left;
}

node *& node::getRight()
{
    return right;
}

void node::setRight(node * right)
{
    this->right = right;
}

shooting * node::getData()
{
    return player_data;
}

void node::setData(shooting * data)
{
    player_data = data;
}

void node::setColor(const string &color)
{
    this->color = color;
}

string node::getColor()
{
    return color;
}

RBT::RBT():
    root{nullptr},
    parent{nullptr},
    grandParent{nullptr},
    temp_parent{nullptr},
    uncle{nullptr},
    left{false}
{
}

RBT::~RBT()
{
    removeAll(root);
}

void RBT::removeAll(node *& root)
{
    if (!root)
        return;

    removeAll(root->getLeft() );
    removeAll(root->getRight() );

    delete root;
}



int RBT::insert(const char * setName, const int &age, const bool &setWinner, const int &targets_shot, const int &meters_away)
{
    int count{0};
    if (!root)
    {
        root = new node;
        root->setData(new shooting(setName, age, setWinner, targets_shot, meters_away) ); 
        root->setColor("black");
        return 1;
    }
    count = insert(setName, age, setWinner, targets_shot, meters_away, root);
    root->setColor("black");
    return count;
}


int RBT::insert(const char * setName, const int &age, const bool &setWinner, const int &targets_shot, const int &meters_away, node * curr)
{
    int count{0};

    if (strcmp(curr->getData()->getName(), setName) == 0) 
    {
        *curr->getData() += targets_shot ;
        return 0;
    }

    if (*curr->getData() == targets_shot)
        return 0;

    if (!curr->getRight() && *curr->getData() < targets_shot)

    {
        curr->getRight() = new node;
        curr->getRight()->setData(new shooting(setName, age, setWinner, targets_shot, meters_away) );
        fix_tree(curr->getRight() );
        return 1;
    }

    if (!curr->getLeft() && *curr->getData() > targets_shot)
    {
        curr->getLeft() = new node;
        curr->getLeft()->setData(new shooting(setName, age, setWinner, targets_shot, meters_away) ); 
        fix_tree(curr->getLeft() );
        return 1;
    }

    if (targets_shot < *curr->getData() )
        count += insert(setName, age, setWinner, targets_shot, meters_away, curr->getLeft() );
    else 
        count += insert(setName, age, setWinner, targets_shot, meters_away, curr->getRight() );

    return count;
}

void RBT::display()
{
    if (!root)
        return;
    display(root);
}


void RBT::display(node * curr)
{
    if (!curr)
        return;

    cout << *curr->getData() << endl;

    display(curr->getLeft() );
    display(curr->getRight() );

    return;
}
bool RBT::search(const char * name)
{
    return search(name , root);
}

bool RBT::search(const char * name, node * curr)
{
    bool found = false;
    if (!curr)
        return found;

    if (strcmp(curr->getData()->getName(), name) == 0 )
    {
        return true;
    }

    if (strcmp(name, curr->getData()->getName()) >  0 )
        found = search(name, curr->getRight() );
    if (strcmp(name, curr->getData()->getName()) <  0 )
        found = search(name, curr->getLeft() );

    return found;
}


node *& RBT::getParentNode(node * curr, node * curr_root)
{
    if (curr_root && curr)
    {
        if ( curr->getData() == curr_root->getData() )
        {
            temp_parent = nullptr;
            return temp_parent;
        }
        if (curr_root->getRight() == curr || curr_root->getLeft() == curr)
        {
            temp_parent = curr_root;
            return temp_parent;
        }

        if (curr_root->getRight() && curr->getData() > curr_root->getData() )
            getParentNode(curr, curr_root->getRight());
        else if (curr_root->getLeft() && curr->getData() < curr_root->getData() )
            getParentNode(curr, curr_root->getLeft() );
    }
    return temp_parent;
}


void RBT::reColor(node * targetNode)
{
    if (parent->getColor() == "red" && uncle->getColor() == "red")
    {
        grandParent->setColor("red");
        grandParent->getRight()->setColor("black");
        grandParent->getLeft()->setColor("black");
        fix_tree(grandParent);
    }
}


void RBT::fix_tree(node * targetNode)
{
    parent = getParentNode(targetNode, root);
    grandParent = getParentNode(parent, root);
    left = checkParent();


    if(parent && grandParent && uncle)
        reColor(targetNode);

    if (!parent && !grandParent)
        return;

    if (parent->getColor() == "red" && (!uncle || uncle->getColor() == "black") )
    {
        if (left && parent->getLeft() == targetNode)
            right_rotate(parent, targetNode);
        if (!left && parent->getRight() == targetNode)
            left_rotate(parent, targetNode);
        if (!left && parent->getLeft() == targetNode)
        {
            right_rotate(targetNode, targetNode);
            left_rotate(targetNode, targetNode);
        }
        if (left && parent->getRight() == targetNode)
        {
            left_rotate(targetNode, targetNode);
            right_rotate(targetNode, targetNode);
        }
    }
}

bool RBT::checkParent()
{
    if (grandParent)
    {   
        if (grandParent->getRight() == parent)
        {   
            uncle = grandParent->getLeft();
            return false;
        }   

        else if (grandParent->getLeft() == parent)
        {   
            uncle = grandParent->getRight();
            return true;
        }
    }
    return false;

}

void RBT::left_rotate(node * rotate_at, node * newNode)
{
    node * precessor = getParentNode(grandParent, root);

    if (rotate_at == newNode && !left)
    {
        if (!grandParent)
            root = rotate_at;
        else
            grandParent->setRight(rotate_at);
        rotate_at->setLeft(parent);
        rotate_at->setColor("black");

        if (rotate_at->getRight() )
            rotate_at->getRight()->setColor("red");
        if(rotate_at->getLeft() )
            rotate_at->getLeft()->setColor("red");

        parent->setLeft(nullptr);
        parent->setRight(nullptr);

        parent = grandParent;
        grandParent = getParentNode(parent, root);
        left = checkParent();
        return;
    }
    else if(rotate_at == newNode && left)
    {
        if (!grandParent)
            root = rotate_at;
        else
            grandParent->setLeft(rotate_at);
        rotate_at->setLeft(parent);
        rotate_at->setColor("black");

        if (rotate_at->getRight() )
            rotate_at->getRight()->setColor("red");
        if(rotate_at->getLeft() )
            rotate_at->getLeft()->setColor("red");

        parent->setLeft(nullptr);
        parent->setRight(nullptr);

        parent = grandParent;
        grandParent = getParentNode(parent, root);
        left = checkParent();
        return;
    }
    if (precessor)
    {
        precessor->setRight(rotate_at);
        rotate_at->setLeft(grandParent);
        grandParent->setRight(nullptr);
        grandParent->setColor("red");
        rotate_at->setColor("black");
        return;
    }

    root = rotate_at;
    grandParent->setRight(rotate_at->getLeft() );
    root->setLeft(grandParent);
    root->getRight()->setColor("red");
    root->getLeft()->setColor("red");
}


void RBT::right_rotate(node * rotate_at, node * newNode)
{
    node * precessor = getParentNode(grandParent, root);
    if (rotate_at == newNode && !left)
    {
        if (!grandParent)
            root = rotate_at;
        else
            grandParent->setRight(rotate_at);
        rotate_at->setRight(parent);
        rotate_at->setColor("black");

        if (rotate_at->getRight() )
            rotate_at->getRight()->setColor("red");
        if(rotate_at->getLeft() )
            rotate_at->getLeft()->setColor("red");
        parent->setLeft(nullptr);
        parent->setRight(nullptr);
        parent = grandParent;
        grandParent = getParentNode(parent, root);
        left = checkParent();
        return;
    }
    if (rotate_at == newNode && left)
    {
        grandParent->setLeft(rotate_at);
        rotate_at->setRight(parent);
        rotate_at->setColor("black");

        if (rotate_at->getRight() )
            rotate_at->getRight()->setColor("red");
        if(rotate_at->getLeft() )
            rotate_at->getLeft()->setColor("red");

        parent->setLeft(nullptr);
        parent->setRight(nullptr);
        parent = grandParent;
        grandParent = getParentNode(parent, root);
        left = checkParent();
        return;
    }


    if (precessor)
    {
        precessor->setLeft(rotate_at);
        rotate_at->setRight(grandParent);
        rotate_at->setColor("black");
        grandParent->setColor("red");
        grandParent->setLeft(nullptr);
                return;
    }


    root = rotate_at;
    grandParent->setLeft(rotate_at->getRight() );
    root->setRight(grandParent);
    root->getRight()->setColor("red");
    root->getLeft()->setColor("red");
}



