#include <stdio.h>

int main() {
    int l, r, t;
    scanf("%d %d %d", &l, &r, &t);

    int c = 0;
    for (int i = l; i <= r; i++) 
    {
        int temp = i; 

        while (temp != 0) 
        {
            int digit = temp % 10;
            if (digit > t) 
            {
                c++;
            }
            temp = temp / 10;
        }

    }

    printf("%d\n", c); 
    return 0;
}
