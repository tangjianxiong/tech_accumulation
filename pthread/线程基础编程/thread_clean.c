#include<stdio.h>
#include<pthread.h>

//Çå³ýº¯Êý
void *clean(void *arg){
    printf("cleanup:%s \n",(char *)arg);
    return (void*)0;
}
void *thr_fn1(void *arg){
    printf("Thread1 start:\n");
    pthread_cleanup_push((void *)clean,"thread1 first handler");
    pthread_cleanup_push((void *)clean,"thread1 second handler");
    printf("thread1 push complete \n");
    if(arg){
        return ((void *)1);
    }
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);
    return (void *)2;
}
void *thr_fn2(void *arg){
    printf("Thread2 start:\n");
    pthread_cleanup_push((void *)clean,"thread2 first handler");
    pthread_cleanup_push((void *)clean,"thread2 second handler");
    printf("thread2 push complete \n");
    if(arg){
        return ((void *)3);
    }
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(0);
    return (void *)4;
}

int main(){
    int res;
    pthread_t tid1,tid2;
    void *tret;
    res=pthread_create(&tid1,NULL,thr_fn1,(void *)1);
    if(res){
        printf("thread is not created...\n");
        return -1;
    }
    res=pthread_create(&tid2,NULL,thr_fn1,(void *)0);
    if(res){
        printf("thread is not created...\n");
        return -1;
    }

    res=pthread_join(tid1,&tret);
    if(res!=0){
        printf("thread_join error...\n");
        return -1;
    }
    printf("Thread1 exit code %d\n",(int) tret);
    res=pthread_join(tid2,&tret);
    if(res!=0){
        printf("Thread_join error\n");
    }
    printf("Thread2 exit code %d\n",(int) tret);
}
