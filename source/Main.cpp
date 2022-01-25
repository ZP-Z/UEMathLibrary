// main.cpp for test

#include <iostream>
#include "Core.h"

using namespace UEMath;
int main()
{
    std::cout << "Hello UEMath!\n";
    int test = 2;
    if (test == 1)
    {// vector and rotation
        auto q1 = FQuat(0.3, 0.3, 0.3, 0.3);
        auto q2 = FQuat(0.4, 0.4, 0.4, 0.4);
        FVector TestBase = FVector(0, 0, 1);
        FQuat Rot = FQuat(FVector(1, 0, 0), 0.5 * PI);

        FVector After = Rot.RotateVector(TestBase);
        std::cout << After.X << " " << After.Y << " " << After.Z << std::endl;
    }
    else if (test == 2)
    {// containers
        TArray<int> arr;
        arr.SetNum(10);
        int index = 0;
        for (auto& v : arr)
        {
            v = index++;
        }

        arr.RemoveAt(5);
        for (auto v : arr)
        {
            std::cout << " " << v << std::endl;
        }
    }
}