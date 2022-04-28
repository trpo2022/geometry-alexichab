#pragma once
#include "point.h"

struct Circle {
    struct Point center;
    float radius;
};

float calculateCirclePerimeter(float radius);
float calculateCircleArea(float radius);
void CircleInfo(struct Circle circle);