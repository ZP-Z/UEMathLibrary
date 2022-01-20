// main.cpp for test

#include <iostream>
#include "Math/Quat.h"

using namespace UE4Math;
int main()
{
    std::cout << "Hello UEMath!\n";
    int test = 1;
    if (test == 1)
    {
        auto q1 = FQuat(0.3, 0.3, 0.3, 0.3);
        auto q2 = FQuat(0.4, 0.4, 0.4, 0.4);
        FVector TestBase = FVector(0, 0, 1);
        FQuat Rot = FQuat(FVector(1, 0, 0), 0.5 * PI);

        FVector After = Rot.RotateVector(TestBase);
        std::cout << After.X << " " << After.Y << " " << After.Z << std::endl;
    }
}