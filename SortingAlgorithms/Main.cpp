// #include<sys/resource.h>
#include<ios>
#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>

long get_mem_usage(){
    struct rusage myusage;
    getrusage(RUSAGE_SELF,&myusage);
    return myusage.ru_maxrss;
}


int main(){
    long baseline=get_mem_usage();
    for(int i=0;i<100;i++){
        char *p=malloc(1024*100);
        memset(p,1,1024*100);
        sleep(1);
        printf("usage: %ld + %ld\n",baseline,get_mem_usage());
    }
}