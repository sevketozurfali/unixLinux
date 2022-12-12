#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]){
    
    int result;
    struct option options[] = {
        {"size", no_argument, NULL, 1},
        {"length", required_argument, NULL, 2},
        {"number", optional_argument, NULL, 3},
        {0,0,0,0},
    };

    char *b_arg, *length_arg, *number_arg = NULL;

    // opterr = 0;

    while((result = getopt_long(argc, argv, "ab:", options, NULL)) != -1){
        switch(result){
            case 'a':
                printf("-a option given\n");
                break;
            case 'b':
                printf("-b option given\n");
                b_arg = optarg;
                break;
            case 1:
                printf("--size option given\n");
                break;
            case 2:
                printf("--length option given\n");
                length_arg = optarg;
                break;
            case 3:
                printf("--number option given\n");
                number_arg = optarg;
                break;
        }

    }

}