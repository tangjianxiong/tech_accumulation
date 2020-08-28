#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_NUMBER 3        /*thread count*/
#define REPEAT_NUMBER 4        /*Number of subtasks*/
#define DELAY_TIME_LEVELS 10.0 /*time interval*/
pthread_mutex_t mutex;
void *thrd_func(void *arg)
{
    int thrd_num = (int)arg;
    int delay_time = 0, count = 0;
    int res;
    res = pthread_mutex_lock(&mutex);
    if (res)
    {
        printf("thread %d lock failed\n", thrd_num);
        pthread_exit(NULL);
    }
    printf("thread %d is starting\n", thrd_num);
    for (count = 0; count < REPEAT_NUMBER; count++)
    {
        delay_time = (int)(rand() * DELAY_TIME_LEVELS / (RAND_MAX) + 1);
        sleep(delay_time);
        printf("\tThread %d :job %d delay=%d\n", thrd_num, count, delay_time);
    }
    printf("thread %d finished\n", thrd_num);
    pthread_exit(NULL);
}
int main()
{
    pthread_t thread[THREAD_NUMBER];
    int no, res;
    void *thrd_ret;
    srand(time(NULL));
    /*mutex init*/
    pthread_mutex_init(&mutex, NULL);
    /*create threads*/
    for (no = 0; no < THREAD_NUMBER; no++)
    {
        res = pthread_create(&thread[no], NULL, thrd_func, (void *)no);
        if (res != 0)
        {
            printf("create thread %d failed\n", no);
            exit(res);
        }
    }
    printf("Create threads success \n Waitting for threads to finish...\n");
    /*Wait for the thread to end*/
    for (no = 0; no < THREAD_NUMBER; no++)
    {
        res = pthread_join(thread[no], &thrd_ret);
        if (!res)
        {
            printf("thread %d joined\n", no);
        }
        else
        {
            printf("thread %d join failed\n", no);
        }
        pthread_mutex_unlock(&mutex);
    }
}