//
// Created by Cassandra Coyle on 2/17/2018.
//

#ifndef MOTORS_TURBO_H
#define MOTORS_TURBO_H
#include "motors.h"

class Turbo: public Motors{
public:
    Turbo(int Cylinders, int Displacement, int Boost, int Feul_Octane, int Horsepower, int Torque);

private:

    int Boost;
    int Feul_Octane;
    int Horsepower;
    int Torque;
};



#endif //MOTORS_TURBO_H
