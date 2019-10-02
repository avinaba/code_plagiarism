void getMinMax(int a[],int l) 
{
	int max;
	
	int min = max = a[0];
	
	for(int i=1;i<l;i++)
	{
		if(a[i] < min)
			min = a[i];
	}
	
	for(int i=1;i<l;i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	
	printf("\nMax val = %d ",max);
	printf("\nMin val = %d ",min);
	
}
