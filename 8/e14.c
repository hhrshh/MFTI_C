//E14

// Более одного раза
// Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются 
//более одного раза. В результирующем массиве эти числа не должны повторяться. 

// Данные на входе: 		10 целых чисел через пробел 
// Данные на выходе: 	Целые числа через пробел, которые встречаются более одного раза в исходном массиве. 


#include <stdio.h>
 
const int SIZE = 10;
 
void Print(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ",arr[i]);;
}
 
int Input(int arr[], int n)
{
int i;
    for(i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    return i;
}
 
int selection(int in[], int out[], int len)
{
int count = 0;
int flag = 1;
    for(int i = 0; i < len; i++)
        for(int j = i + 1; j < len; j++)
            if(in[i] == in[j])
            {
                for(int k = 0; k < count; k++)
                {
                    if(out[k] == in[i])
                	{
                        flag = 0;
                        break;
                	}
                	else
                        flag = 1;
                }
                if(flag == 1)
                    out[count++] = in[i];
            }
 
    return count;
}
int main() 
{ 
int in[SIZE];
int out[SIZE];
    Input(in,SIZE);
int count = selection(in,out,SIZE);
    Print(out,count);  
    return 0;
}

