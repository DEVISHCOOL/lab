#include<string.h> 
#include<ctype.h> 
#include<stdio.h> 
int main()
{
FILE *input, *output; 
int l=1, t=0, j=0, i, flag; 
char ch, str[20];
char keyword[30][30]={"int", "main", "if", "else", "do", "while"}; 
clrscr();
input=fopen("input.txt",
"r");
output=fopen("output.txt", "w");
fprintf(output, "Line no. \tToken no. \t Token \t\t Lexeme\n\n"); 
while(!feof(input))
{
i=0;
flag=0; 
ch=fgetc(input);
if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
{
fprintf(output, "%7d\t\t%7d\t\tOperator\t\t%7c\n", l, t, ch); 
t++;
}
else if(ch==';'||ch=='{'||ch=='}'||ch=='('||ch==')'||ch=='?'||ch=='@'||ch=='!'||ch=='%')
{
fprintf(output, "%7d\t\t%7d\t\tSpecial Symbol\t%7c\n", l, t, ch); 
t++;
}
else if(isdigit(ch))
{
fprintf(output, "%7d\t\t%7d\t\tDigit\t\t%7c\n", l, t, ch); 
t++;
}
else if(isalpha(ch))
{
str[i]=ch; 
i++;
ch=fgetc(input);

while(isalnum(ch)&&ch!=' ')
{
str[i]=ch; 
i++;
ch=fgetc(input);
}
str[i]='\0';
for(j=0; j<=30; j++)
{
if(strcmp(str, keyword[j])==0)
{
flag=1; 
break;
}
}
if(flag==1)
{
fprintf(output, "%7d\t\t%7d\t\tKeyword\t\t%7s\n", l, t, str); 
t++;
}
else
{
fprintf(output, "%7d\t\t%7d\t\tIdentifiers\t\t%7s\n", l, t, str); 
t++;
}
}

else if(ch=='\n')
{
i++;
}
}
fclose(input); 
fclose(output); 
getch();
return 0;
}


INPUT:input.txt
include<stdio.h>
void main()
{
  printf("HEllo World");
}
