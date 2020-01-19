#include<stdio.h>

int ary[10][10], completed[10], n, cost=0;

void takeInput(int r)
{
	int i, j;
    i=0;
    FILE *fileptr;
    char c[100];
    char m[100];
    int nrchr=0;
    if(r==0)
        if ((fileptr = fopen( "C:\\Users\\Tania\\Desktop\\villages2.txt ", "r"))== NULL)
            printf("Error opening file\n");
        else
            while(fscanf(fileptr, "%s", c)!=EOF){
                m[nrchr]=c[0];
                nrchr++;
            }
    else
        if ((fileptr = fopen( "C:\\Users\\Tania\\Desktop\\villages3.txt ", "r"))== NULL)
            printf("Error opening file\n");
        else
            while(fscanf(fileptr, "%s", c)!=EOF){
                m[nrchr]=c[0];
                nrchr++;
            }

    char aux;
    int far[100];
    for(i=0;i<nrchr;i++){
        aux=m[i];
        far[i]=aux;
        far[i]=far[i]-48;
    }
    fclose(fileptr);

    n=far[0];
    if(r==0)
        printf("\nThe number of villages is: %d",n);

    int nrr=1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++){
            ary[i][j]=far[nrr];
            nrr++;
        }
        completed[i] = 0;

	}

	printf("\n\nThe cost list is:");

	for (i = 0; i < n; i++)
	{
		printf("\n");

		for (j = 0; j < n; j++)
			printf("\t%d", ary[i][j]);
	}

}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;

	for(i=0;i < n;i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min)
			{
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}

	if(min!=999)
		cost+=kmin;

	return nc;
}

int fr=0;

void mincost(int city, int r)
{
	int i,ncity;

	completed[city]=1;
    if(r==0){
        if(city==n-1){
            fr=1;
            printf("%d",city+1);
            return;
        }
        else
            printf("%d--->",city+1);

        ncity=least(city);

        if(ncity==999)
        {
            ncity=0;
            printf("%d",ncity+1);
        if(city!=n-1)
            cost+=ary[city][ncity];

            return;
        }

    }
    else{
        if(city==n-1){
            fr=1;
            printf("%d",n-city);
            return;
        }
        else
            printf("%d--->",n-city);

        ncity=least(city);

        if(ncity==999)
        {
            ncity=0;
            printf("%d",n-ncity);
            cost+=ary[city][ncity];

            return;
        }

    }

	mincost(ncity, r);
}



int main()

{   int maxcost=0;
	takeInput(0);

	printf("\n\nThe Path from 1 to %d is:\n",n);
	mincost(0,0); //passing 0 because starting vertex

	printf("\n\nMinimum cost for the first friend is %d.\n",cost);
	maxcost=cost;

    cost=0;

	takeInput(1);

	printf("\n\nThe Path from %d to 1 is:\n",n);
	mincost(0,1); //passing 0 because starting vertex

	printf("\n\nMinimum cost for the second friend is %d.\n",cost);
	if(maxcost<cost)
        maxcost=cost;

    printf("\n\nThe minimum cost for the two friends to meet is %d.\n ",maxcost);


	return 0;
}

