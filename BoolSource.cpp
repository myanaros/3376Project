// Standard library includes

// Project includes
#include "BoolSource.h"

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

// TODO whether or not something should be added to queue
bool BoolSource::shouldAddToQueue()
{
    return false;
}
