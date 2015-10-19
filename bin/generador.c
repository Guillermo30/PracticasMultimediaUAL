#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 4) {
        printf("Usage: %s <initial_value> <increment> <#total>\n", argv[0]);
        return 1;
    }

    short initial_value = (short) atoi(argv[1]);
    short increment = (short) atoi(argv[2]);
    int total = atoi(argv[3]);

    FILE *f;
    f = fopen("samples.bytes", "wb");
    
    short sample = initial_value;
    for(short i=0; i < total; i++) {
        fwrite(&sample, sizeof(short), 1, f);
        sample = sample + increment;
    }
    
    fclose(f);

    return 0;
}
