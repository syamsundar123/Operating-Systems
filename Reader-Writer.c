#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>


pthread_mutex_t mutex,wrt;
int shared_variable,read_count = 0;


void *writer(void *a)
{
        pthread_mutex_lock(&wrt);
        int random_time;
        random_time = rand() % 10;
        int  *d = ((int*)a);
        printf("=======================================================================\n");
        printf("W%d is waiting for Random Time = %d\n", *d, random_time);
        sleep(random_time);
        int No_of_times;
        printf("Enter the no. of times W%d wants to write:\n", *d);
        scanf("%d",&No_of_times);
        printf("W%d is Writing...\n", *d);
        for(int j = 1; j<= No_of_times;j++)
                {
                        printf("Enter the value %d to write\n",j);
                        int up;
                        scanf("%d",&up);
                        shared_variable += up;
                }
        printf("UPDATED SHARED VARIABLE  = %d\n",shared_variable);
        printf("========================================================================\n");
        pthread_mutex_unlock(&wrt);
}
void *reader(void *arg)
{
        //Entry Part
        pthread_mutex_lock(&mutex);
        read_count++;
        if(read_count == 1)
        {
                pthread_mutex_lock(&wrt);//No writer  should come
        }

        pthread_mutex_unlock(&mutex);//Next reader can Come.
        //Exit Part
        int random_time = rand() % 10;
        int *d = ((int *)arg);
        printf("R%d is waiting for random time = %d\n",*d, random_time);
        sleep(random_time);
       // printf("Enter the number of times R%d wants to read:\n", *d);
        int No_of_times;
        printf("Enter the number of times R%d wants to read:\n", *d);

        scanf("%d",&No_of_times);
        printf("R%d is reading\n",*d);

        for(int j = 1;j<= No_of_times;j++)
        {
                printf("R%d is reading shared value = %d\n",*d,shared_variable);
        }

        printf("Number of readers = %d\n",read_count-1);
	//printf("Enter Number of times to read:");
        pthread_mutex_lock(&mutex);
        read_count--;

        if(read_count == 0)
        {
                pthread_mutex_unlock(&wrt);//Any writer can come if they want..!
        }
        pthread_mutex_unlock(&mutex);
}
void main()
{
        printf("Enter the Initial  value of Shared Variable(INTEGER Format):");
        scanf("%d",&shared_variable);
        printf("========================================================================\n");
        int no_of_readers,no_of_writers,i;
        printf("Enter the number of readers");
        printf("\n");
        scanf("%d",&no_of_readers);
	 if(no_of_readers<0 )
                {
                                printf("You have enetered a negative number of readers\n");
                                printf("Program will be terminated...!\n");
                                return;

                }

        for(i = 0; i < no_of_readers ; i++)
        {
                printf("R%d\n",i);
        }
        printf("=========================================================================\n");
        printf("Enter the number of  writers:");
        scanf("%d",&no_of_writers);
	 if(no_of_writers < 0)
                {
                                printf("You have enetered a negative number of writers\n");
                                printf("Program will be terminated\n");
                                return;

                }
        for(int i = 0;i< no_of_writers;i++)
        {
                printf("W%d\n",i);
        }
        printf("=========================================================================\n");
        pthread_t r[no_of_readers],w[no_of_writers];
        pthread_mutex_init(&wrt,NULL);
        pthread_mutex_init(&mutex,NULL);

         if(no_of_readers == 0)
                {
                        printf("Sorry...!, You have not taken any reader\n");
                        printf("No READER thread will be created...!\n");
                }
         else if(no_of_writers == 0)
                {
                        printf("Sorry...!, You have not taken any writer\n");
                        printf("No WRITER thread will be created...!\n");
                }
        else
        {
                printf("Thread Creating...!\n");
        }
        printf("=========================================================================\n");

        if(no_of_readers == no_of_writers)
                {
                        for(i = 0;i< no_of_writers;i++)
                        {
                                pthread_create(&w[i], NULL, &writer, &i);
                                pthread_create(&r[i], NULL, &reader, &i);
                        }
                        for(i = 0; i<no_of_writers;i++)
                        {
                                pthread_join(w[i],NULL);
                                pthread_join(r[i],NULL);

                        }
               }
	else if(no_of_writers>no_of_readers)
                {
                        for(i = 0;i< no_of_readers;i++)
                        {
                                pthread_create(&w[i], NULL, &writer, &i);
                                pthread_create(&r[i], NULL, &reader, &i);
                        }
                        for(i = no_of_readers;i<no_of_writers;i++)
                        {

                                pthread_create(&w[i], NULL, &writer,&i); 
                        }

                        for(i = 0;i< no_of_readers;i++)
                        {
                                pthread_join(w[i], NULL);
                                pthread_join(r[i], NULL);
                        }
                        for(i = no_of_readers;i<no_of_writers;i++)
                        {

                                pthread_join(w[i], NULL);
                        }
                }
        else
                {
                        for(i = 0;i< no_of_writers;i++)
                        {
                                pthread_create(&w[i], NULL, &writer, &i);
                                pthread_create(&r[i], NULL, &reader, &i);
                        }
                        for(i = no_of_writers;i<no_of_readers;i++)
                        {

                                pthread_create(&r[i], NULL, &reader, &i);
                        }

                        for(i = 0;i< no_of_writers;i++)
                        {
                                pthread_join(w[i], NULL);
                                pthread_join(r[i], NULL);
                        }
                        for(i = no_of_writers;i<no_of_readers;i++)
                        {

                                pthread_join(r[i], NULL);
                        }
                }
        printf("======================After Joining the Thread=========\n");
        printf("Final Value Of Shared Variable is:%d\n",shared_variable);
}

