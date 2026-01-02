#include <stdio.h>
#include <string.h>

#define MAX_BEDS 10
#define NAME_LEN 30

struct Bed {
    int id;
    int occupied;        // 0 = free, 1 = occupied
    char patient[NAME_LEN];
};

// Function declarations
void showBeds(struct Bed beds[]);
void allocateBed(struct Bed beds[]);
void freeBed(struct Bed beds[]);

int main() {
    struct Bed beds[MAX_BEDS];
    int i, choice;

    // Initialize beds
    for (i = 0; i < MAX_BEDS; i++) {
        beds[i].id = i + 1;
        beds[i].occupied = 0;
        strcpy(beds[i].patient, "None");
    }

    do {
        printf("\n=== Hospital Bed Allocation System ===\n");
        printf("1. Show bed status\n");
        printf("2. Allocate bed\n");
        printf("3. Free bed\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // consume newline left by scanf

        switch(choice) {
            case 1:
                showBeds(beds);
                break;
            case 2:
                allocateBed(beds);
                break;
            case 3:
                freeBed(beds);
                break;
            case 0:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void showBeds(struct Bed beds[]) {
    printf("\nBed Status:\n");
    for (int i = 0; i < MAX_BEDS; i++) {
        printf("Bed %d | %s | Patient: %s\n",
               beds[i].id,
               beds[i].occupied ? "Occupied" : "Free",
               beds[i].patient);
    }
}

void allocateBed(struct Bed beds[]) {
    char name[NAME_LEN];
    int allocated = 0;

    printf("Enter patient name: ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline

    for (int i = 0; i < MAX_BEDS; i++) {
        if (!beds[i].occupied) {
            beds[i].occupied = 1;
            strcpy(beds[i].patient, name);
            printf("Patient %s allocated to bed %d\n", name, beds[i].id);
            allocated = 1;
            break;
        }
    }

    if (!allocated) {
        printf("No free beds available!\n");
    }
}

void freeBed(struct Bed beds[]) {
    int id;
    printf("Enter bed number to free: ");
    scanf("%d", &id);
    getchar(); // consume newline

    if (id < 1 || id > MAX_BEDS) {
        printf("Invalid bed number!\n");
    } else if (!beds[id - 1].occupied) {
        printf("Bed is already free!\n");
    } else {
        beds[id - 1].occupied = 0;
        strcpy(beds[id - 1].patient, "None");
        printf("Bed %d is now free.\n", id);
    }
}
