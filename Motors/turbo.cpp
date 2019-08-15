//
// Created by Cassandra Coyle on 2/17/2018.
//

#include "turbo.h"


Turbo::Turbo(int Cylinders, int Displacement, int Boost, int Feul_Octane, int Horsepower, int Torque)
        : Motors(Cylinders, Displacement), Boost(Boost), Feul_Octane(Feul_Octane), Horsepower(Horsepower), Torque(Torque) {}
