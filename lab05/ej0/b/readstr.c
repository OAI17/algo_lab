#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

/*char *fgets(char *s, int size, FILE *stream);*/
int main(void) {
    char user_input[MAX_LENGTH];
    size_t len;

    printf("Ingrese su nombre y apellido: ");
    //scanf("%s", user_input);
    fgets(user_input,MAX_LENGTH,stdin);

    len = strlen(user_input);
    user_input[len-1] = '\0';
    
    printf("Te damos la bienvenida %s a este maravilloso programa!\n", user_input);

    return EXIT_SUCCESS;
}

