#include <cstring>

template<typename T>
struct vector3
{
    T x{};
    T y{};
    T z{};
};

template<typename T>
struct vector2
{
    T x{};
    T y{};
};

class Logic
{
public:
    Logic(size_t _screeWidth, size_t _screenHeight)
            : screenWidth{_screeWidth}
            , screenHeight{_screenHeight}
    {};



    float pitch{};
    float yaw{};
    float roll{};

    vector2<int> projectToScreen(vector3<float> point);

private:
    size_t screenWidth;
    size_t screenHeight;

    float calculateX(vector3<float> vec);
    float calculateY(vector3<float> vec);
    float calculateZ(vector3<float> vec);

    vector3<float> rotatePoint(vector3<float> vec);

};