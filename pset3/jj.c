#include <stdio.h>
#include <cs50.h>

int
main(void)
{
	printf("Temperature in C: ");
	float c = GetFloat();
	float f = (c * (9.0 / 5) + 32);
	printf("%.1f C = %.1f F", c, f);
}
