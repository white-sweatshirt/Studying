#include <stdio.h>
#include "function_for_edziennik.h"


int in_Upper_Limit(int limited_Value, int upper_Limit)
{
    while ((limited_Value > upper_Limit) || (limited_Value <= 0))
    {
        printf("prosze podac warotosc ograniczona o %d :", upper_Limit);
        scanf("%d", &limited_Value);
    }
    return limited_Value;
}
int smaller(int a,int b)
{
    if(a>b)
        return b;
    return a;
}
void print_Student(struct Student person){
    printf("======================================\n");
    printf("wyswietlam dane studenta \nimie :%s\n", person.name);
    printf("nazwisko %s \nwiek studenta:%d \n", person.surname, person.age);
    for (int i = 0; i < person.matematics.how_Many_Grades; i++)
        printf("ocena %d z matmeatyki :%d\n", i + 1, person.matematics.Grades[i]);
    for (int i = 0; i < person.biology.how_Many_Grades; i++)
        printf("ocena %d z biologi :%d\n", i + 1, person.biology.Grades[i]);
    printf("studiuje na %d roku\n", person.year_Of_Study);
    printf("Id tego studenta : %d\n", person.id);
    printf("ma srednia :%f \n", person.avarage_Of_Student);
    printf("======================================\n");
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

struct Student add_Student(struct Student person, int id)
{
    printf("podaj imie studenta :");
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
    scanf("%d", &person.year_Of_Study);
    person.id = id;
    return person;
}

int find_Sudent(struct Student students[], int id_To_Find, int how_Many_Sudents_Are)
{
    int i = 0;
    for (i; i < how_Many_Sudents_Are; i++)
        if (students[i].id == id_To_Find)
            break;
    if (i < how_Many_Sudents_Are)
        return i;
    else
        return -1;
}

void rewrite_Students_List(struct Student Students[], int start, int finish)
{
    for (int i = start; i < finish - 1; i++)
        Students[i] = Students[i + 1];
}

int destroy_Student(struct Student students[], int numer_Of_Unlucky_Fellow, int current_Number_Students)
{
    int to_be_killed = 0;
    to_be_killed = find_Sudent(students, numer_Of_Unlucky_Fellow, current_Number_Students);
    if (to_be_killed >= 0 && to_be_killed <= current_Number_Students - TO_SEE_LAST)
    {
        // z ostanim zachowuje sie jak by to byla wolna przestrzenia
        // tu jest de facto destrucja
        rewrite_Students_List(students, to_be_killed, current_Number_Students); 
        return current_Number_Students - 1;                                     
    }   
    else
    {
        printf("Nie ma takiego studenta o takim id na liscie!\n");
        return current_Number_Students;
    }
}

void swap(struct Student students[], int from, int to)
{
    struct Student temp;
    temp = students[from];
    students[from] = students[to];
    students[to] = temp;
}

void quick_Sort(struct Student students[], int left_Start, int right_Start)
{
    int pivot = (left_Start + right_Start - (left_Start + right_Start) % 2) / 2;
    float value_Pivot = students[pivot].avarage_Of_Student;
    if (left_Start >= right_Start)
        return;
    int left = left_Start, right = right_Start;
    
    while (left <= right)
    {
        while (students[left].avarage_Of_Student > value_Pivot && left < right)
            ++left;
        while (students[right].avarage_Of_Student <= value_Pivot)
            --right;
        if (left >= right)
            break;
        else
        {
            swap(students, left, right);
            if (pivot == left)
                pivot = right;
            if (pivot == right)
                pivot = left;
        }
    }
    if (students[pivot].avarage_Of_Student >= students[left].avarage_Of_Student && pivot > left)
        swap(students, pivot, left);

    if (students[pivot].avarage_Of_Student < students[left].avarage_Of_Student && pivot < left)
        swap(students, pivot, left);

    if (left - 1 < right_Start)
        quick_Sort(students, left_Start, left - 1);
    if (left > left_Start)
        quick_Sort(students, left, right_Start);
}

float average(struct Student person)
{
    float current_avrage = 0;
    float for_Conversion = 0;
    for (int i = 0; i < person.matematics.how_Many_Grades; i++)
    {
        for_Conversion = (float)person.matematics.Grades[i];
        current_avrage = current_avrage + for_Conversion;
    }
    for (int i = 0; i < person.biology.how_Many_Grades; i++)
    {
        for_Conversion = (float)person.biology.Grades[i];
        current_avrage = current_avrage + for_Conversion;
    }
    float math = (float)person.matematics.how_Many_Grades;
    float biology = (float)person.biology.how_Many_Grades;
    float how_Many_Grades = math + biology;
    return current_avrage / how_Many_Grades;
}

void copy_Students(struct Student from[], struct Student to[], int how_Many_Students_Are_In_From)
{
    for (int i = 0; i < how_Many_Students_Are_In_From; i++)
        to[i] = from[i];
}
void calculate_Avarage_And_Show_Top_3(struct Student persons[] ,struct Student top_Students[] ,int potential_New_Addtion)
{
    for (int i = 0; i < potential_New_Addtion; i++)
                persons[i].avarage_Of_Student = average(persons[i]);

            copy_Students(persons, top_Students, potential_New_Addtion);

            quick_Sort(top_Students, 0, potential_New_Addtion - 1);
            for (int i = 0; i < smaller(HOW_MANY_POSTIONS_TO_SHOW,potential_New_Addtion); i++)
                print_Student(top_Students[i]);
            
}
void find_And_Show_Student(struct Student persons[],int search_Student_With_ID,int potential_New_Addtion)
{
    int show_student=0;
            printf("podaj id (id>0 i id zawiera sie w naturalnych) studenta ktorego ci pokazac :");
            scanf("%d", &search_Student_With_ID);
            show_student = find_Sudent(persons, search_Student_With_ID, potential_New_Addtion);
            if (show_student >= 0)
                print_Student(persons[show_student]);
            else
                printf("brak takiego studenta\n");

}