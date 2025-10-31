#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int n, i, j, head, total = 0, min, index;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int request[n];
    bool visited[n];
    printf("Enter the disk request sequence: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
        visited[i] = false;
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("\nSSTF Disk Scheduling Order:\n");

    for (i = 0; i < n; i++)
    {
        min = 9999;
        index = -1;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && abs(head - request[j]) < min)
            {
                min = abs(head - request[j]);
                index = j;
            }
        }
        visited[index] = true;
        printf("%d -> ", request[index]);
        total += abs(head - request[index]);
        head = request[index];
    }
    printf("\nTotal head movement: %d", total);
    printf("\nAverage head movement: %.2f\n", (float)total / n);

    return 0;
}
