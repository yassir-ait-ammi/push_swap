
int fsqrt(int nb) {
    float i = 1;

    if (nb < 0)
        return 0;

    while (i <= nb / i)
	{
        if (i * i == nb)
            return i;
        i += 0.1;
    }
    return i;
}
#include <stdio.h>
#include <math.h>
int main()
{
	int i = fsqrt(100) + 500 / 500 + 5;
	printf("%d\n", i);
}
