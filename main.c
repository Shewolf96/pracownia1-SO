#include <stdio.h>
#include <pthread.h>


void* thr_print( void *arg )
{
    printf("Watek nr 1\n");

    pthread_exit(NULL);
}


void* thr2_print( void *arg )
{
    printf("Watek nr 2\n");

    pthread_exit(NULL);
}



int main()
{
    pthread_t  thread_1, thread_2;

    if (pthread_create (&thread_1, NULL, thr_print, NULL) )
    {
        printf("Blad przy tworeniu thread_1\n");
	return 1;
        //abort();
    }


    if (pthread_create (&thread_2, NULL, thr2_print, NULL) )
    {
        printf("Blad przy tworeniu thread_2\n");
	return 1;
        //abort();
    }


    if (pthread_join (thread_1, NULL) )
    {
        printf("Blad przy konczeniu thread_1\n");
	return 1;
        //exit();
    }


    if (pthread_join (thread_2, NULL) )
    {
        printf("Blad przy konczeniu thread_2\n");
	return 1;
        //exit();
    }

    printf("Watek glowny\n");

    return 0;
}
