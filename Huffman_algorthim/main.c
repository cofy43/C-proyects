#include <stdio.h>
int main()
{
    FILE *fp;
    char c[1024];
    fp = fopen("fichero.txt", "r");
    int i = 0;
    while (1)
    {
        c[i] = fgetc(fp);
        if (feof(fp))
        {
            break;
        }
        printf("%c", c[i]);
        i++;
    }
    fclose(fp);

    return (0);
}