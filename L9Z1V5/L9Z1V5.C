#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int skorost, /*Скорость*/
	      naprav,  /*Направление*/
	      pole,    /*Поле*/
	      error;   /*Код ошибки*/
typedef struct TStudent {
    unsigned char  fam[15],ima[15],otez[15]; /*ФИО*/
    unsigned int  kurs; /*Курс*/
    double sball; /*Средний балл*/
} TStudent;
//Сортировка вставками
//По возрастанию '>' naprav=0
//По убыванию    '<' naprav=1
void SortIns(TStudent st[],int count)
{
 int j,i;               //Индексные переменные
 TStudent tmp;          //Буффер
 if(naprav==0) {        //По возрастанию
 for(j=1;j<count;j++){  //Проверяем каждый элемент с каждым
   i = j - 1;
   tmp = st[j];         //Копируем j-ый элемент в буффер
   switch(pole)         //По какому полю сортировать
   {                    //strcmp = str1 - str2 (-31 = 'А' - 'Я')
       case 1:          //Фамилия
	 while(strcmp(tmp.fam,st[i].fam)<0)
	 {
	   st[i+1] = st[i];
	   i--;
	   if(i<0) break;
	 }
	 break;
       case 2:          //Имя
	 while(strcmp(tmp.ima,st[i].ima)<0)
	 {
	   st[i+1] = st[i];
	   i--;
	   if(i<0) break;
	 }
	 break;
       case 3:          //Отчество
	 while(strcmp(tmp.ima,st[i].otez)<0)
	 {
	   st[i+1] = st[i];
	   i--;
	   if(i<0) break;
	 }
	 break;
       case 4:          //Курс
	 while(tmp.kurs<st[i].kurs)
	 {
	   st[i+1] = st[i];
	   i--;
	   if(i<0) break;
	 }
	 break;
       case 5:          //Средний балл
	 while((tmp.sball<st[i].sball)&&(i>=0))
	 {
	     st[i+1] = st[i];
	     i--;
	 }
	 break;
   }
   st[i+1] = tmp;       //Вставка буффера в массив
 }
 }else{                 //По убыванию
  for(j=1;j<count;j++){ //Проверяем каждый элемент с каждым
   i = j - 1;
   tmp = st[j];         //Копируем j-ый элемент в буффер
   switch(pole)         //По какому полю сортировать
   {                    //strcmp = str1 - str2 (-31 = 'А' - 'Я')
       case 1:          //Фамилия
	 while(strcmp(tmp.fam,st[i].fam)>0)
	 {
	   st[i+1] = st[i];
	   i--;
	   if(i<0) break;
	 }
	 break;
       case 2:          //Имя
	 while(strcmp(tmp.ima,st[i].ima)>0)
	 {
	   st[i+1] = st[i];
	   i--;
	   if(i<0) break;
	 }
	 break;
       case 3:          //Отчество
	 while(strcmp(tmp.ima,st[i].otez)>0)
	 {
	   st[i+1] = st[i];
	   i--;
	   if(i<0) break;
	 }
	 break;
       case 4:          //Курс
	 while(tmp.kurs>st[i].kurs)
	 {
	   st[i+1] = st[i];
	   i--;
	   if(i<0) break;
	 }
	 break;
       case 5:          //Средний балл
	 while((tmp.sball>st[i].sball)&&(i>=0))
	 {
	     st[i+1] = st[i];
	     i--;
	 }
	 break;
   }
   st[i+1] = tmp;       //Вставка буффера в массив
 }
 }
}
void HoorSort(TStudent *st,int min,int max)		
{													
  int Lo,Hi;											
  TStudent buf,mid;								
  switch(pole)										
  {												
	case 1:
	  Lo=min;
  	  Hi=max;
	  mid=st[(Lo+Hi)/2];
	  do {
	  	while(!naprav?(strcmp(st[Lo].fam,mid.fam)<0):(strcmp(st[Lo].fam,mid.fam)>0)) 
		  Lo++;
	   	while(!naprav?(strcmp(st[Hi].fam,mid.fam)>0):(strcmp(st[Hi].fam,mid.fam)<0)) 
		  Hi--;
	    if(Lo<=Hi)	{
	      buf=st[Lo];
		  st[Lo]=st[Hi];
		  st[Hi]=buf;
	  	  Lo++;
		  Hi--;
		}
	  }while(Lo<=Hi);
	  if(Hi>min) HoorSort(st,min,Hi);
	  if(Lo<max) HoorSort(st,Lo,max);
	  break;
	case 2:
	  Lo=min;
  	  Hi=max;
	  mid=st[(Lo+Hi)/2];
	  do {
	  	while(!naprav?(strcmp(st[Lo].ima,mid.ima)<0):(strcmp(st[Lo].ima,mid.ima)>0)) 
		  Lo++;
	   	while(!naprav?(strcmp(st[Hi].ima,mid.ima)>0):(strcmp(st[Hi].ima,mid.ima)<0)) 
		  Hi--;
	    if(Lo<=Hi)	{
	      buf=st[Lo];
		  st[Lo]=st[Hi];
		  st[Hi]=buf;
	  	  Lo++;
		  Hi--;
		}
	  }while(Lo<=Hi);
	  if(Hi>min) HoorSort(st,min,Hi);
	  if(Lo<max) HoorSort(st,Lo,max);
	  break;
    case 3:
	  Lo=min;
  	  Hi=max;
	  mid=st[(Lo+Hi)/2];
	  do {
	  	while(!naprav?(strcmp(st[Lo].otez,mid.otez)<0):(strcmp(st[Lo].otez,mid.otez)>0)) 
		  Lo++;
	   	while(!naprav?(strcmp(st[Hi].otez,mid.otez)>0):(strcmp(st[Hi].otez,mid.otez)<0)) 
		  Hi--;
	    if(Lo<=Hi)	{
	      buf=st[Lo];
		  st[Lo]=st[Hi];
		  st[Hi]=buf;
	  	  Lo++;
		  Hi--;
		}
	  }while(Lo<=Hi);
	  if(Hi>min) HoorSort(st,min,Hi);
	  if(Lo<max) HoorSort(st,Lo,max);
	  break;
    case 4:
	  Lo=min;
  	  Hi=max;
	  mid=st[(Lo+Hi)/2];
	  do {
	  	while(!naprav?(st[Lo].kurs<mid.kurs):(st[Lo].kurs>mid.kurs)) 
		  Lo++;
	   	while(!naprav?(st[Hi].kurs>mid.kurs):(st[Hi].kurs<mid.kurs)) 
		  Hi--;
	    if(Lo<=Hi)	{
	      buf=st[Lo];
		  st[Lo]=st[Hi];
		  st[Hi]=buf;
	  	  Lo++;
		  Hi--;
		}
	  }while(Lo<=Hi);
	  if(Hi>min) HoorSort(st,min,Hi);
	  if(Lo<max) HoorSort(st,Lo,max);
	  break;
	case 5:
	  Lo=min;
  	  Hi=max;
	  mid=st[(Lo+Hi)/2];
	  do {
	  	while(!naprav?(st[Lo].sball<mid.sball):(st[Lo].sball>mid.sball)) 
		  Lo++;
	   	while(!naprav?(st[Hi].sball>mid.sball):(st[Hi].sball<mid.sball)) 
		  Hi--;
	    if(Lo<=Hi)	{
	      buf=st[Lo];
		  st[Lo]=st[Hi];
		  st[Hi]=buf;
	  	  Lo++;
		  Hi--;
		}
	  }while(Lo<=Hi);
	  if(Hi>min) HoorSort(st,min,Hi);
	  if(Lo<max) HoorSort(st,Lo,max);
	  break;
  }
}

