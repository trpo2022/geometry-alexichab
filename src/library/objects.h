#pragma once

#include "library/circle.h"
#include "library/point.h"
#include "library/triangle.h"

typedef enum object_type { CIRCLE, TRIANGLE } object_type;

typedef struct object {
    struct Circle circle;
    struct Triangle triangle;
    object_type type;
} object;

int check_object(char* input, char** token);
