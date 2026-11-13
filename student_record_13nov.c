#include <stdio.h>

// स्ट्रक्चर डिफाइन करना ताकि छात्र का रिकॉर्ड मैनेज हो सके
struct Student {
    char name[50];
    int rollNo;
    float marks;
};

int main() {
    struct Student s1;

    printf("--- Student Record System ---\n");
    
    // इनपुट लेना
    printf("Enter student name: ");
    scanf("%s", s1.name);
    
    printf("Enter Roll Number: ");
    scanf("%d", &s1.rollNo);
    
    printf("Enter Physics Marks: ");
    scanf("%f", &s1.marks);

    // आउटपुट दिखाना
    ("\n--- Displaying Student Details ---\n");
    printf("Name: %s\n", s1.name);
    printf("Roll Number: %d\n", s1.rollNo);
    printf("Physics Marks: %.2f\n", s1.marks);

    return 0;
}
