#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, head, total = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter the disk request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Disk Scheduling Order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d -> ", request[i]);
        total += abs(request[i] - head);
        head = request[i];
    }

    printf("\nTotal head movement: %d", total);
    printf("\nAverage head movement: %.2f\n", (float)total / n);

    return 0;
}
