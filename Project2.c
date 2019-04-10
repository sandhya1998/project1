#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

enum  res {pen=1,paper=2,question_paper=3};

pthread_mutex_t l;
int i;
struct Student{
	int name;
	int value;
}s[3];

int val;

void *run(){

	pthread_mutex_lock(&l);

	for(i=0;i<3;i++){
        	if((s[i].value+val)==6){
                        printf("\n%d is writing.",s[i].name);
                        printf("\n%d has finished writing.",s[i].name);
                 }
        }

	pthread_mutex_unlock(&l);

}


void *resource(){

	pthread_mutex_lock(&l);
	int i;
	i=rand()%3;
	if(i==0){
		val=pen+paper;
	}
	else if(i==1){
		val=pen+question_paper;
	}
	else{
		val=paper+question_paper;
	}
	pthread_mutex_unlock(&l);
}


int main(){

	s[0].value=pen;
	s[0].name=1;
	s[1].value=paper;
	s[1].name=3;
	s[2].value=question_paper;
	s[2].name=2;

	pthread_t teacher,student;
	pthread_mutex_init(&l,NULL);

	int n,i;

	printf("Enter the number of times you want the teacher process to be run");
	scanf("%d",&n);

	i=0;
	while(i<n){
		pthread_create(&teacher,NULL,resource,NULL);
		pthread_join(teacher,NULL);

		pthread_create(&student,NULL,run,NULL);
		pthread_join(student,NULL);
		i++;
	}

}



