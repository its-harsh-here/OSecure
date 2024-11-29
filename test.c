#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *a;
    a = popen("w", "r");
    fprintf("%s", a);
    
    
}