#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char buffer[256];
    
    // Open the file in read mode
    file = fopen("example.txt", "r");
    
    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    // Read the file line by line until end-of-file is reached
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    // Check if we stopped reading due to an error or end-of-file
    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }
    
    // Confirm we reached end-of-file
    if (feof(file)) {
        // File read successfully to the end
    }
    
    // Close the file
    fclose(file);
    
    return 0;
}
