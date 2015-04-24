#ifndef __CS3376_QUEUE_H__
#define __CS3376_QUEUE_H__

#include <list>

// Forward declaration of Airplane in lieu of #include "Airplane.h".
//   We don't need to know the interface of the Airplane class here, just
//   that the class exists.
class Airplane;

// We really don't need any functionality in Queue beyond what the
// std::list<> template already provides.
class Queue : public std::list<Airplane> {
    private:
    public:
};

#endif
