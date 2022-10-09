#include "Logic.h"
#include <math.h>

float Logic::calculateX(vector3<float> vec)
{
    using namespace std;
    return vec.y * sin(pitch) * sin(yaw) * cos(roll) - vec.z * cos(pitch) * sin(yaw) * cos(roll) +
           vec.y * cos(pitch) * sin(roll) + vec.z * sin(pitch) * sin(roll) + vec.x * cos(yaw) * cos(roll);
}

float Logic::calculateY(vector3<float> vec)
{
    using namespace std;
    return vec.y * cos(pitch) * cos(roll) + vec.z * sin(pitch) * cos(roll) -
           vec.y * sin(pitch) * sin(yaw) * sin(roll) + vec.z * cos(pitch) * sin(yaw) * sin(roll) -
           vec.x * cos(yaw) * sin(roll);
}

float Logic::calculateZ(vector3<float> vec)
{
    using namespace std;
    return vec.z * cos(pitch) * cos(yaw) - vec.y * sin(pitch) * cos(yaw) + vec.x * sin(yaw);
}

vector3<float> Logic::rotatePoint(vector3<float> vec)
{
    vector3<float> rotatedPoint;
    rotatedPoint.x = calculateX(vec);
    rotatedPoint.y = calculateY(vec);
    rotatedPoint.z = calculateZ(vec);
    return rotatedPoint;
}

vector2<int> Logic::projectToScreen(vector3<float> point)
{
    vector3<float> rotatedPoint = rotatePoint(point);
    vector2<int> imgPoint = {0, 0};

    //TODO: why?
    float focal = 1 / (rotatedPoint.z + 41);

    //TODO: why?
    imgPoint.x = static_cast<int>(screenWidth / 2.f + focal * 40.f * rotatedPoint.x);
    imgPoint.y = static_cast<int>(screenHeight / 2.f + focal * 40.f * rotatedPoint.y);

    return imgPoint;
}

