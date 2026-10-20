#include <stdio.h>
#include <stdlib.h>

int main() {
    // Pointer to FILE structure
    FILE *file;

    // ==========================================
    // 1. WRITING DATA TO A TEXT FILE
    // ==========================================
    file = fopen("student_record.txt", "w");
    
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    // File mein data likhna
    fprintf(file, "Name: Rahul Sharma\n");
    fprintf(file, "Course: Advanced C Programming\n");
    fprintf(file, "Score: 95\n");

    // File ko close karna zaroori hai
    fclose(file);
    printf("Data successfully written to 'student_record.txt'.\n\n");

    // ==========================================
    // 2. READING DATA FROM THE TEXT FILE
    // ==========================================
    file = fopen("student_record.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    char buffer[150];
    printf("Reading data from file:\n");
    printf("------------------------\n");
    
    // File ke har line ko read karna jab tak end of file (EOF) na aa jaye
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // File stream close karna
    fclose(file);

    return 0;
}
