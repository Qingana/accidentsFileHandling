#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

struct Accident
{
    char location[MAX_LINE_LENGTH];
    int mortalityRate;
    char time[10];
    char cause[MAX_LINE_LENGTH];
    char sex[MAX_LINE_LENGTH];
    char month[15];
    int dayOfMonth;
    int financialLoss;
};

int main()
{
    // Open dataset from project directory and set read mode
    FILE *file = fopen("road_accident.txt", "r");
    if (!file)
    {
        perror("Unable to open file"); // error handle if file doesn't exist
        return 1;
    }

    // local declarations
    struct Accident accidents[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int MRATE; char Location[20];
    int i = 0;

    // skip the dataset features labels.
    fgets(line, sizeof(line), file);

    // Prompt user search input
    printf("Search by City and Mortality Rate\n");
    printf("Enter City: ");
    gets(Location);
    printf("Enter Mortality Rate < ");
    scanf("%d",&MRATE);


    // Gets string from file and store in string array (line) based on format specifier
    while (fgets(line, sizeof(line), file) && i < 100) // reads line from file untill i = 99
    {
        sscanf(line, "%[^,],%d,%[^,],%[^,],%[^,],%[^,],%d,%d",  // %[^,] is scan-set that reads a string up to when a comma(,) is used
               accidents[i].location, &accidents[i].mortalityRate,  // sscanf() reads formatted input from a string
               accidents[i].time, accidents[i].cause, accidents[i].sex,
               accidents[i].month, &accidents[i].dayOfMonth, &accidents[i].financialLoss);
        i++;
    }
    fclose(file);

    // Example: Searching causes of accidents by city and mortality rate
    printf("Accidents with mortality rate less than %d within the city of %s in South Africa:\n",MRATE,Location);
    for (int j = 0; j < i; j++)
    {
        if(strcmp(accidents[j].location,Location)==NULL)
        {
            if (accidents[j].mortalityRate < MRATE)
            {
                printf("Location: %s, Mortality Rate: %d, Time: %s, Cause: %s, Loss: %d\n",
                       accidents[j].location, accidents[j].mortalityRate, accidents[j].time,
                       accidents[j].cause, accidents[j].financialLoss);
            }
        }
    }

    return 0;
}

