#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/* Delphine's */
#define RU 0
#define EN 1

#define LANGUAGE EN


#if LANGUAGE == RU


#define TEXT_THIS_TIMER 	"Это таймер"
#define TEXT_WRONG_ARG_SEC	"Неверный аргумент (Секунды)"
#define TEXT_WRONG_ARG_MIN	"Неверный аргумент (Минуты)"
#define TEXT_WRONG_ARG_HOUR	"Неверный аргумент (Часы)"
#define TEXT_ENTER_SEC 		"Введите секунды: "
#define TEXT_ENTER_MIN		"Введите минуты: "
#define TEXT_ENTER_HOUR 	"Введите часы: "
#define TEXT_TIME_UP 		"Время вышло"


#elif LANGUAGE == EN


#define TEXT_THIS_TIMER 	"This is a timer"
#define TEXT_WRONG_ARG_SEC	"Wrong argument (Seconds)"
#define TEXT_WRONG_ARG_MIN	"Wrong argument (Minutes)"
#define TEXT_WRONG_ARG_HOUR	"Wrong argument (Hours)"
#define TEXT_ENTER_SEC 		"Enter seconds: "
#define TEXT_ENTER_MIN 		"Enter minuts: "
#define TEXT_ENTER_HOUR		"Enter hours: "
#define TEXT_TIME_UP 		"Time is up"

#endif



struct time
{
	int sec, min, hour;
}l, p;

int main(int argc, char *args[])
{	setlocale(LC_ALL, "Rus");

int 
temp_int = 0,
sec_need = 0,
sec_start = 0,
sec = 0,
temp_sec = 0;

if(argc > 1)
{
	temp_int = atoi(args[1]); 					if( temp_int>59 | temp_int<0)	printf("%s\n", TEXT_WRONG_ARG_SEC); 
	if(argc > 2) { temp_int = atoi(args[2]); 	if( temp_int>59 | temp_int<0)	printf("%s\n", TEXT_WRONG_ARG_MIN); }
	if(argc > 3) { temp_int = atoi(args[3]); 	if( temp_int<0)					printf("%s\n", TEXT_WRONG_ARG_HOUR);}
	printf("\n");
	temp_int = atoi(args[1]); 	if( temp_int>59 | temp_int<0)		goto startprog;	sec_need = sec_need + temp_int;
	if(argc > 2)
	{
		temp_int = atoi(args[2]); 	if( temp_int>59 | temp_int<0)	goto startprog;	sec_need = sec_need + temp_int * 60;
		if(argc > 3)
		{
			temp_int = atoi(args[3]); 	if( temp_int<0)				goto startprog;	sec_need = sec_need + temp_int * 3600;
		}
	}
	
printf("%s\n\n",TEXT_THIS_TIMER);
goto RunTimer;
}

startprog:;

printf("%s\n",TEXT_THIS_TIMER);
start:;

char 
ch1[5000],
*ch2;

temp_int = 0;
sec_need = 0;
sec_start = 0;
sec = 0;
temp_sec = 0;


printf("\n");
secs: 	printf("%s",TEXT_ENTER_SEC);	ch2 = gets(ch1);	temp_int = atoi(ch2); 	if( temp_int>59 | temp_int<0) 	goto secs;	sec_need = sec_need + temp_int;
mins: 	printf("%s",TEXT_ENTER_MIN); 	ch2 = gets(ch1); 	temp_int = atoi(ch2); 	if( temp_int>59 | temp_int<0) 	goto mins;	sec_need = sec_need + temp_int * 60;
hours: 	printf("%s",TEXT_ENTER_HOUR); 	ch2 = gets(ch1); 	temp_int = atoi(ch2); 	if( temp_int<0) 				goto hours;	sec_need = sec_need + temp_int * 3600;
printf("\n");

RunTimer:
sec = time(NULL);
sec_need = sec_need + sec;
sec_start = sec;

if(sec != sec_need)
for(;;) 
{
	
	sec = time(NULL);

	if(temp_sec != sec )
	{
		l.sec = 0; l.min = 0; l.hour = 0;
		p.sec = 0; p.min = 0; p.hour = 0;
	
		l.sec = sec_need - sec;
		while(l.sec >= 60) { l.sec = l.sec - 60; ++l.min; }
		while(l.min >= 60) { l.min = l.min - 60; ++l.hour;}
		
		p.sec = sec - sec_start;
		while(p.sec >= 60) { p.sec = p.sec - 60; ++p.min; }
		while(p.min >= 60) { p.min = p.min - 60; ++p.hour;}
				
		printf("%02d:%02d:%02d	-	%02d:%02d:%02d\r",p.hour,p.min,p.sec,l.hour,l.min,l.sec);
		if(sec >= sec_need)
		{
			printf("\n\n------------------------------\n\n%s\n\n------------------------------\n\a\a\a\a\a",TEXT_TIME_UP);
			goto start;
		}
		temp_sec = sec;
	}
}
else
for(;;)
{
	sec = time(NULL);

	if(temp_sec != sec )
	{
		p.sec = 0; p.min = 0; p.hour = 0;
	
		p.sec = sec - sec_start;
		while(p.sec >= 60) { p.sec = p.sec - 60; ++p.min; }
		while(p.min >= 60) { p.min = p.min - 60; ++p.hour;}
				
		printf("%02d:%02d:%02d	-	--:--:--\r",p.hour,p.min,p.sec);

		temp_sec = sec;
	}
	
}

goto start;
}
