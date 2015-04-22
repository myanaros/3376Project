// Standard library includes
#include <iostream>
#include <climits>
#include <cstdlib>

// Project includes
#include "BoolSource.h"

using namespace std;

// ---------------------------------------------------------------------
// Static vars
// ---------------------------------------------------------------------

bool BoolSource::is_seeded_ = false;

// ---------------------------------------------------------------------
// Constructors / Destructors
// ---------------------------------------------------------------------

BoolSource::BoolSource(const float probability) {
    set_probability(probability);
    if (!is_seeded()) {
        srand(time(NULL));
        set_is_seeded(true);
    }
}

// ---------------------------------------------------------------------
// Accessors
// ---------------------------------------------------------------------

// return probability
float BoolSource::probability()
{
    return probability_;
}

// return is_seeded_
bool BoolSource::is_seeded() {
    return is_seeded_;
}

// ---------------------------------------------------------------------
// Mutators
// ---------------------------------------------------------------------

// set the probability
void BoolSource::set_probability(const float probability)
{
    probability_ = probability;
}

// set is_seeded_
void BoolSource::set_is_seeded(const bool is_seeded) {
    is_seeded_ = is_seeded;
}
// ---------------------------------------------------------------------
// Other Member Functions
// ---------------------------------------------------------------------

// returns true with odds according to probability
bool BoolSource::decide()
{
    float randNormal = (float)rand() / (float)UINT_MAX;
    // if a random normalized value between 0 and 1 is less
    // than our probability threshold, return true;
    // Ex. probability = 0.10:
    //      a true random normalized value will be less than 0.10
    //      exactly 10% of the time.
    return randNormal < probability();
}
