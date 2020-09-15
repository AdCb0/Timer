#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct time
{
	int sec, min, hour;
}l, p;

int main()
{	setlocale(LC_ALL, "Rus");
printf("Это таймер\n");
start:;

char 
ch1[5000],
*ch2;

int 
temp_int = 0,
sec_need = 0,
sec_start = 0,
sec = 0,
temp_sec = 0;


printf("\n");
secs: 	printf("Секунды: ");	ch2 = gets(ch1);	temp_int = atoi(ch2); 	if( temp_int>59 | temp_int<0) 	goto secs;	sec_need = sec_need + temp_int;
mins: 	printf("Минуты: "); 	ch2 = gets(ch1); 	temp_int = atoi(ch2); 	if( temp_int>59 | temp_int<0) 	goto mins;	sec_need = sec_need + temp_int * 60;
hours: 	printf("Часы: "); 		ch2 = gets(ch1); 	temp_int = atoi(ch2); 	if( temp_int<0) 				goto hours;	sec_need = sec_need + temp_int * 3600;
printf("\n");

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
			printf("\n\n------------------------------\n\nВремя вышло\n\n------------------------------\n\a\a\a\a\a");
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
