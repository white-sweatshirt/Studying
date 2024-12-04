#include <stdio.h>
#include <limits.h>
#include <float.h>
#define PLACE_FOR_ZERO 1
unsigned long power(int n)
{
    if (n == 1)
        return 1;
    return 2 * power(n - 1);
}

void show_Int()
{
    // tak wiem wykorzystuje wlasciwosc ze wszystkie te tepy pisze sie tak samo i ze zawieraja sie w unsigned-long
    // printf("power of 2 :%llu ", power(32));
    printf("my opinion of  long int :  %ld and in limits.h %d\n", power(32) - PLACE_FOR_ZERO, LONG_MAX);
    /*Note to Future Idiot Franko znak podwaja liczbe mozliwosc wiec normalne ze bedzie 2^33 a nie 2^64
    jak sie podwoi 2^32*/
    printf("unsigned long : %lu and in limits.h : %lu \n", power(33) - PLACE_FOR_ZERO, ULONG_MAX);
    printf("my opinion of   int : %lu and in limits.h %lu \n", power(32) - PLACE_FOR_ZERO, INT_MAX);
    printf("unsigned int :%lu, and in limits.h :%llu \n", power(33) - PLACE_FOR_ZERO, UINT_MAX);
    printf("short %lu and in limits.h: %hu\n", power(16) - PLACE_FOR_ZERO, SHRT_MAX);
    printf("unsigned short %lu and in limits.h: %lu\n", power(17) - PLACE_FOR_ZERO, USHRT_MAX);
    printf("my opinion of   char : %lu and in limits.h %d \n", power(8) - PLACE_FOR_ZERO, CHAR_MAX);
}
double range_Float_Value(double a)
{
    double highest_Posible_Power_Ten = 1;
    double current_Power_Ten = a;
    current_Power_Ten += 1;
    while (current_Power_Ten >highest_Posible_Power_Ten)
    {
        highest_Posible_Power_Ten = current_Power_Ten;
        current_Power_Ten *= 10;
    }
    /* after this a is pure power of ten so we can just copy stuff to current from highest possible */
    current_Power_Ten=highest_Posible_Power_Ten;
    while (a==1)
    {
       ; /* code */
    }
    
    return a;
}

void show_Float()
{
    float a = 0;
}
int main()
{
    show_Int();

    return 0;
}