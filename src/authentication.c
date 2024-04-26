//
// Created by hungt on 4/26/2024.
//

#include "flight.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool search_user_by_username(const char *filename, const char *usernameToSearch, bool printActive) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return false;
    }

    User user;
    char line[MAX_LINE_LENGTH];
    bool foundUser = false;

    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = 0;

        // Check if the line starts with the 'username' field
        if (strncmp(line, USERNAME_PREFIX, strlen(USERNAME_PREFIX)) == 0) {
            // Extract the username from the current line
            strcpy(user.username, line + strlen(USERNAME_PREFIX));

            // If the username matches, proceed to populate the rest of the fields
            if (strcmp(user.username, usernameToSearch) == 0) {
                if(printActive){
                    printf("%s\n", line); // Print username

                    // Read and print the rest of the user details
                    fgets(user.password, sizeof(user.password), file); printf("%s", user.password);
                }
                foundUser = true;
                break;
            }
        }
    }

    fclose(file);

    if(printActive){
        if (!foundUser) {
            printf("User '%s' not found.\n", usernameToSearch);
        }
    }

    return foundUser;
}

bool read_user(FILE* file, User* user) {
    char line[256];
    bool hasUsername = false, hasPassword = false;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\r\n")] = 0; // Remove newline characters

        if (strncmp(line, "username: ", 10) == 0) {
            strcpy(user->username, line + 10);
            hasUsername = true;
        } else if (strncmp(line, "password: ", 10) == 0) {
            strcpy(user->password, line + 10);
            hasPassword = true;
        }

        // Check if all necessary data is gathered to complete user reading
        if (hasUsername && hasPassword) {
            break;  // Exit once all required data is read
        }
    }

    // Return true only if all necessary fields are read
    return hasUsername && hasPassword;
}


void register_auth(const char *filename, const User* user){
    if(search_user_by_username(filename, user->username, false)){
        printf("User already exists!\n");
        return;
    }

    FILE *file = fopen(filename, "a"); // Open for appending
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "username: %s\n", user->username);
    fprintf(file, "password: %s\n", user->password);
    fclose(file);
    printf("Register successfully!\n");
}

int login(const char *fileUserPath, const char *fileTokenPath,const char *username, const char *password) {
    FILE *tokenFile = fopen(fileTokenPath, "w");
    if (!tokenFile) {
        perror("Error opening token file\n");
        return 0;
    }
    FILE *file = fopen(fileUserPath, "r");
    if (!file) {
        perror("File could not be opened for reading\n");
        fclose(tokenFile);
        return 0;
    }

    User user;
    bool found = false;

    while (read_user(file, &user)) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            printf("Login successful!\n");
            fprintf(tokenFile, "username: %s\n", user.username);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Login failed!\n");
    }

    fclose(tokenFile);
    fclose(file);
    return found ? 1 : 0;
}
