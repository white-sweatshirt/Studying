#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGHT_NAMES 40
#define MAX_NUMBER 10
struct Student
{
    char name[MAX_LENGHT_NAMES];
    char surname[MAX_LENGHT_NAMES];
    short int age;
    short int biology[MAX_NUMBER];
    short int matematics[MAX_NUMBER];
    short int year_of_study;
    int id; 
} Student;

void init_struct(struct Student person)
{
    for (int i = 0; i < MAX_NUMBER; i++)
        person.matematics[i] = 0;
    for (int i = 0; i < MAX_NUMBER; i++)
        person.biology[i] = 0;
}

void print_Student(struct Student person)
{
    
    printf("======================================\n");

    printf("wyswietlam dane studenta \nimie :%s\n", person.name);
    printf("nazwisko %s \nwiek studenta:%d \n", person.surname, person.age);
    for (int i = 0; person.matematics[i] > 0  ; i++)
        printf("ocena %d z matmeatyki :%d\n", i + 1, person.matematics[i]);
    for (int i = 0; i < person.biology[i] > 0 ; i++)
        printf("ocena %d z biologi :%d\n", i + 1, person.biology[i]);
    printf("studiuje na %d roku\n ", person.year_of_study);
    printf("Id tego studenta : %d\n", person.id);

    printf("======================================\n");
}
int in_Upper_Limit(int limited_Value, int upper_Limit)
{
    while ((limited_Value > upper_Limit )|| (limited_Value <= 0) )
    {
        printf("prosze podac warotosc ograniczona o %d :", upper_Limit);
        scanf("%d", &limited_Value);
    }
    return limited_Value;
}

struct Student add_Student(struct Student person, int id) // roboczo dodaje id takie same jak ma numer w dzeinniku
{
    int mat = 0, biol = 0;
    printf("podaj imie studenta :"); // jedna funkcja do imienia nazwiska i wieku i roku
    scanf("%s", &person.name);
    printf("podaj nazwisko studenta: ");
    scanf("%s", &person.surname);
    printf("podaj wiek studenta:");
    scanf("%d", &person.age);
    printf("podaj ilosc ocen (max 10) z matmy dla studenta\n"); // po jednej funkcja dla tych tablic
    mat=in_Upper_Limit(mat,MAX_NUMBER);
    for (int i = 0; i < mat; i++)
    {
        printf("podaj ocene (>0) z matmatyki dla studenta :");
        scanf("%d", &person.matematics[i]);
        if (person.matematics[i] < 1 || person.matematics[i] > 6)
        {
            printf("podano nie prawidlowa ocene pamietaj ze oceny sa w zakresie 1-6 \n");
            i--;
        }
    }
    printf("podaj ilosc (max 10) ocen z biologi dla studenta\n");
    biol = in_Upper_Limit(biol, MAX_NUMBER);

    for (int i = 0; i < biol; i++)
    {
        printf("podaj ocene z bilogi dla studenta :");
        scanf("%d", &person.biology[i]);
        if (person.biology[i] < 1 || person.biology[i] > 6)
        {
            printf("podano nie prawidlowa ocene pamietaj ze oceny sa w zakresie 1-6 \n");
            i--;
        }
    }
    printf("podaj rok na ktorym studiuje: ");
    scanf("%d", &person.year_of_study);
    person.id = id;
    return person;
}
void destroy_Student()
{
    /*WiP*/
}
int main()
{
    struct Student persons[MAX_LENGHT_NAMES];
    init_struct(persons[0]);
    bool t = 1;
    int potential_New_Addtion = 0;
    int show_Student = 0;
    while (t == 1)
    {

        int choice = 0;
        printf("MENU \n");
        printf("1. dodaj ucznia\n");
        printf("2. lista uczniuw\n");
        printf("3. wyswietl jednego studenta \n");
        printf("4. zakoncz\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            persons[potential_New_Addtion]=add_Student(persons[potential_New_Addtion], potential_New_Addtion);
            ++potential_New_Addtion;
            break;
        case 2:
            printf("wypisuje wszystkich uczniow\n");
            for (int i = 0; i < potential_New_Addtion; i++)
            {
                print_Student(persons[i]);
                printf("wypisuje studenta o numerze :%d\n");
            }

            break;
        case 3:
            printf("jakiego studenta (indeksy w liczbach naturalnych >0) ci pokazac  :%d");
            scanf("%d", &show_Student);
            print_Student(persons[show_Student-1]);
            break;
        default:
            t = 0;
            break;
        }
    }
    return 0;
}
