#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "function_for_edziennik.h"


int main()
{
    struct Student persons[MAX_NUMBER_OF_STUDENTS];
    struct Student top_Students[MAX_NUMBER_OF_STUDENTS];

    strcpy(persons[0].name, "Modz");
    strcpy(persons[0].surname, "mim");
    persons[0].biology.Grades[0] = 1;
    persons[0].matematics.Grades[0] = 1;
    persons[0].id = 2;
    persons[0].age = 1;
    persons[0].year_Of_Study = 1;
    persons[0].matematics.how_Many_Grades = 1;
    persons[0].biology.how_Many_Grades = 1;

    strcpy(persons[1].name, "Jessica");
    strcpy(persons[1].surname, "Wanda");
    persons[1].biology.Grades[0] = 2;
    persons[1].matematics.Grades[0] = 2;
    persons[1].id = 1;
    persons[1].age = 1;
    persons[1].year_Of_Study = 1;
    persons[1].matematics.how_Many_Grades = 1;
    persons[1].biology.how_Many_Grades = 1;

    strcpy(persons[2].name, "Kamil");
    strcpy(persons[2].surname, "Wands");
    persons[2].biology.Grades[0] = 3;
    persons[2].matematics.Grades[0] = 3;
    persons[2].id = 3;
    persons[2].age = 1;
    persons[2].year_Of_Study = 1;
    persons[2].matematics.how_Many_Grades = 1;
    persons[2].biology.how_Many_Grades = 1;

    strcpy(persons[3].name, "Kamil");
    strcpy(persons[3].surname, "Wands");
    persons[3].biology.Grades[0] = 4;
    persons[3].matematics.Grades[0] = 4;
    persons[3].id = 4;
    persons[3].age = 1;
    persons[3].year_Of_Study = 1;
    persons[3].matematics.how_Many_Grades = 1;
    persons[3].biology.how_Many_Grades = 1;

    bool active_Loop = 1;
    int id_Count = 4, potential_New_Addtion = 4;
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
        printf("5. policz srednia wszystkich studentow i pokaz 3 najlepszych\n");
        printf("6. zakoncz\n");
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
            }
            break;
        case 3:
            find_And_Show_Student( persons, search_Student_With_ID, potential_New_Addtion);
            break;
        case 4:
            printf("podaj id studenta ktory ma zostac usuniety.\n ");
            scanf("%d", &search_Student_With_ID);
            potential_New_Addtion = destroy_Student(persons, search_Student_With_ID, potential_New_Addtion);
            break;
        case 5:
            printf("obliczam srednia\n");
            calculate_Avarage_And_Show_Top_3(persons , top_Students , potential_New_Addtion);
            break;
        case 6:
            active_Loop = 0;
            break;
        default:
            printf("nie ma takiej opcji\n");
            break;
        }
    }
    return 0;
}