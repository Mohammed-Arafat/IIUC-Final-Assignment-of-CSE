#include <stdio.h>
#include <string.h>

struct User
{
    unsigned int id, number_of_friends, friends_id[50];

    char name_of_USER[23], password[50], email_address[37];

};

typedef struct User SU;

SU info[200];

void showInfo(unsigned int x)
{

    unsigned int i, j;

    FILE *fl;

    fl = fopen ("userDB.txt", "r");

    for (i = 0; i < x; i++)
    {
        fscanf (fl, "%u\n", &info[i].id);

        fgets (info[i].name_of_USER, sizeof (info[i].name_of_USER), fl);

        fgets (info[i].password, sizeof (info[i].password), fl);

        fgets (info[i].email_address, sizeof (info[i].email_address), fl);

        fscanf (fl, "\n%u", &info[i].number_of_friends);

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

        printf ("\n");
    }

}

int main()
{
    unsigned int n;

    scanf ("%u", &n);

    showInfo(n);

    return 0;
}

