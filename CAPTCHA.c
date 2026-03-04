#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char captcha[20];
    int length;
    int choice;
    int index;

    srand(time(NULL));

    printf("Enter CAPTCHA length: ");
    scanf("%d", &length);

    for(int i = 0; i < length; i++)
    {
        index = rand() % 26;     // pick random letter
        choice = rand() % 2;     // 0 = lowercase, 1 = uppercase

        if(choice == 0)
            captcha[i] = alphabet[index];
        else
            captcha[i] = alphabet[index] - 32; // convert to uppercase
    }

    captcha[length] = '\0';

    printf("Generated CAPTCHA: %s\n", captcha);

    return 0;
}
