#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0;
int salah = 0;

typedef struct {
    char username[20];
    char password[20];
} login;

void Sign_up(login* a)
{
    char n;
    puts("\n\n\n\n===================================================================================\n");
    printf("                                  === register ===                                  \n");
    printf("\nUsername \t: ");
    gets(a->username);
    printf("Password \t: ");
    gets(a->password);
    puts("\n\n\n\nyour account has been created...");
    puts("===================================================================================\n");
    system("pause");
    system("cls");
    puts("===================================================================================\n");
    input(a);
}

void input(login b)
{
    while (i < 3) {
        printf("                                 === select one ===                                 \n\n");

        printf("login or register ? ");
        char input[128];
        fflush(stdin);
        gets(input);

        if (strcmp(input, "login") == 0) {
            puts("\n\n\n\n===================================================================================\n");
            printf("                                    === login ===                                    \n");
            printf("\nUsername \t: ");
            char x[128];
            fflush(stdin);
            gets(x);
            printf("Password \t: ");
            char y[128];
            fflush(stdin);
            gets(y);
            if (strcmp(x, b.username) == 0 && strcmp(y, b.password) == 0) {
                system("cls");
                hangman();
            } else {
                puts("\n\n\n\nplease register !!! ");
                system("pause");
                system("cls");
            }
        } else if (strcmp(input, "register") == 0) {
            Sign_up(&b);
        } else {
            i++;
        }
    }
}

void gambar()
{
    char array[3][100] = {
        "         ---   \n        |   |  \n         ---   \n",
        "          |    \n        / | \\  \n       /  |  \\ \n",
        "          |    \n         / \\   \n        /   \\  \n"
    };
    printf("-----------\n");
    printf("          |    \n");
    for (int i = 0; i < salah; i++) {
        printf("%s", array[i]);
    }
}

void hangman()
{
    int max_salah = 4;
    int count_salah = 0;
    system("cls");
    puts("====================================================================================\n");
    puts("                                   = Insert Word =                                  \n");
    puts("====================================================================================\n");
    char answer[128];
    printf("Enter word to guess ( max 127 word ): ");
    fflush(stdout);
    scanf("%s", answer);
    system("cls");
    puts("====================================================================================\n");
    puts("                                   = game start =                                   \n");
    puts("====================================================================================\n");
    int N = strlen(answer);
    int mask[N];
    for (int i = 0; i < N; ++i) {
        mask[i] = 0;
    }
    salah = 0;
    int gameover = 0;
    while (!gameover) {
        count_salah = 0;
        printf("The word is : ");
        for (int j = 0; j < N; ++j) {
            if (mask[j]) {
                printf("%c", answer[j]);
            } else {
                printf("*");
            }
        }
        printf("  Kesempatan kesalahan : %d", max_salah - salah);
        printf("\n");
        char guess;
        printf("Letter? ");
        fflush(stdout);
        scanf(" %c", &guess);
        for (int k = 0; k < N; ++k) {
            if (answer[k] == guess) {
                mask[k] = 1;
            } else if (answer[k] != guess) {
                count_salah++;
            }
        }
        gambar();
        if (count_salah == N) {
            salah++;
            printf("Tebakan anda salah!\n");
        }
        gameover = 1;
        for (int m = 0; m < N; ++m) {
            if (!mask[m]) {
                gameover = 0;
                break;
            }
        }
        if (salah == max_salah)
            gameover = 1;
    }
    if (salah == max_salah) {
        puts("====================================================================================\n");
        printf("\nGame Over!!!! The word is \"%s\".                                                    \n", answer);
        printf("\n====================================================================================");
    } else {
        puts("====================================================================================\n");
        printf("\nVictory!!!! The word is \"%s\".                                                      \n", answer);
        printf("\n====================================================================================");
    }
    akhir();
}

void akhir()
{
    char x;
    int n = 0;
    while (n < 3) {
        printf("\n\n\n\n\nApakah anda ingin bermain lagi [y/n] :");
        scanf(" %c", &x);
        switch (x) {
        case 'y':
            system("cls");
            hangman();
            break;
        case 'n':
            exit(0);
            break;
        }
    }
}

int main()
{
    system("cls");
    system("color 0b");
    puts("\n+=================================================================================+\n");
    printf("|                                  Hangman Games                                  |\n");
    puts("\n+=================================================================================+\n");
    login b;
    input(b);
    puts("input error 404....");
    system("pause");
    return 0;
}
