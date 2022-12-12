#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    int result;
    int a_flag = 0, b_flag = 0, c_flag = 0, d_flag = 0, e_flag = 0, err_flag = 0;
    char *c_arg, *e_arg;
    opterr = 0;

    while((result = getopt(argc, argv, "abc:de:")) != -1){
        switch(result){
            case 'a':
                a_flag = 1;
                break;
            case 'b':
                b_flag = 1;
                break;
            case 'c':
                c_flag = 1;
                c_arg = optarg;
                break;
            case 'd':
                d_flag = 1;
                break;
            case 'e':
                e_flag = 1;
                e_arg = optarg;
                break;
            case '?':
                if(optopt == 'c' || optopt == 'e'){
                    fprintf(stderr, "-%c option must have an argument! \n", optopt);
                }
                else
                    fprintf(stderr, "-%c invalid option!\n", optopt);
                    err_flag = 1;
        }
    }

    if(a_flag){
        printf("-a option given \n");
    }

    if(b_flag){
        printf("-b option given \n");
    }

    if(c_flag){
        printf("-c option given with argument \" %s \" \n", c_arg);
    }

    if(d_flag){
        printf("-d option given \n");
    }

    if(e_flag){
        printf("-e option given with argument \" %s\" \n", e_arg);
    }

    if((optind - argc) != 0)
        printf("Arguments without option : \n");

    for(int i = optind; i < argc; i++){
        puts(argv[i]);
    }

    if(err_flag){
        exit(EXIT_FAILURE);
    }
}