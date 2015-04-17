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
    bool shouldAdd = (rand() % 100) < probability_ * 100;

    if(shouldAdd)
    {
        return true;
    }
    else
    {
        return false;
    }
}
