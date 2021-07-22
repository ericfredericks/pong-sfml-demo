#ifndef STATE_H
#define STATE_H
#include <vector>

class State
{
public:
    virtual void init()=0;
    virtual void update()=0;
    virtual void display()=0;
    virtual void exit()=0;
};

class StateStack {
public:
    void push(State* state);
    void update();
    void display();
    void pop();
    std::vector<State*> states;
};
#endif
