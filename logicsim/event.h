#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        // for min heap you want to do greater<int> (operator>() for min-heap)
        // want the event with smallest time to be at top of the heap (since min heap)
        bool operator()(Event* firstEvent, Event* secondEvent){
            return firstEvent->time < secondEvent->time;
            // if returns true, this means that firstEvent will be placed AFTER secondEvent (since that means first would be greater time)
        }
} EventLess;
	
#endif
