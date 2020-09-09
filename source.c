#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* Functions */

void display(void);
void update(int DELAY);
void delay(int DELAY);

/* Global variables */



/* Global struct's */
struct my_time {int hours; int minutes; int seconds; } timer,need, left;

/* Code */
int main(int argc, char *argv[])
{	setlocale(LC_ALL, "Rus");

register int DELAY = 4320;

FILE *fp;
int s = 0, create_files=0;
char *p, f[5000];

if(argc>1) 
{ 
	for(int p=0; p<argc ;++p) 
	{
		if(! atoi(argv[p])=='\0') DELAY = atoi(argv[p]);
		else if(*argv[p] == *"file") create_files = 1;
	} 
}

	puts("Это таймер");
	printf("\nТекущее значение: %i\n", DELAY);
	
	start_prog:
	timer.hours = 0;
	timer.minutes = 0;
	timer.seconds = 0;

	secs: 	printf("\nВведите секунды: ");	p = gets(f);	s = atoi(p); 	if( s>59 | s<0) 	goto secs; 	left.seconds =	need.seconds = s;
	mins: 	printf("Введите минуты: "); 	p = gets(f); 	s = atoi(p); 	if( s>59 | s<0) 	goto mins; 	left.minutes =	need.minutes = s;
	hours: 	printf("Введите часы: "); 		p = gets(f); 	s = atoi(p); 	if( s<0) 			goto mins; 	left.hours	 =	need.hours 	 = s;
	printf("\n");
	if(create_files==1) {fp =  fopen("1 - Начало", "wb+"); fclose (fp); }

	for(;;)
	{
		update(DELAY);
		display();
		if(timer.seconds==need.seconds && timer.minutes==need.minutes && timer.hours==need.hours)
		{
			if(create_files==1) { fp =  fopen("2 - Конец", "wb+"); fclose (fp); }
			
			printf("\n------------------------------\n\nВремя вышло\n\n------------------------------\n");
			printf("\a\a\a\a");
			break;
		}
	}

	goto start_prog;
}

void update(int DELAY)
{
	timer.seconds++;
	left.seconds--;
	
	/* Прошло */
	
	if(timer.seconds==60)
	{
		timer.seconds = 0;
		timer.minutes++;
	}
	
	if(timer.minutes==60)
	{
		timer.minutes = 0;
		timer.hours++;
	}

	/* Осталось */
	
	if(left.seconds==-1)
	{
		left.seconds = 59;
		left.minutes--;
	}
	
	if(left.minutes==-1)
	{
		left.minutes = 59;
		if(left.hours==0); 
		else left.hours--;
	}

	delay(DELAY);
}

void display(void)
{
	if(need.hours !=0 | need.minutes !=0 | need.seconds !=0)
	printf("%02i:%02i:%02i	-	 %02i:%02i:%02i\n", timer.hours, timer.minutes, timer.seconds, left.hours, left.minutes, left.seconds);
	else 
	printf("%02i:%02i:%02i	-	 --:--:--\n", timer.hours, timer.minutes, timer.seconds);
}

void delay(int DELAY)
{
	long int t;
	for(t=1; t<DELAY*100000; ++t);
}
