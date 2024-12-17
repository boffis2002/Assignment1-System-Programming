#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

int process(){
    return 0;
}
int summerize(){
    return 0;
}
void outputHelp(int std){
    FILE * f=fopen("help.txt","r");
    char buf[1001];
    while(fgets(buf,1001,f)){
        if(std==1) printf("%s",buf);
        else if(std==0) fprintf(stderr,"%s",buf);
    }
    fclose(f);
}
int main(int argc, char * argv[]){
    //Lettura argomenti
    int w=5,i=1;
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
            outputHelp(1);
        }
        else{
            outputHelp(0);
            exit(EXIT_FAILURE);
        }
    }

    //Esecuzioni
    for (;i<argc;i++){
        if(w);
        pid_t pid=fork();
        if (pid < 0) {
            goto error;
        } else if (pid == 0) {
            process(proc);
            summerize(summary);
            exit(EXIT_SUCCESS);
        } else {
        }
    }
    exit(EXIT_SUCCESS);
    return 0;
error:
    fprintf(stderr, "An error occured\n");
    exit(EXIT_FAILURE);

    
}