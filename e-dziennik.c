#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBER_OF_STUDENTS 40
#define MAX_LENGHT_NAMES 40
#define MAX_NUMBER_OF_GRADES 10
#define MAX_NUMBER_OF_SUBJECTS 2
struct Subject
{
    // char name_Of_Subject[MAX_LENGHT_NAMES];
    short how_Many_Grades;
    short Grades[MAX_NUMBER_OF_GRADES];
} Subject;

struct Student
{
    char name[MAX_LENGHT_NAMES];
    char surname[MAX_LENGHT_NAMES];
    short age;
    struct Subject biology;
    struct Subject matematics;
    short year_of_study;
    int id;
} Student;

/*void init_struct(struct Student person) //moze sie kiedys przyda
{
    for (int i = 0; i < MAX_NUMBER_OF_GRADES; i++)
        person.matematics.Grades[i] = 0;
    for (int i = 0; i < MAX_NUMBER_OF_GRADES; i++)
        person.biology.Grades[i] = 0;
}*/

void print_Student(struct Student person)
{

    printf("======================================\n");

    printf("wyswietlam dane studenta \nimie :%s\n", person.name);
    printf("nazwisko %s \nwiek studenta:%d \n", person.surname, person.age);
    for (int i = 0; i < person.matematics.how_Many_Grades; i++)
        printf("ocena %d z matmeatyki :%d\n", i + 1, person.matematics.Grades[i]);
    for (int i = 0; i < person.biology.how_Many_Grades; i++)
        printf("ocena %d z biologi :%d\n", i + 1, person.biology.Grades[i]);
    printf("studiuje na %d roku\n", person.year_of_study);
    printf("Id tego studenta : %d\n", person.id);

    printf("======================================\n");
}
int in_Upper_Limit(int limited_Value, int upper_Limit)
{
    while ((limited_Value > upper_Limit) || (limited_Value <= 0))
    {
        printf("prosze podac warotosc ograniczona o %d :", upper_Limit);
        scanf("%d", &limited_Value);
    }
    return limited_Value;
}
void insert_Grades(short grades[], short how_Many_Grades)
{
    for (short i = 0; i < how_Many_Grades; i++)
    {
        printf("podaj ocene (>0)  dla studenta :");
        scanf("%d", &grades[i]);
        if (grades[i] < 1 || grades[i] > 6)
        {
            printf("podano nie prawidlowa ocene pamietaj ze oceny sa w zakresie 1-6 \n");
            i--;
        }
    }
}

struct Student add_Student(struct Student person, int id) // roboczo dodaje id takie same jak ma numer w dzeinniku
{
    printf("podaj imie studenta :"); // jedna funkcja do imienia nazwiska i wieku i roku
    scanf("%s", &person.name);
    printf("podaj nazwisko studenta: ");
    scanf("%s", &person.surname);
    printf("podaj wiek studenta:");
    scanf("%d", &person.age);

    printf("podaj ilosc ocen (max 10) z matmy dla studenta\n");
    person.matematics.how_Many_Grades = in_Upper_Limit(person.matematics.how_Many_Grades, MAX_NUMBER_OF_GRADES);
    printf("podaj kolejne oceny z matematki\n");
    insert_Grades(person.matematics.Grades, person.matematics.how_Many_Grades);

    printf("podaj ilosc (max 10) ocen z biologi dla studenta\n");
    person.biology.how_Many_Grades = in_Upper_Limit(person.biology.how_Many_Grades, MAX_NUMBER_OF_GRADES);
    printf("podaj kolejne oceny z biologis\n");
    insert_Grades(person.biology.Grades, person.biology.how_Many_Grades);

    printf("podaj rok na ktorym studiuje: ");
    scanf("%d", &person.year_of_study);
    person.id = id;
    return person;
}
int find_Sudent(struct Student students[], int id_to_find, int how_Many_Sudents_Are)
{
    int i = 0;
    for (i; i < how_Many_Sudents_Are; i++)
        if (students[i].id == id_to_find)
            break;
    if (i < how_Many_Sudents_Are)
        return i;
    else
        return -1;
}
#define TO_SEE_LAST 1
void rewrite_Students_List(struct Student Students[], int start, int finish)
{
    for (int i = start; i < finish - 1; i++)
        Students[i] = Students[i + 1];
}

int destroy_Student(struct Student Students[], int numer_Of_Unlucky_Fellow, int current_Number_Students)
{
    int to_be_killed = 0;
    to_be_killed = find_Sudent(Students, numer_Of_Unlucky_Fellow, current_Number_Students);
    if (to_be_killed >= 0 && to_be_killed <= current_Number_Students - TO_SEE_LAST)
    {
        rewrite_Students_List(Students, to_be_killed, current_Number_Students); // tu jest de facto destrucja
        return current_Number_Students - 1;                                     // z ostanim zachowuje sie jak by byl wolna przestrzenia
    }
    else
    {
        printf("Nie ma takiego studenta o takim id na liscie!\n");
        return current_Number_Students;
    }
}
#define FOR_POSITIVE_VALUES 1
int main()
{
    struct Student persons[MAX_NUMBER_OF_STUDENTS];
    bool active_Loop = 1;
    int id_Count = 0, potential_New_Addtion = 0;
    int search_Student_With_ID = 0;
    int show_student = 0;
    while (active_Loop == 1)
    {
        int choice = 0;
        printf("MENU \n");
        printf("1. dodaj ucznia\n");
        printf("2. lista uczniuw\n");
        printf("3. wyswietl jednego studenta \n");
        printf("4. usun Studenta\n");
        printf("5. zakoncz\n");
        printf("twoj wybor---->");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            persons[id_Count] = add_Student(persons[id_Count], potential_New_Addtion + 1);
            ++potential_New_Addtion;
            ++id_Count; // gwarancja unikalnego id
            break;
        case 2:
            printf("wypisuje wszystkich uczniow\n");
            for (int i = 0; i < potential_New_Addtion; ++i)
            {
                print_Student(persons[i]);
                printf("wypisuje studenta o numerze :%d\n");
            }
            break;
        case 3:
            printf("jakiego studenta (indeksy w liczbach naturalnych >0) ci pokazac :");
            scanf("%d", &search_Student_With_ID);
            show_student = find_Sudent(persons, search_Student_With_ID, potential_New_Addtion);
            if (show_student >= 0)
                print_Student(persons[show_student]);
            else
                printf("brak takiego studenta\n");
            break;
        case 4:
            printf("podaj id studenta ktory ma zostac usuniety.\n ");
            scanf("%d", &search_Student_With_ID);
            potential_New_Addtion = destroy_Student(persons, search_Student_With_ID, potential_New_Addtion);
            printf("potential new addtion: %d\n", potential_New_Addtion);
            break;
        case 5:
            active_Loop = 0;
            break;
        default:
            printf("nie ma takiej opcji\n");
            break;
        }
    }
    return 0;
}