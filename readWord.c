#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

/*Biggest problem this program has is case sensitivity, can
count, but misses words that are different because of
case sensitivity.*/

int countWord(const char* filename, const char* word, int* count) 
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        return 1;
    }
    int finalCount = 0;
    char buffer[100];
    while ((fscanf(file, "%99s", buffer)) == 1)
    {
        if (strcmp(buffer, word) == 0)
        {
            finalCount++;
        }
    }
    fclose(file);
    return finalCount;
}

int main()
{
    char path[1000];
    char word[1000];
    int wordCount = 0;
    printf("Enter file to search: ");
    scanf("%s", path);
    printf("Enter word to search: ");
    scanf("%s", word);
    wordCount = countWord(path, word, &wordCount);
    printf("The word \"%s\" appears %d time(s) in %s\n", word, wordCount, path);
    return 0;
}
