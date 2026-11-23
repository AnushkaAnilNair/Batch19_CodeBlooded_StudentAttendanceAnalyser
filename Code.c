#include <stdio.h>

#define SUBJECTS 5
#define MIN_ATTENDANCE 75.0

char subjects[SUBJECTS][60] = {
    "Advanced Engineering Mathematics",
    "Physics for Computer Science",
    "Problem Solving",
    "Programming in C",
    "Environment, Sustainability and Climate Change"
};

int total[SUBJECTS] = {0};
int attended[SUBJECTS] = {0};

/* Function to calculate attendance percentage */
float calculateAttendance(int present, int conducted)
{
    return ((float)present / conducted) * 100;
}

/* Function to enter attendance details */
void enterAttendance()
{
    int i;

    printf("\n========== ENTER ATTENDANCE ==========\n");

    for(i = 0; i < SUBJECTS; i++)
    {
        printf("\n%s\n", subjects[i]);

        printf("Enter total classes conducted: ");
        scanf("%d", &total[i]);

        printf("Enter classes attended: ");
        scanf("%d", &attended[i]);

        while(total[i] <= 0 || attended[i] < 0 ||
              attended[i] > total[i])
        {
            printf("\nInvalid input! Enter again.\n");

            printf("Total classes conducted: ");
            scanf("%d", &total[i]);

            printf("Classes attended: ");
            scanf("%d", &attended[i]);
        }
    }

    printf("\nAttendance details saved successfully!\n");
}

/* Function to display current attendance */
void displayAttendance()
{
    int i;
    float percentage;

    printf("\n========== CURRENT ATTENDANCE ==========\n");

    for(i = 0; i < SUBJECTS; i++)
    {
        if(total[i] == 0)
        {
            printf("\nPlease enter attendance details first.\n");
            return;
        }

        percentage = calculateAttendance(attended[i], total[i]);

        printf("\n%s\n", subjects[i]);
        printf("Classes Conducted : %d\n", total[i]);
        printf("Classes Attended  : %d\n", attended[i]);
        printf("Attendance        : %.2f%%\n", percentage);

        if(percentage >= MIN_ATTENDANCE)
            printf("Status            : ELIGIBLE\n");
        else
            printf("Status            : DEBARRED\n");
    }
}

/* Function for next class analysis */
void nextClassAnalysis()
{
    int i;
    float current, newAttend, newMiss;
    float increase, decrease;

    printf("\n========== NEXT CLASS ANALYSIS ==========\n");

    for(i = 0; i < SUBJECTS; i++)
    {
        if(total[i] == 0)
        {
            printf("\nPlease enter attendance details first.\n");
            return;
        }

        current = calculateAttendance(attended[i], total[i]);

        newAttend =
            calculateAttendance(attended[i] + 1, total[i] + 1);

        newMiss =
            calculateAttendance(attended[i], total[i] + 1);

        increase = newAttend - current;
        decrease = current - newMiss;

        printf("\n----------------------------------------\n");
        printf("%s\n", subjects[i]);

        printf("Current Attendance : %.2f%%\n", current);

        printf("\nIf Next Class is ATTENDED:\n");
        printf("New Attendance     : %.2f%%\n", newAttend);
        printf("Rate of Change     : +%.2f%%\n", increase);

        printf("\nIf Next Class is MISSED:\n");
        printf("New Attendance     : %.2f%%\n", newMiss);
        printf("Rate of Change     : -%.2f%%\n", decrease);
    }
}

/* Function to calculate how many classes can be missed */
void classesCanMiss()
{
    int i, miss;
    float current, afterMiss;

    printf("\n========== CLASSES YOU CAN MISS ==========\n");

    for(i = 0; i < SUBJECTS; i++)
    {
        if(total[i] == 0)
        {
            printf("\nPlease enter attendance details first.\n");
            return;
        }

        current = calculateAttendance(attended[i], total[i]);

        printf("\n%s\n", subjects[i]);
        printf("Current Attendance : %.2f%%\n", current);

        if(current < MIN_ATTENDANCE)
        {
            printf("Status              : DEBARRED\n");
            printf("Classes You Can Miss: 0\n");
        }
        else
        {
            miss = 0;

            while(1)
            {
                afterMiss =
                    calculateAttendance(attended[i],
                                        total[i] + miss + 1);

                if(afterMiss >= MIN_ATTENDANCE)
                    miss++;
                else
                    break;
            }

            printf("Status              : ELIGIBLE\n");
            printf("Classes You Can Miss: %d\n", miss);

            if(miss > 0)
                printf("Taking Next Class Off: SAFE\n");
            else
                printf("Taking Next Class Off: NOT SAFE\n");
        }
    }
}

/* Function to display debarred subjects */
void displayDebarred()
{
    int i, count = 0;
    float percentage;

    printf("\n========== DEBARRED SUBJECTS ==========\n");

    for(i = 0; i < SUBJECTS; i++)
    {
        if(total[i] == 0)
        {
            printf("\nPlease enter attendance details first.\n");
            return;
        }

        percentage = calculateAttendance(attended[i], total[i]);

        if(percentage < MIN_ATTENDANCE)
        {
            printf("\n%s : %.2f%% - DEBARRED\n",
                   subjects[i], percentage);

            count++;
        }
    }

    if(count == 0)
        printf("\nYou are not debarred in any subject.\n");
    else
        printf("\nTotal Debarred Subjects: %d\n", count);
}

/* Function to display overall attendance */
void overallAttendance()
{
    int i;
    int totalClasses = 0;
    int totalPresent = 0;
    float percentage;

    if(total[0] == 0)
    {
        printf("\nPlease enter attendance details first.\n");
        return;
    }

    for(i = 0; i < SUBJECTS; i++)
    {
        totalClasses += total[i];
        totalPresent += attended[i];
    }

    percentage =
        calculateAttendance(totalPresent, totalClasses);

    printf("\n========== OVERALL ATTENDANCE ==========\n");

    printf("Total Classes Conducted : %d\n", totalClasses);
    printf("Total Classes Attended  : %d\n", totalPresent);
    printf("Overall Attendance      : %.2f%%\n", percentage);
}

/* Main function */
int main()
{
    int choice;

    do
    {
        printf("\n\n========================================\n");
        printf("       STUDENT ATTENDANCE ANALYSER\n");
        printf("========================================\n");

        printf("1. Enter Attendance Details\n");
        printf("2. View Current Attendance\n");
        printf("3. Next Class Impact Analysis\n");
        printf("4. Check How Many Classes Can Be Missed\n");
        printf("5. View Debarred Subjects\n");
        printf("6. View Overall Attendance\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enterAttendance();
                break;

            case 2:
                displayAttendance();
                break;

            case 3:
                nextClassAnalysis();
                break;

            case 4:
                classesCanMiss();
                break;

            case 5:
                displayDebarred();
                break;

            case 6:
                overallAttendance();
                break;

            case 7:
                printf("\nThank you for using Student Attendance Analyser!\n");
                break;

            default:
                printf("\nInvalid choice! Please enter 1 to 7.\n");
        }

    } while(choice != 7);

    return 0;
}
