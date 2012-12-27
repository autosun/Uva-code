/**
 * ClockHands
 */

#include <stdio.h>
#include <math.h>

int main() {
    int hour, minute;
    float angles = 0;

    const int angle_per_min = 6;
    const int angle_per_hr = 30;
    const float angle_min_hr = 0.5;

    scanf("%d:%d", &hour, &minute);

    while (hour != 0 || minute != 0) {
        hour %= 12;
        float angle_min = minute * angle_per_min;
        float angle_hr = hour * angle_per_hr + minute * angle_min_hr;

        angles = fabs(angle_min - angle_hr);
        while (angles > 180)
            angles = fabs(360 - angles);
        
        printf("%.3f\n", angles);
        scanf("%d:%d", &hour, &minute);
    }

    return 0;
}

