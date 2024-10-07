#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct freshman_score{

	char name[80];
	double school_grade;
	int eng;
}score;

int num;
score *em;

void personnel();
int allocation_memory();
void input();
int check_elite();

int main() {

	int check;

	personnel();
	check = allocation_memory();
	if(check == 0) return 0;

	input();
	check_elite();

	free(em);

	return 0;
}

void personnel(){

	printf("How many people do you check? ");
	scanf("%d", &num);
}

int allocation_memory(){

	em = (score *)calloc(num, sizeof(score) );
	if(em == NULL) {

		printf("LINE 41, calloc memory Error\n");
		return 0;
	}
}

void input(){

	int i;

	for(i = 0 ; i < num ; i++){

		printf("%d : Input Name, School grade, English grade : ", i+1);
		scanf("%s%lf%d", em[i].name, &em[i].school_grade, &em[i].eng);
	}
}

int check_elite(){

	int i, check = 0;
	char **elite = NULL;
	
	for(i = 0 ; i < num ; i++){

		if( ( (em + i) -> school_grade >= 4.0 ) && ( (em + i) -> eng >= 900 ) ){ //school grade 4.0 or high & English grade 900 or high

			if(check == 0) elite = (char **)malloc( (check+1) * sizeof(char *) );
			else elite = (char **)realloc(elite, (check+1) * sizeof(char *) );	

			if(elite == NULL) {

				printf("LINE 74, 75, memory Error\n");
				return 0;
			}

			elite[check] = (char *)malloc( strlen(em[i].name) * sizeof(char) + 1 );

			if(elite[check] == NULL) {

				printf("LINE 83, memory Error\n");
				return 0;
			}

			strcpy(elite[check], em[i].name);

			check++;
		}
	}

	printf("Elite : ");
	for(i = 0 ; i < check ; i++) {
		
		if(i == check-1) printf("%s", elite[i]);
		else printf("%s, ", elite[i]);
	}

	printf("\n");

	for(i = 0 ; i < check ; i++) free(elite[i]);
	free(elite);

	return 0;
}