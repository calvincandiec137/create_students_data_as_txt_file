#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STUDENTS 60
#define p 60
#define c 60
#define m 60
#define ed 60
#define e 60

void enter_grades(int grades[MAX_STUDENTS], int PHYSCIS[p], int CHEMISTRY[c], int MATHS[m], int ENGINEERING_DRAWING[ed], int ENGLISH[e], char NAME[MAX_STUDENTS][100], int stud);
void get_grades(int grades[MAX_STUDENTS], int PHYSCIS[p], int CHEMISTRY[c], int MATHS[m], int ENGINEERING_DRAWING[ed], int ENGLISH[e], char NAME[MAX_STUDENTS][100], int stud);

int main(void) {
    char ch, s[100];

    

    int stud;
    int grades[MAX_STUDENTS] = {0};
    int PHYSCIS[p] = {0};
    int CHEMISTRY[c] = {0};
    int MATHS[m] = {0};
    int ENGINEERING_DRAWING[ed] = {0};
    int ENGLISH[e] = {0};
    char NAME[MAX_STUDENTS][100]; 
    for (;;) {
        do {
            printf("(E)nter the grades\n");
            printf("(R)eport the grades\n");
            printf("(Q)uit\n");
            fgets(s, sizeof(s), stdin);
            ch = toupper(*s);
        } while (ch != 'E' && ch != 'R' && ch != 'Q');

        switch (ch) {
            case 'E':
                enter_grades(grades, PHYSCIS, CHEMISTRY, MATHS, ENGINEERING_DRAWING, ENGLISH, NAME, stud);
                break;

            case 'R':
                printf("Enter the student's Roll No:");
                scanf("%d", &stud);
                get_grades(grades, PHYSCIS, CHEMISTRY, MATHS, ENGINEERING_DRAWING, ENGLISH, NAME, stud);
                break;

            case 'Q':
                exit(0);
                break;
        }
    }

    return 0;
}

void enter_grades(int grades[MAX_STUDENTS], int PHYSCIS[p], int CHEMISTRY[c], int MATHS[m], int ENGINEERING_DRAWING[ed], int ENGLISH[e], char NAME[MAX_STUDENTS][100], int stud) {
    int P, C, M, ED, E;

    FILE *fptr;

    fptr=fopen("report.txt","a+");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }


    printf("Enter the student's Roll No:");
    scanf("%d", &stud);
    fprintf(fptr,"Enter the student's Roll No: %d\n",stud);

    
    printf("Enter the student's name:");
    scanf("%s", NAME[stud]);
    fprintf(fptr,"Enter the student's name: %s\n",NAME[stud]);


    printf("Enter PHYSICS marks:");
    scanf("%d", &P);
    fprintf(fptr,"Enter PHYSICS marks: %d\n",P);

    printf("Enter CHEMISTRY marks:");
    scanf("%d", &C);
    fprintf(fptr,"Enter CHEMISTRY marks: %d\n",C);

    printf("Enter MATHS marks:");
    scanf("%d", &M);
    fprintf(fptr,"Enter MATHS marks: %d\n",M);

    printf("Enter ENGINEERING DRAWING marks:");
    scanf("%d", &ED);
    fprintf(fptr,"Enter ENGINEERING DRAWING marks: %d\n",ED);

    printf("Enter ENGLISH marks:");
    scanf("%d", &E);
    fprintf(fptr,"Enter ENGLISH marks: %d\n\n\n\n",E);

    if (stud >= 0 && stud < MAX_STUDENTS) {
        PHYSCIS[stud] = P;
        CHEMISTRY[stud] = C;
        MATHS[stud] = M;
        ENGINEERING_DRAWING[stud] = ED;
        ENGLISH[stud] = E;
    } else {
        printf("Invalid class or student index\n");
    }
    fflush(fptr);
    fclose(fptr);
}

void get_grades(int grades[MAX_STUDENTS], int PHYSCIS[p], int CHEMISTRY[c], int MATHS[m], int ENGINEERING_DRAWING[ed], int ENGLISH[e], char NAME[MAX_STUDENTS][100], int stud) {
    if (stud >= 0 && stud < MAX_STUDENTS) {
        printf("NAME: %s\n", NAME[stud]);
        printf("ROLL NO: %d\n", stud);
        printf("Physics: %d\n", PHYSCIS[stud]);
        printf("Chemistry: %d\n", CHEMISTRY[stud]);
        printf("Maths: %d\n", MATHS[stud]);
        printf("Engineering Drawing: %d\n", ENGINEERING_DRAWING[stud]);
        printf("English: %d\n", ENGLISH[stud]);
    } else {
        printf("Invalid class or student index\n");
    }
}
