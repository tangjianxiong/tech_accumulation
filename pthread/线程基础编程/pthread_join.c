#include<stdio.h>
#include<pthread.h>

void *thread(void *str){
    int i;
    for(i=0; i<4; ++i){
        sleep(2);
        printf("This is the thread:%d\n",i);
    }
    return NULL;
}
int main(){
    pthread_t pth;
    int i;
    int ret=pthread_create(&pth,NULL,thread,NULL);
    pthread_join(pth,NULL);
    printf("123\n");
    for(i=0;i<3;++i){
        sleep(1);
        printf("This is the main :%d\n",i);
    }
    return 0;

}
