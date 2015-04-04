#ifndef __CS3376_BOOLSOURCE_H__
#define __CS3376_BOOLSOURCE_H__

class BoolSource {
    private:
        int probability_;
    public:
        int probability();
        void set_probability(int);

        bool shouldAddToQueue();
};

#endif
