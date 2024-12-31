#ifndef FUNCTION_FOR_EDZIENNIK_H 
#define FUNCTION_FOR_EDZIENNIK_H
#define MAX_NUMBER_OF_STUDENTS 40
#define MAX_LENGHT_NAMES 40
#define MAX_NUMBER_OF_GRADES 10
#define MAX_NUMBER_OF_SUBJECTS 2
#define FOR_POSITIVE_VALUES 1
#define HOW_MANY_POSTIONS_TO_SHOW 3
#define TO_SEE_LAST 1

struct Subject
{
    short how_Many_Grades;
    short Grades[MAX_NUMBER_OF_GRADES];
};

struct Student
{
    char name[MAX_LENGHT_NAMES];
    char surname[MAX_LENGHT_NAMES];
    short age;
    struct Subject biology;
    struct Subject matematics;
    short year_Of_Study;
    int id;
    float avarage_Of_Student;
};
int in_Upper_Limit(int limited_Value, int upper_Limit);
int smaller(int a,int b);
void insert_Grades(short grades[], short how_Many_Grades);
struct Student add_Student(struct Student person, int id);
void print_Student(struct Student person);
int find_Sudent(struct Student students[], int id_To_Find, int how_Many_Sudents_Are);
void rewrite_Students_List(struct Student Students[], int start, int finish);
int destroy_Student(struct Student students[], int numer_Of_Unlucky_Fellow, int current_Number_Students);
void swap(struct Student students[], int from, int to);// funkcja konfliktowa z swap w Cxx
void quick_Sort(struct Student students[], int left_Start, int right_Start);
float average(struct Student person);
void copy_Students(struct Student from[], struct Student to[], int how_Many_Students_Are_In_From);
void calculate_Avarage_And_Show_Top_3(struct Student persons[] ,struct Student top_Students[] ,int potential_New_Addtion);
void find_And_Show_Student(struct Student persons[],int search_Student_With_ID,int potential_New_Addtion);

#endif