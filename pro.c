#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int initialize(int *age)
{
	int i,n;
	n=rand()%50;
	for(i=0;i<n;i++)
	{
		age[i]=rand()%100;
	}
	printf("\n\tPopulation Generated:\n");
	for(i=0;i<n;i++)
	{
		printf("\n\tGeneration %d: \t Age: %d",(i+1),age[i]);
	}
	return n;
}
void encoding(int age[],int store[][10],int n)
{
	int k,l,i,j;
	for(i=0;i<n;i++)
	{
		k=age[i];
		for(j=0;j<10;j++)
		{
			if(k<2)
			{
				store[i][j]=k;
				while(j<10)
				{
					j++;
					store[i][j]=0;
				}
				break;
			}
		store[i][j]=k%2;
		l=k/2;
		k=l;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("\tGeneration : %d Age : %d Factors : ",(i+1),age[i]);
		for(j=0;j<10;j++)
		{
			printf("%d ",store[i][j]);
		}
	}
}
void score(int age[],int store[][10],int n,int eval[])
{
	int i,j;
	float sum[100],avg=0;
	for(i=0;i<n;i++)
	{
		sum[i]=0;
		for(j=0;j<10;j++)
		{
			sum[i]=sum[i]+store[i][j];
		}	
	}
	for(i=0;i<n;i++)
	{
		avg=avg+(sum[i]/n);
	}
	printf("\n\tAverage : %f ",avg);
	for(i=0;i<n;i++)
	{
		eval[i]=sum[i]/avg;
	}
	for(i=0;i<n;i++)
	{	
		eval[i]=eval[i]+.5;
		printf("\n\tGeneration %d : Fitness Score : %d",(i+1),eval[i]);
	}
}
void selection(int eval[],int n,int store[][10],int *age)
{
        int temp[100],i,j,k=0;
        for(i=0;i<n;i++)
        {
                temp[i]=rand()%2;
                printf("\n\tRandom Number between 1 and 0 : %d",temp[i]);
        }
        for(i=0;i<n;i++)
        {
                if(eval[i]!=temp[i])
		{
			age[i]=0;		
                }
        }
}
void crossover(int new[],int store[][10],int k)
{
	if(k%2!=0)
	{k=k-1;}
	int i,j,m=k/2,lk[100],ran[100],b=0;
	for(i=0;i<m;i++)
	{
		lk[i]=rand()%k;
	}
	for(i=k;i<(k+m);i++)
	{
		new[i]=rand()%100;
	}
	for(i=0;i<m;i++)
	{
		ran[i]=rand()%2;
	}
	for(i=k;i<(k+m);(i+2))
	{
		if(ran[b]==0)
		{for(j=0;j<5;j++)
		{
			store[i][j]=store[lk[i]][j];		
		}i++;
		}
		else
		{for(j=0;j<5;j++)
                {
                        store[i][j]=store[lk[i]][j];
                }
		i++;}
		if(ran[b]==1)
		{for(j=5;j<10;j++)
                {
			store[i][j]=store[lk[i]][j];
                }i++;
		}
		else
		{for(j=5;j<10;j++)
                {
                        store[i][j]=store[lk[i]][j];

                }}
		

	}
}
void mutation(int k,int store[][10],int new[],int m)
{
	int i,j,a[10],b,d,c;
	c=rand()%11;
	d=rand()%11;
	b=k/8;
	for(i=0;i<b;i++)
	{
		a[i]=rand()%(k+m);
	}
	for(i=0;i<(k+m);i++)
	{
		if(c==a[i])
		{store[i][d]=rand()%2;}
	}
}
		
main()
{
	int n,age[100],store[100][10],eval[100],i,new[100],k=0,m,j;
	system("clear");
	n=initialize(age);
	printf("\n\tTotal Number Of Generations: %d",n);
	encoding(age,store,n);
	score(age,store,n,eval);
	selection(eval,n,store,age);
	printf("\n\tNew Total: ");
	for(i=0;i<n;i++)
        {
                printf("\n%d",age[i]);
        }
	for(i=0;i<n;i++)
	{
		if(age[i]!=0)
		{
			new[k]=age[i];
			k++;
		}
	}
	printf("\n");
	printf("\tNumber of people selected : %d\n",k);
	printf("\tSelected People:\n");
	for(i=0;i<k;i++)
        {
                printf("\nGeneration %d: Age: %d",(i+1),new[i]);
        }
	printf("\n\n");
	encoding(new,store,k);
	crossover(new,store,k);
	m=k/2;
	printf("\tNew Population:\n");
	for(i=0;i<(k+m);i++)
        {
                printf("\n");
                printf("\tGeneration : %d Age : %d Factors : ",(i+1),age[i]);
                for(j=0;j<10;j++)
                {
                        printf("%d ",store[i][j]);
                }
        }
	mutation(k,store,new,m);
	printf("\n\n\tAfter Mutation:\n");
        for(i=0;i<(k+m);i++)
        {
                printf("\n");
                printf("\tGeneration : %d Age : %d Factors : ",(i+1),age[i]);
                for(j=0;j<10;j++)
                {
                        printf("%d ",store[i][j]);
                }
        }
	score(new,store,(k+m),eval);
	for(i=0;i<(k+m);i++)
	{	
		if(eval[i]!=1)
		{
		}
	}
		
}	

