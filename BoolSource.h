#ifndef __CS3376_BOOLSOURCE_H__
#define __CS3376_BOOLSOURCE_H__

class BoolSource {
    private:
        float probability_;

    public:
        // Constructors/Destructors
        BoolSource(const float probability);
        ~BoolSource() {};

        // Accessors
        float probability();

        // Mutators
        void set_probability(const float probability);

        // Other
        bool shouldAddToQueue();
};

#endif
