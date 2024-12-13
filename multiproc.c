#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

int process(){
}
int summerize(){

}
int main(int argc, char * argv[]){
    int p=0,s=0,w=5,h=0,i=1;
    char * help="-p <prog>, --proc <prog> The program for the processing operation (default: cat)\n-s <prog>, --summary <prog> The program for the summarize operation (default: cat)\n-w <workers>, --workers <workers> The number of forked processes(default: 5, max: 20)\n";
    char * proc="cat";
    char * summary="cat";
    for (;i<argc && argv[i][0]=='-';i++){
        if(strcmp(argv[i],"-p")==0||strcmp(argv[i],"--proc")==0){
            proc=argv[++i];
        }
        else if(strcmp(argv[i],"-s")==0||strcmp(argv[i],"--summary")==0){
            summary=argv[++i];
        }
        else if(strcmp(argv[i],"-w")==0||strcmp(argv[i],"--workers")==0){
            w= atoi(argv[++i])>0?(atoi(argv[i])>20?20:atoi(argv[i])):5;
        }
        else if(strcmp(argv[i],"-h")==0||strcmp(argv[i],"--help")==0){
            printf("%s",help);
        }
        else{
            fprintf(stderr, "%s",help);
            exit(EXIT_FAILURE);
        }
    }
    for (;i<argc;i++){
        pid_t pid=fork();
        if (pid < 0) {
            goto error;
        } else if (pid == 0) {
            process();
            summerize();
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
        }
    }
    exit(EXIT_SUCCESS);
    return 0;
error:
    fprintf(stderr, "An error occured\n");
    exit(EXIT_FAILURE);

    
}