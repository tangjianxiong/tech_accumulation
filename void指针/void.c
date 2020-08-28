#include <stdio.h>

int main()
{

    int num1 = 1;
    char char1 = 'b';

    /*Define two void pointer types*/
    void *void_pointer_1;
    void *void_pointer_2;

    /*Give different void Pointers to different data types*/
    void_pointer_1 = &num1;
    void_pointer_2 = &char1;

    printf("void_pointer_1:%d,void_pointer_2:%c,", *((int *)void_pointer_1), *((char *)void_pointer_2));

    void_pointer_2 = &num1;
    printf("void_proint1:%d\n", *((int *)void_pointer_2));

    float float_1 = 1.25f;
    float *float_pointer = &float_1;
    void *void_float_pointer;
    void_float_pointer = float_pointer;

    printf("float_pointer:%f\n", *((float *)void_float_pointer));
    return 0;
}