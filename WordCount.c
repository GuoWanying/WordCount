#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
    char c;
    int Ccnt = 0, Wcnt = 0;
    FILE * f;
    if (argc != 3) {
        printf("Parameter error!\n");
    }
    if ((f = fopen(argv[2], "rb")) == NULL) {
        printf("Can not open the source file!\n");
            exit(0);
    }
    fseek(f, 0L, 0);
        while (!feof(f)) {
            fread(&c, 1, 1, f);
                if (c == ' ' || c == ',')  Wcnt++;
                Ccnt++;
        }
    Wcnt++;
    if (strcmp(argv[1], "-w") == 0) printf("********µ¥´ÊÊý£º%d ********\n", Wcnt);
    else if (strcmp(argv[1], "-c") == 0) printf("********×Ö·ûÊý£º%d ********\n", Ccnt);
    fclose(f);
    return 0;
}
