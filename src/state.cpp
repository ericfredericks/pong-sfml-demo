#include "../include/state.hpp"

void StateStack::push(State* state)
{
    state->init();
    states.push_back(state);
}

void StateStack::update()
{
    if (!states.empty())
        states.back()->update();
}

void StateStack::display()
{
    if (!states.empty())
        states.back()->display();
}

void StateStack::pop()
{
    if (!states.empty())
    {
        states.back()->exit();
        states.pop_back();
    }
}
