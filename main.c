#include <stdio.h>
#define SIZE 3

// игра окончена ?
int game_over(char(*arr)[SIZE]){ 
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j)
            if(arr[i][j] == '0' || arr[i][j] == 0) return 0;} // если где либо содержится 0 то нет
    return 1;
}

int is_win(char(*arr)[SIZE])
{   
    int x = 0, o = 0;
    // диагональ слева направа
    for(int i = 0; i < SIZE; ++i) {if(arr[i][i] == 'x') x++; else if(arr[i][i] == 'o') o++;}
    if(x == 3) return 1; else if(o == 3) return 2; else{x = 0; o = 0;}    
    //диагональ справа налево 
    int help = SIZE-1; // чтобы взять 2 1 0 по j нам понадобится помощь которую мы будем уменьшать в процессе
    for(int i = 0; i < SIZE; ++i) {if(arr[i][help] == 'x') x++; else if(arr[i][help] == 'o') o++; help--;}
    if(x == 3) return 1; else if(o == 3) return 2; else{x = 0; o = 0;}
    //ряды по горизонтали
    for(int i = 0; i < SIZE; ++i){ 
        for(int j = 0; j < SIZE; ++j){if(arr[i][j] == 'x') x++; else if(arr[i][j] == 'o') o++;}
        if(x == 3) return 1; else if(o == 3) return 2; else{x = 0; o = 0;}}
    //колонки по вертикали
    for(int i = 0; i < SIZE; ++i){ 
        for(int j = 0; j < SIZE; ++j){if(arr[j][i] == 'x') x++; else if(arr[j][i] == 'o') o++;}
        if(x == 3) return 1; else if(o == 3) return 2; else{x = 0; o = 0;}}
        
    if(game_over(arr)) return 3; // если ни одно из условий не сработало и игра окончена то это ничья
    return 0; // игра окончена
} 

int main(void)
{
    char pole[SIZE][SIZE] = {0};
    char* ptr_p = &pole[0][0];
    int count = 0;
    while(count < SIZE * SIZE && scanf("%hhd", ptr_p) == 1) {
        *ptr_p = (*ptr_p == 1) ? 'x' : (*ptr_p == 2) ? 'o': *ptr_p;
        ptr_p++;
        count++;
    }

    printf("%d\n", is_win(pole));
    return 0;
}
