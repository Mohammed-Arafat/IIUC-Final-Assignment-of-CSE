#include <stdio.h>
#include <string.h>

struct User
{
    unsigned int id, number_of_friends, friends_id[50];

    char name_of_USER[23], password[50], email_address[37];

};

typedef struct User SU;

SU info[200];

unsigned int x;

void showInfo()
{

    unsigned int i, j;

    FILE *fl;

    fl = fopen ("userDB.txt", "r");

    fscanf (fl, "%u", &x);

    for (i = 0; i < x; i++)
    {
        fscanf (fl, "%u\n", &info[i].id);

        fgets (info[i].name_of_USER, sizeof (info[i].name_of_USER), fl);

        fscanf(fl, "\n");

        fgets (info[i].password, sizeof (info[i].password), fl);

        fscanf(fl, "\n");

        fgets (info[i].email_address, sizeof (info[i].email_address), fl);

        fscanf (fl, "%u", &info[i].number_of_friends);

        for ( j = 0; j < info[i].number_of_friends; j++)
        {
            fscanf (fl, "%u", &info[i].friends_id[j]);
        }
    }

    fclose(fl);

    for (i = 0; i < x; i++)
    {
        printf ("%u\n%s\n%s\n%s\n%u\n", info[i].id, info[i].name_of_USER, info[i].password, info[i].email_address, info[i].number_of_friends);

        for ( j = 0; j < info[i].number_of_friends; j++)
        {
            printf ("%u ", info[i].friends_id[j]);
        }

        printf ("\n\n\n");
    }

}




void addInfo()
{
    unsigned int i, j;

    FILE *fl;

    fl = fopen ("userDB.txt", "r");

    fscanf(fl, "%u", &x);

    for (i = 0; i < x; i++)
    {
        fscanf (fl, "%u\n", &info[i].id);

        fgets (info[i].name_of_USER, sizeof (info[i].name_of_USER), fl);

        fscanf(fl, "\n");

        fgets (info[i].password, sizeof (info[i].password), fl);

        fscanf(fl, "\n");

        fgets (info[i].email_address, sizeof (info[i].email_address), fl);

        fscanf (fl, "%u", &info[i].number_of_friends);

        for ( j = 0; j < info[i].number_of_friends; j++)
        {
            fscanf (fl, "%u", &info[i].friends_id[j]);
        }
    }

    fclose(fl);

    x++;

    info[x - 1].id = x;

    printf ("User Name:- ");

    scanf ("\n");

    gets(info[x - 1].name_of_USER);

    printf ("Password:- ");

    gets (info[x - 1].password);

    printf ("Email Address:- ");

    gets(info[x - 1].email_address);

    printf ("Number of Friends:- ");

    scanf ("%u", &info[x - 1].number_of_friends);

    printf ("Friends's ID:- ");

    for ( i = 0; i < info[x - 1].number_of_friends; i++)
    {
        scanf ("%u", &info[x - 1].friends_id[i]);
    }


    fl = fopen("userDB.txt", "w");

    fprintf (fl, "%u\n\n\n\n\n\n", x);

    for ( i = 0; i < x; i++)
    {
        fprintf (fl, "%u\n%s\n%s\n%s\n%u\n", info[i].id, info[i].name_of_USER, info[i].password, info[i].email_address, info[i].number_of_friends);

        for ( j = 0; j < info[i].number_of_friends; j++)
        {
            if (j == info[i].number_of_friends - 1)
            {
                fprintf(fl, "%u\n\n\n\n", info[i].friends_id[j]);
            }

            else
            {
                fprintf(fl, "%u ", info[i].friends_id[j]);
            }
        }

        if (j == 0)
        {
            fprintf(fl, "\n\n\n\n");
        }
        

    }

    fclose(fl);


}




int main()
{
    unsigned short n;

    printf ("1. If you want to see all profile, then press 1\n2. If you want to add a new profile, then press 2\n");

    scanf ("%hu", &n);

    printf ("\n\n");

    if (n == 1)
    {
        showInfo();
    }

    else if (n == 2)
    {
        addInfo();
    }

    return 0;
}