//Преобразователь данных
TStudent StringToStudent(char *string)
{
   TStudent st; //Возращаемая структура
   int i;       //Индексная переменная
   // Формат строки:
   // ФАМИЛИЯ ИМЯ ОТЧЕСТВО [КУРС], СРЕДНИЙ_БАЛЛ
   //  15B     15B  15B      1B     3B 
   // Поиск символа-разделителя ' '
   for(i=0;i<15; i++)
   {
		st.fam[i]=0;
        st.ima[i]=0;
		st.otez[i]=0; 
   }
   st.kurs=0;  //0-код ошибки
   st.sball=0.0;
   i=0;
   while((*string!=' ')&&string!=NULL)
   {
     if(i<15) st.fam[i]=*string;
     string++;
     i++;
   } 
   // Поиск символа-разделителя ' '
   //Переход на следующий символ
   string++;
   i=0;
   while((*string!=' ')&&string!=NULL)
   {
     if(i<15) st.ima[i]=*string;
     string++;
     i++;
   } 
   // Поиск символа-разделителя ' '
   //Переход на следующий символ
   string++;
   i=0;
   while((*string!=' ')&&string!=NULL)
   {
     if(i<15) st.otez[i]=*string;
     string++;
     i++;
   }
   //Переход на следующий символ
   string++;
   if(*string=='[')
   {
     string++;
     st.kurs=*string-'0';
     if(st.kurs<0||st.kurs>5) st.kurs=0; //Код ошибки
     string++;
     if(*string==']') string++;
     else             st.kurs=0;
     if(*string==',') string++;
     else             st.kurs=0;
     if(*string==' ') string++;
     else             st.kurs=0;
     st.sball=atof(string);  
   }
   else
     st.kurs=0;
   return st;
}
int main(int argc,char *argv[])
{
    int i,count=0;
		char *s;
    TStudent *students=NULL;
	printf("Лабораторная работа #9\n"
	   "Задание #1 Вариант #5\n"
	   "Иванов И. С. 06-ИТ-2\n"
	   "Введите количество студентов\n");
    while(count<=0)
	{
    	gets(s);  
	    count=atoi(s);
        if(count<=0)  printf("Ошибка!\n"); 
		
 	}   
	students=(TStudent *)calloc(count,sizeof(TStudent));
    if(!students) { printf("Ошибка!\n"); return 0; }
    printf("Введите студентов в формате ");
    printf("Фамилия имя отчество [курс], средний балл:\n");
    error=1;  
	for(i=0; i<count; i++){
		while(error){
			printf("#%d ",i+1);
			gets(s);
		    students[i]=StringToStudent(s);  
			if(students[i].kurs==0) error=1;
			else                    error=0;
		}
		error=1;
    }
    error=0;
    if(argc==4)
    {
	if(!strcmp(argv[1],"a:slow"))      skorost=0; //Медленный
	else if(!strcmp(argv[1],"a:fast")) skorost=1; //Быстрый
	else error=1;

	if(!strcmp(argv[2],"d:inc"))      naprav=0; //Возрастание
	else if(!strcmp(argv[1],"d:dec")) naprav=1; //Убывание
	else error=1;

	if(*argv[3]=='f')
	{
	   argv[3]+=2;
	   pole=*argv[3]-'0';
	}
	else error=1;

    }
    if(error) printf("Ошибка в командой строке");
    if((error==1)||(argc!=4))
    {
    newvvod:
		printf("Введите алгоритм сортировки (0 - медленный 1 - быстрый):\n");
		scanf("%d",&skorost);
		printf("Введите направление сортировки (0 - возрастание 1 - убывание):\n");
		scanf("%d",&naprav);
		printf("Введите номер поля:\n");
		scanf("%d",&pole);
		if(pole>5||naprav>1||skorost>1||pole==0)  
			goto newvvod;
		 
    }
    printf("Выбранные параметры:\n");
    printf("Алгоритм: %s\n",(skorost)?("Быстрый"):("Медленный"));
    printf("Направление %s\n",(!naprav)?("Возрастание"):("Убывание"));
    printf("Поле: %d\n",pole);
    printf("Сортировка.....\n");
    if(skorost==0)  SortIns(students,count);
	else            HoorSort(students,0,count);
    for(i=0; i<count; i++)
      printf("%d %15s %15s %15s %d %0.1lf\n",i+1,students[i].fam,students[i].ima,students[i].otez,students[i].kurs,students[i].sball);
    while(1){   
		printf("Сортировка окончена. Желайте выйти? (Y/N)\n");
    	i=_getch();
    	if(i=='N'||i=='n') goto newvvod;
		if(i=='Y'||i=='y'){free(students);return 0;}
	}
}