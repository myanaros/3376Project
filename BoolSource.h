#ifndef __CS3376_BOOLSOURCE_H__
#define __CS3376_BOOLSOURCE_H__

class BoolSource {
    private:
        float probability_;
        static bool is_seeded_;

        // Private Accessors
        float probability();
        bool is_seeded();

        // Private Mutators
        void set_probability(const float probability);
        void set_is_seeded(const bool is_seeded);

    public:
        // Constructors/Destructors
        BoolSource(const float probability);
        ~BoolSource() {};

        // Other
        bool decide();
};

#endif
