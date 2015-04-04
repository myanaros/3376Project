// Standard library includes

// Project includes
#include "BoolSource.h"

//return probability
int BoolSource::probability()
{
    return probability_;
}

//set the probability
void BoolSource::set_probability(int probability_in)
{
    probability_ = probability_in;
}

//TODO whether or not something should be added to queue
bool BoolSource::shouldAddToQueue()
{
    return false;
}
