// Standard library includes

// Project includes
#include "BoolSource.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// ---------------------------------------------------------------------
// Constructors / Destructors
// ---------------------------------------------------------------------

BoolSource::BoolSource(const float probability) {
    set_probability(probability);
}

// ---------------------------------------------------------------------
// Accessors
// ---------------------------------------------------------------------

// return probability
float BoolSource::probability()
{
    return probability_;
}

// ---------------------------------------------------------------------
// Mutators
// ---------------------------------------------------------------------

// set the probability
void BoolSource::set_probability(const float probability)
{
    probability_ = probability;
}

// ---------------------------------------------------------------------
// Other Member Functions
// ---------------------------------------------------------------------

// If the random value is less than the probability than
// a plane should be added to it's respective queue
bool BoolSource::shouldAddToQueue()
{
    // TODO: rand() % 100 will likely not have uniform distribution.
    // This is due to two factors:
    // 1:   UINT_MAX % 100 = 35 (on 32-bit systems)
    //      So rand() % 100 will yield more numbers between 0 and 35
    //      than between 35 and 99.
    // 2:   Many PRNGs have very biased moduli.
    bool shouldAdd = (rand() % 100) < probability() * 100;

    if(shouldAdd)
    {
        return true;
    }
    else
    {
        return false;
    }
}
