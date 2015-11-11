#include <stdio.h>
#include <stdlib.h>

void minimumTime(int *time, int people){
	int i, j, tmp, totaltime = 0, unbridge = 0;
	int min1, min2;

	if(people == 1){
		printf("%d\n", time[0]);
		return;
	}

	/* Sort decreasing! */
	for(i = 0 ; i<people ; i++){
		for(j = i+1 ; j<people ; j++){
			if(time[i] < time[j]){
				tmp = time[i];
				time[i] = time[j];
				time[j] = tmp;
			}
		}
	}
	min1 = time[people-1];
	min2 = time[people-2];
	unbridge = people;
	while(unbridge != 0){

		if(unbridge == 2){
			totaltime += min2;
			printf("%d\n", totaltime);
			return;
		}
		else if(unbridge == 3){
			totaltime += time[people-unbridge] + min1 + min2;
			printf("%d\n", totaltime);
			return;
		}
		else{
			if( (time[people-unbridge+1]+min1) > 2*min2)
				totaltime += min2 + min1 + time[people-unbridge] + min2;
			else
				totaltime += time[people-unbridge] + time[people-unbridge+1] + 2*min1;

			unbridge -= 2;
		}
	}
}

int main(int argc, char *argv[]){

	int people, i, tmp;
	int *time = NULL;

	while( scanf("%d",&people) != EOF ){
		if(people >= 1 && people <= 30)
			time = malloc(people*sizeof(int));
		else 
			break;
		for(i = 0 ; i<people ; i++){
			scanf("%d", &tmp);
			if(tmp >= 1 && tmp <= 1000)
				time[i] = tmp;
			else
				return -1;
		}
		minimumTime(time, people);
	}

	return 0;
}

