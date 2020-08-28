#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define THREAD_NUMBER   3//线程数
#define REPEAT_NUMBER   5//每个线程中的小任务数
#define DELAY_TIME_LEVELS   10.0//小任务之间的最大时间间隔

//线程函数
void *thrd_func(void *arg){
    int thrd_num=(int)arg;
    int delay_time= 0;
    int count = 0;

    printf("Thread %d is starting\n",thrd_num);
    for(count=0; count<REPEAT_NUMBER; count++){
        delay_time=(int)(rand()*DELAY_TIME_LEVELS/(RAND_MAX))+1;
        sleep(delay_time);
        printf("\tThread %d :job %d  delay %d \n",thrd_num,count,delay_time);
    }
    printf("Thread %d finished \n",thrd_num);
    pthread_exit(NULL);
}
int main(){
    pthread_t thread[THREAD_NUMBER];
    int no, res;
    void *thrd_ret;
    srand(time(NULL));

    for(no=0; no<THREAD_NUMBER; no++){
        //创建多线程
        res=pthread_create(&thread[no],NULL,thrd_func,no);
        if(res!=0){
            printf("thread %d is not created...\n",no);
            exit(res);
        }
    }

    printf("Creating threads success \n Waiting for threads to finish...\n");

    for(no=0; no<THREAD_NUMBER; no++){
        //等待线程结束
        res=pthread_join(thread[no],&thrd_ret);
        if(!res){
            printf("Thread %d joined\n",no);
        }
        else{
            printf("Thread %d joined failed\n",no);
        }
    }
    return 0;
}
