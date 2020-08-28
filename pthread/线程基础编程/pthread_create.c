#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *mythread1(){
    int i;
    for(i=0; i<5; i++){
        printf("I am the 1st pthread, created by mybeilef321\n");
        sleep(2);
    }
}
void *mythread2(){
    int i;
    for(i=0; i<5; i++){
        printf("I am the 2st pthread, created by mybeilef321\n");
        sleep(2);
    }
}

int main(){
    pthread_t id1, id2;
    int res;
    res=pthread_create(&id1,NULL,mythread1,NULL);
    if(res){
        printf("create pthread error!\n");
        return 1;
    }
    //创建线程并执行相应函数
    res=pthread_create(&id2,NULL,mythread2,NULL);
    if(res){
        printf("create pthread error!\n");
        return 1;
    }
    //等待两个线程退出，main再退出
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    return 1;
}
