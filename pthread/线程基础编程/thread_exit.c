#include<stdio.h>
#include<pthread.h>

void *create(void *arg){
    printf("New thread is create...\n");
    pthread_exit((void *) 5);
}
int main(){
    pthread_t tid;
    int res;
    void *temp;
    res=pthread_create(&tid,NULL,create,NULL);
    printf("I am the main thread!\n");
    if(res){
        printf("thread is not created...\n");
        return -1;
    }

    res=pthread_join(tid,&temp);
    if(res){
        printf("Thread is not exit...\n");
        return -2;
    }
    printf("thread is exit code %d\n",(int)temp);
    return 0;
}
