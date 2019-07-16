#include <stdio.h> 

int main()
{
	char dateArry[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	char str[4][100]={0};
	int i=0;
	int flag=0;
	int date=0, hour=0, minute=0; 
	
	for(i=0; i<4; i++)
	{
		fgets(str[i], 100, stdin);
	}
	
	for(i=0; (str[0][i] != '\0') && (str[1][i] != '\0'); i++)
	{
		if(str[0][i] == str[1][i])
		{
			if((0 == flag) && (str[0][i] >= 'A' && str[0][i] <= 'Z'))
			{
				date = str[0][i] - 'A';
				flag = 1;
			}
			else if(1 == flag) 
			{
				if(str[0][i] >= 'A' && str[0][i] <= 'N') 
				{
					hour = str[0][i] - 'A' + 10;
					break;
				}
				else if(str[0][i] >= '0' && str[0][i] <= '9') 
				{
					hour = str[0][i] - '0';
					break;
				}
			}
		}
	} 
	
	for(i=0; (str[2][i] != '\0') && (str[3][i] != '\0'); i++)
	{
		if((str[2][i] >= 'A' && str[2][i] <= 'Z') || (str[2][i] >= 'a' && str[2][i] <= 'z') && (str[2][i] == str[3][i]))
		{
			minute = i;
			break;
		}
	} 
	
	printf("%s %02d:%02d\n", dateArry[date], hour, minute);
	
	return 0;
}


