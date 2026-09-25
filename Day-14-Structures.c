/* =========================================================
   Q1: q01_basic_structure.c
   Declare and access a structure
   ========================================================= */

#include <stdio.h>

struct Student
{
    int roll_no;
    float marks;
};

int main(void)
{
    struct Student s1;

    s1.roll_no = 101;
    s1.marks = 85.5f;

    printf("Roll No = %d\n", s1.roll_no);
    printf("Marks   = %.2f\n", s1.marks);

    return 0;
}


/* =========================================================
   Q2: q02_structure_input_output.c
   Read and display structure data
   ========================================================= */

#include <stdio.h>

struct Student
{
    int roll_no;
    char name[50];
    float marks;
};

int main(void)
{
    struct Student s;

    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);

    printf("Enter name: ");
    scanf("%49s", s.name);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    printf("\nStudent Details\n");
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);

    return 0;
}


/* =========================================================
   Q3: q03_array_of_structures.c
   Array of structures
   ========================================================= */

#include <stdio.h>

struct Student
{
    int roll_no;
    float marks;
};

int main(void)
{
    struct Student students[3] =
    {
        {101, 85.5f},
        {102, 90.0f},
        {103, 78.5f}
    };

    for (int i = 0; i < 3; i++)
    {
        printf("Roll No = %d, Marks = %.2f\n",
               students[i].roll_no,
               students[i].marks);
    }

    return 0;
}


/* =========================================================
   Q4: q04_nested_structure.c
   Structure inside another structure
   ========================================================= */

#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Student
{
    int roll_no;
    struct Date birth_date;
};

int main(void)
{
    struct Student s =
    {
        101,
        {15, 8, 2005}
    };

    printf("Roll No = %d\n", s.roll_no);

    printf("Birth Date = %02d/%02d/%d\n",
           s.birth_date.day,
           s.birth_date.month,
           s.birth_date.year);

    return 0;
}


/* =========================================================
   Q5: q05_structure_pointer.c
   Access structure members using a pointer
   ========================================================= */

#include <stdio.h>

struct Employee
{
    int id;
    float salary;
};

int main(void)
{
    struct Employee emp = {101, 50000.0f};

    struct Employee *ptr = &emp;

    printf("ID = %d\n", (*ptr).id);
    printf("Salary = %.2f\n", (*ptr).salary);

    return 0;
}


/* =========================================================
   Q6: q06_structure_arrow_operator.c
   Use -> operator
   ========================================================= */

#include <stdio.h>

struct Device
{
    int id;
    int status;
};

int main(void)
{
    struct Device device = {10, 1};

    struct Device *ptr = &device;

    printf("Device ID = %d\n", ptr->id);
    printf("Status = %d\n", ptr->status);

    return 0;
}


/* =========================================================
   Q7: q07_structure_function.c
   Pass structure to a function
   ========================================================= */

#include <stdio.h>

struct Student
{
    int roll_no;
    float marks;
};

void display(struct Student s)
{
    printf("Roll No = %d\n", s.roll_no);
    printf("Marks = %.2f\n", s.marks);
}

int main(void)
{
    struct Student s = {101, 88.5f};

    display(s);

    return 0;
}


/* =========================================================
   Q8: q08_return_structure.c
   Return structure from a function
   ========================================================= */

#include <stdio.h>

struct Point
{
    int x;
    int y;
};

struct Point create_point(int x, int y)
{
    struct Point p;

    p.x = x;
    p.y = y;

    return p;
}

int main(void)
{
    struct Point p = create_point(10, 20);

    printf("X = %d\n", p.x);
    printf("Y = %d\n", p.y);

    return 0;
}


/* =========================================================
   Q9: q09_modify_structure_pointer.c
   Modify structure using pointer
   ========================================================= */

#include <stdio.h>

struct Employee
{
    int id;
    float salary;
};

void update_salary(struct Employee *emp)
{
    emp->salary += 5000.0f;
}

int main(void)
{
    struct Employee emp = {101, 40000.0f};

    printf("Before = %.2f\n", emp.salary);

    update_salary(&emp);

    printf("After  = %.2f\n", emp.salary);

    return 0;
}


/* =========================================================
   Q10: q10_sensor_data_structure.c
   Embedded-style sensor data structure
   ========================================================= */

#include <stdio.h>

struct SensorData
{
    float temperature;
    float humidity;
    int sensor_status;
};

void display_sensor_data(struct SensorData *data)
{
    printf("Temperature = %.2f C\n", data->temperature);
    printf("Humidity    = %.2f %%\n", data->humidity);
    printf("Status      = %d\n", data->sensor_status);
}

int main(void)
{
    struct SensorData sensor =
    {
        28.5f,
        65.0f,
        1
    };

    display_sensor_data(&sensor);

    return 0;
}
