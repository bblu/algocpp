#include <stdio.h>
#include <pthread.h>

void* thread_fun(void* _arg){
    unsigned int* arg = _arg;
    printf(" new thread: tid is %u\n", *arg);
};

void main(){
    pthread_t new_thread_id;
    pthread_create(&new_thread_id, NULL, thread_fun, &new_thread_id);
    printf("new thread: tid is %u\n", pthread_self());
    usleep(100);
};
