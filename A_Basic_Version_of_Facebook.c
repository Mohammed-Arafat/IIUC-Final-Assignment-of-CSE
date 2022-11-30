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

void read_Data();

void write_Data();

void write_in_console();

void showInfo();

void addInfo();

void remove_Profile();

void addFriend();

void checking_strong_password();






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




void write_in_console()
{
    unsigned int i, j;

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




void showInfo()
{

    unsigned int i, j;

    read_Data();

    write_in_console();

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


void remove_Profile()
{
    unsigned int i, j, m, k, remove_id;

    printf("Give the profile id that you want to remove:-  ");

    scanf ("%u", &m);


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

                    }
                    
                }
                
            }

        }

        
    }


    write_Data();

}




void addFriend()
{
    read_Data();

    unsigned int i, id1, id2;

    printf ("Give two profile IDs that you want to make friend:-  ");

    scanf("%u%u", &id1, &id2);

    for ( i = 0; i < x; i++)
    {
        if (info[i].id == id1)
        {
            info[i].number_of_friends++;

            info[i].friends_id[info[i].number_of_friends - 1] = id2;
        }
        else if (info[i].id == id2)
        {
            info[i].number_of_friends++;

            info[i].friends_id[info[i].number_of_friends - 1] = id1;
        }
        
    }

    write_Data();
    
}




void checking_strong_password()
{
    read_Data();

    unsigned int i, j;

    unsigned short fu = 0, fl = 0, fsc = 0, fn = 0;

    for ( i = 0; i < x; i++, fu = 0, fl = 0, fsc = 0, fn = 0)
    {
        if (strlen(info[i].password) >= 8)
        {

            for ( j = 0; j < strlen(info[i].password); j++)
            {
                if (info[i].password[j] >= 'A' && info[i].password[j] <= 'Z')
                {
                    fu = 1;
                }

                else if (info[i].password[j] >= 'a' && info[i].password [j] <= 'z')
                {
                    fl = 1;
                }

                else if (info[i].password[j] == '#' || info[i].password [j] == '$' || info[i].password [j] == '&'|| info[i].password [j] == '@'|| info[i].password [j] == '*')
                {
                    fsc = 1;
                }

                else if (info[i].password[j] >= '0' && info[i].password [j] <= '9')
                {
                    fn = 1;
                }
                
            }

            if (fu == 1 && fl == 1 && fsc == 1 && fn == 1)
            {
                printf ("%s\n%s\n", info[i].name_of_USER, info[i].password);
            }
            

        }
        
    }
    
}





int main()
{
    unsigned short n;


    printf ("1. If you want to see all profile, then press 1\n2. If you want to add a new profile, then press 2\n3. If you want to remove a profile, then press 3\n4. If you want to make friend between two profiles, then press 4\n5. If you want to check strong password of a profile, then press 5\n");

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
        remove_Profile();
    }

    else if (n == 4)
    {
        addFriend();
    }

    else if (n == 5)
    {
        checking_strong_password();
    }


    return 0;
}
