#include <stdio.h>
int main()
{


int c[5][5], max[5][5], avail[5];
int a[5] = {0, 0, 0, 0, 0};
int mr[5], r[5], s = 0;
int pro;
 
	printf("no of processes: ");
    	scanf("%d", &pro);
 	int counter = 0, i, j, e, resources, k = 1;
    	for (i = 0; i < pro; i++) 
	{
        	r[i] = 1;
        	counter++;
    	}
 
    	printf("no of resources: ");
    	scanf("%d", &resources);
 
    	printf("\nEnter Claim Vector:");
    	for (i = 0; i < resources; i++) 
	{ 
	        scanf("%d", &mr[i]);
    	}
 
   	printf("\nEnter Allocated Resource Table:\n");
    	for (i = 0; i < pro; i++) 
	{
	        for(j = 0; j < resources; j++) 
		{
  			scanf("%d", &c[i][j]);
        	}
    	}
 
    	printf("\nEnter Maximum Claim Table:\n");
    	for (i = 0; i < pro; i++) 
	{
        	for(j = 0; j < resources; j++) 
		{
            		scanf("%d", &max[i][j]);
        	}
    	}
 
	printf("\nThe Claim Vector is: ");
    	for (i = 0; i < resources; i++) 
	{
	        printf("\t%d", mr[i]);
	}
 
    	printf("\nThe Allocated Resource Table:\n");
    	for (i = 0; i < pro; i++) 
	{
	        for (j = 0; j < resources; j++) 
		{
            		printf("\t%d", c[i][j]);
        	}
		printf("\n");
    	}
 
    	printf("\nThe Maximum Claim Table:\n");
    	for (i = 0; i < pro; i++) 
	{
        	for (j = 0; j < resources; j++) 
		{
		        printf("\t%d", max[i][j]);
        	}
        	printf("\n");
    	}
 
    	for (i = 0; i < pro; i++) 
	{
        	for (j = 0; j < resources; j++) 
		{
            		a[j] += c[i][j];
        	}
    	}
 
    	printf("\nAllocated resources:");
    	for (i = 0; i < resources; i++) 
	{
        	printf("\t%d", a[i]);
    	}
 
    	for (i = 0; i < resources; i++) 
	{
	        avail[i] = mr[i] - a[i];
	}
 
    	printf("\nAvailable resources:");
    	for (i = 0; i < resources; i++) 
	{
        	printf("\t%d", avail[i]);
    	}
    	printf("\n");
 
    	while (counter != 0) 
	{
        	s = 0;
        	for (i = 0; i < pro; i++) 
		{
            		if (r[i]) 
			{
                		e = 1;
                		for (j = 0; j < resources; j++) 
				{
                    			if (max[i][j] - c[i][j] > avail[j]) 
					{
                        			e = 0;
                        			break;
                    			}
                		}
                		if (e) 
				{
                    			printf("\nProcess%d is euting\n", i + 1);
                    			r[i] = 0;
                    			counter--;
                    			s = 1;
 
                    			for (j = 0; j < resources; j++) 
					{
                        			avail[j] += c[i][j];
                    			}
			                break;
                		}
            		}
        	}
        	if (!s) 
		{
            		printf("\nThe pro are in unsafe state.\n");
            		break;
        	} 
		else 
		{
            		printf("\nThe process is in safe state");
            		printf("\nAvailable vector:");
 
            		for (i = 0; i < resources; i++) 
			{
                		printf("\t%d", avail[i]);
            		}
 
		        printf("\n");
        	}
    	}
    	return 0;
}
