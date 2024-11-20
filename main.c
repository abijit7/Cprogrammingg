#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "students.txt";
    char name[50];
    int marks, n;

    // Open file in append mode to add data without overwriting
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Input number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Read data for each student and write to the file
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", name);  // Read string with spaces
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks);

        // Write the student data to the file
        fprintf(file, "Name: %s, Marks: %d\n", name, marks);
    }

    printf("Data has been successfully written to '%s'.\n", filename);

    // Close the file
    fclose(file);

    return 0;
}

