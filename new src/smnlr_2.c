void find_min_and_max(int array[],int length) 
{
	int min,max;
	
	min = max = array[0];
	
	for(int i=0;i<length;i++)
	{
		if(array[i] < min)
			min = array[i];
	}
	
	for(int i=0;i<length;i++)
	{
		if(array[i] > max)
			max = array[i];
	}
	
	printf("The minimum value is: %d ",min);
	printf("The maximum value is: %d ",max);
}
