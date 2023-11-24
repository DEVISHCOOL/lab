# include <stdio.h> 
# include <conio.h> 
# include <string.h> 
void main()
{
char input[10];
int start,length,address; 
FILE *fp1,*fp2; 
clrscr();
fp1=fopen("input.dat","r");
fp2=fopen("output.dat","w");
fscanf(fp1,"%s",input); 
while(strcmp(input,"E")!=0)
{
if(strcmp(input,"H")==0)
{
fscanf(fp1,"%d",&start); 
fscanf(fp1,"%d",&length); 
fscanf(fp1,"%s",input);
}
else if(strcmp(input,"T")==0)
{
fscanf(fp1,"%d",&address); 
fscanf(fp1,"%s",input);
DEVISH 211191101028
fprintf(fp2,"%d\t%c%c\n",address,input[0],input[1]); 
fprintf(fp2,"%d\t%c%c\n",(address+1),input[2],input[3]); 
fprintf(fp2,"%d\t%c%c\n",(address+2),input[4],input[5]); 
address+=3;
fscanf(fp1,"%s",input);
}
else
{
fprintf(fp2,"%d\t%c%c\n",address,input[0],input[1]); 
fprintf(fp2,"%d\t%c%c\n",(address+1),input[2],input[3]); 
fprintf(fp2,"%d\t%c%c\n",(address+2),input[4],input[5]); 
address+=3;
fscanf(fp1,"%s",input);
}
}
fclose(fp1); 
fclose(fp2); 
printf("FINISHED"); 
getch();
}



INPUT:
h 1000 232
t 1000 142033 483039 102036
t 2000 298300 230000 282030 302015
e