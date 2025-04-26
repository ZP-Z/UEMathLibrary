// main.cpp for test

#include <iostream>
#include "UEMathCore.h"

using namespace UEMath;

FQuat AverageQuat(const TArray<FQuat>& In);

int main()
{
    std::cout << "Hello UEMath!\n";
    int test = 4;
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
    else if (test == 3)
    {
        FVector pos_a_base = FVector(1, 1, 1);
        FVector pos_a_curr = FVector(2, 0.3, 0.5);

        FVector pos_b_base = FVector(1.3, 0.6, 1.9);
        FVector pos_b_curr = FVector(3.1, 1.2, 0.7);

        FVector ab_base = pos_b_base - pos_a_base;
        FVector ab_curr = pos_b_curr - pos_a_curr;

        FQuat rot_1 = FQuat::FindBetweenVectors(ab_base, ab_curr);

		ab_base = pos_a_base - pos_b_base;
		ab_curr = pos_a_curr - pos_b_curr;
        FQuat rot_2 = FQuat::FindBetweenVectors(ab_base, ab_curr);

        std::cout << "rotation" << std::endl;
    }
	else if (test == 4)
	{
        FQuat q1 = FQuat(FVector(0, 0, 1), 0.5);
        FQuat q2 = FQuat(FVector(0, 0, 1), 0.4);
        FQuat q3 = FQuat(FVector(0, 0, 1), 1.5);
        FQuat q4 = FQuat(FVector(0, 0, 1), 2.7);

        TArray<FQuat> q_arr = { q1, q2, q3, q4 };
        FQuat AvgRot = AverageQuat(q_arr);
        std::cout << q1.GetAngle() << " " << q2.GetAngle() << " " << q3.GetAngle() << " " << q4.GetAngle() << " " << AvgRot.GetAngle() << std::endl;
	}
}

FQuat AverageQuat(const TArray<FQuat>& In)
{
	FQuat Result;
	TArray<FQuat> QuatArr = In;
	int Num = QuatArr.Num();
	int Error = 0;

	while (Num > 1)
	{
		if (Error >= 10) break;
		Error++;

		int k = 0;
		for (int i = 0; i + 1 < Num; i += 2)
		{
			FQuat Qa = QuatArr[i];
			FQuat Qb = QuatArr[i + 1];

			FQuat AvgQuat = FQuat::Slerp(Qa, Qb, 0.5f);

			QuatArr[k] = AvgQuat;
			k++;
		}

		int Last = Num;
		Num = k;

		if ((Last & 1) == 1)
		{
			k++;
			Num++;
			QuatArr[k] = QuatArr[Last - 1];
		}
	}
	Result = QuatArr[0];
	return Result;
}