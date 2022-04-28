#include "inputread.h"
#include <stdio.h>

void initInput(char array[32])
{
    char prefix[] = "(geometry) ";
    printf("%s", prefix);
    scanf(" %[^\n]", array);
}