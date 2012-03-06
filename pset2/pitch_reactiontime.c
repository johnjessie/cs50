#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

#define MILE_IN_FEET 5280.0
#define SECS_IN_HOUR 3600.0

int
main(void)
{
    printf("Pitch speed in mph:\n");
    int mphspeed = GetInt();
    // calculate feet per second from mph
    float fpsspeed = ( (float)mphspeed * MILE_IN_FEET ) / SECS_IN_HOUR;
    // reaction time = distance / feet per sec
    float reactiontime = 60.5 / fpsspeed;
    // Output
    printf("Amount of reaction time for %d mph pitch:\n%.2f seconds\n", mphspeed, reactiontime);
}