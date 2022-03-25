#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//pedir que me expliquen:
    //mandar matrices a funciones
    //como definirlas 
    
void printing(char board[3][3])
{
    printf("------------------ \n");
    int j,i;
    for (j=0; j<3; j++)
    {
        for (i=0; i<3; i++)
        {
            printf("%c    ", board[j][i]);
        }
        printf("\n");
    }
}

void writing(char player, char board[3][3])
{
    int c,f;
    printf("Escriba que columna quiere editar \n");
    scanf("%d", &c);
    printf("Escriba que fila quiere editar \n");
    scanf("%d", &f);
    board[c-1][f-1] = player;
    printing(board);
}

int has_free_cell(char board[3][3], char p)
{
    int j,i,cont_n,cont_d;
    cont_d = 0;
    cont_n = 0;
    for (j=0; j<3; j++)
    {
        for (i=0; i<3; i++)
        {
            if (board[j][i] == p){
                cont_n = cont_n + 1;  
            }
            }
        }
        if (board[j][j] == p){
            cont_d = cont_d + 1;        
    }
    if ((cont_n == 3) || (cont_d == 3)){
        printf("Player ""%c " "win \n", p);
        return 1;
    }
    else{
        return 0;
    }
}

void get_winner(char board[3][3], char player1, char player2)
{
    int t,turno,status;
    printf("Iniciando juego...\n");
    printf("Player1: X \n");
    printf("Player2: O \n");
    turno = 1;
    t = 1;
    while (t == 1)
    {
        if (turno == 1){
            printf("Turno de jugador1 \n");
            printing(board);
            writing(player1,board);
            status = has_free_cell(board,player1);
            if (status == 1){
                t = 0;
            }            
            turno = 0;
        }

        else{
            printf("Turno de jugador2\n");
            printing(board);
            writing(player2,board);
            status = has_free_cell(board, player2);
            if (status == 1){
                t = 0;
            }
            turno = 1;
        }

    }
}

int main(void)
{
    char xplayer,oplayer;
    xplayer = 'X';
    oplayer = 'O';
    
    char board [3][3] = {
    { '-', '-', '-' },
    { '-', '-', '-' },
    { '-', '-', '-' }
    };

    get_winner(board,xplayer,oplayer);
    return 0;
}

//hice algunos cambios a las funciones has_free_cell y get_winner