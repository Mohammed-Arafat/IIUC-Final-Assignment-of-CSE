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


void read_Data()
{
    unsigned int i, j;

    FILE *fl;

    fl = fopen ("userDB.txt", "r");

    fscanf (fl, "%u", &x);

    for (i = 0; i < x; i++)
    {
        fscanf (fl, "%u\n", &info[i].id);

        fscanf(fl, "%[^\n]\n", info[i].name_of_USER);

        fscanf(fl, "%[^\n]\n", info[i].password);

        fscanf(fl, "%[^\n]\n", info[i].email_address);

        fscanf (fl, "%u", &info[i].number_of_friends);

        for ( j = 0; j < info[i].number_of_friends; j++)
        {
            fscanf (fl, "%u", &info[i].friends_id[j]);
        }
    }

    fclose(fl);
}


void write_Data()
{
    unsigned int i, j;

    FILE *fl;

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





void showInfo()
{

    unsigned int i, j;

    read_Data();

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

    read_Data();

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


    write_Data();

}


void remove_Profile(unsigned int m)
{
    unsigned int i, j, k, remove_id;

    read_Data();

    for ( i = 0; i < x; i++)
    {
        if (info[i].id == m)
        {

            remove_id = info[i].id; 

            for ( j = i; j < x - 1; j++)
            {
                info[j] = info [j + 1];
            }

            x--;

            for ( i = 0; i < x; i++)
            {
                for ( j = 0; j < info[i].number_of_friends; j++)
                {
                    if (info[i].friends_id[j] == remove_id)
                    {
                        for ( k = j; k < info[i].number_of_friends - 1; k++)
                        {
                            info[i].friends_id[j] = info[i].friends_id[j + 1];
                        }

                        info[i].number_of_friends--;

                        //goto RRR;
                        
                    }
                    
                }
                
            }

        }

        
    }

    RRR:;

    write_Data();

}



int main()
{
    unsigned short n;

    unsigned int m;

    printf ("1. If you want to see all profile, then press 1\n2. If you want to add a new profile, then press 2\n3. If you want to remove a profile, then press 3\n");

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

    else if (n == 3)
    {
        printf("Give the profile id that you want to remove:-  ");

        scanf ("%u", &m);

        remove_Profile(m);
    }
    

    return 0;
}
