#include <stdio.h>
#include <stdlib.h>

#include "data.h"

//El operador sizeof() devuelve la cantidad de bytes ocupados por una expresión
//p = malloc(sizeof(int));
//lu es long unsigned
void print_data(data_t d)
{
	printf("NOMBRE: %s\n"
	       "EDAD  : %d años\n"
	       "ALTURA: %d cm\n\n", d.name, d.age, d.height);
}

int main(void)
{

	data_t messi = { "Leo Messi", 169, 34 };
	print_data(messi);

    data_t *d = NULL;
    d = &messi;

    unsigned long s,n=sizeof(d->name),a=sizeof(d->age),h=sizeof(d->height);

    s = sizeof(messi);
    
	printf("name-size  : %lu bytes\n"
	       "age-size   : %lu bytes\n"
	       "height-size: %lu bytes\n"
	       "data_t-size: %lu bytes\n", n, a, h, s);
 
	return EXIT_SUCCESS;
}
