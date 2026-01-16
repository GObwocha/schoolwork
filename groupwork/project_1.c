//SCS3/2595/2025
//SCS3/150532/2025
//SCS3/2478/2025
//SCS3/2596/2025

//Link to the GitHub account where the project is:
//https://github.com/GObwocha/schoolwork

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadTasksFromFile();
void saveTasksToFile();
void addTask();
void viewTasks();
void markTaskCompleted();
void clearInputBuffer();

int main() {
  int choice;
  loadTasksFromFile();

  while (1) {
    printf("\n--- To-Do List Menu ---\n");
    printf("1. Add New Task\n");
    printf("2. View All Tasks\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Save Tasks to File\n");
    printf("5. Reload Tasks from File\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
      printf("Invalid input. Please enter a number.\n");
      clearInputBuffer();
      continue;
    }
    clearInputBuffer(); 

    switch (choice) {
    case 1:
      addTask();
      break;
    case 2:
      viewTasks();
      break;
    case 3:
      markTaskCompleted();
      break;
    case 4:
      saveTasksToFile();
      break;
    case 5:
      loadTasksFromFile();
      printf("Tasks reloaded from file.\n");
      break;
    case 6:
      printf("Exiting... Include saving? (y/n): ");
      char saveChoice;
      scanf("%c", &saveChoice);
      if (saveChoice == 'y' || saveChoice == 'Y') {
        saveTasksToFile();
      }
      printf("Goodbye!\n");
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }
  return 0;
}
