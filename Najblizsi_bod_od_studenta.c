#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

typedef struct
{
    float x,y,c;
} coordinates;


int main(void)
{

    int j = 0,sm_arr = 0, i = 0, k = 0;
    char conclusion = 0;
    //coordinates c[MAX];
    do
    {
        printf("Zadajte pocet opakovania sekvencie zadania suradnic: ");
        scanf("%d", &j);
        if (j == 0)
        {
            printf("\n!! ERROR CODE 01: Prepacte, minimalny pocet je 1, skuste vyssie cislo!! \n");
        }
        else if (j < 0)
        {
            printf("!! ERROR CODE 02: Prepacte, ale nedokazem vytvorit cyklus v zapornej hodnote !!\nPrajete si hodnotu %d prepisat na %d [Y/n]: ", j, abs(j) );
            scanf(" %c", &conclusion);
            if (conclusion == 'Y' || conclusion == 'y')
            {
                j = abs(j);
                printf("Nastavuje sa nova hodnota %d\n\n", j);
            }
            else
            {
                printf("Opakuje sa cyklus\n\n");
            }
        }
    }
    while (j <= 0);
    coordinates c[j];

    for(i = 0; i < j; i++)
    {
        printf("Prosim zadajte suradnicu x: ");
        scanf("%f", &c[i].x);
        printf("Prosim zadajte suradnicu y: ");
        scanf("%f", &c[i].y);
        //c[i].c = sqrt(pow(fabs(c[i].x),2) + pow(fabs(c[i].y),2));

        c[i].c = sqrt(c[i].x*c[i].x + c[i].y*c[i].y);
        printf("Vzdialenost od stredu je: %.3f\n",c[i].c);
    }

    //for (i = 0; i <= j; i++)
    for (i =1; i < j; i++)
    {
        if (c[i].c < c[sm_arr].c)
        {
            sm_arr = i;
        }
    }

    //for (i = 0; i <= j; i++)
    for (i = sm_arr; i < j; i++)
    {
        if (c[i].c == c[sm_arr].c)
        {
            if (k == 0)
            {
                printf("\n\n-----------------------------------------");
                printf("\nNajblizsie k stredu sa nachadza bod x: %.3f y: %.3f dlzkou %.3f v indexe %d\n", c[sm_arr].x,
                       c[sm_arr].y, c[sm_arr].c, sm_arr);
            }
            else
            {
                printf("V sekvencii sa nasiel dalsi bod s rovnakou dlzkou k stredu: %.3f x: %.3f y: %.3f v indexe %d\n", c[i].c,
                       c[i].x, c[i].y, i);
            }
            k++;
        }
    }



    return 0;

}
