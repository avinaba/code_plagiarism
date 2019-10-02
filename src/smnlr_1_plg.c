void printMinMaxinput(int input[],int size) 
{
	int min,max;
	
	min = max = input[0];
	
	for(int i=1;i<size;i++)
	{
		if(input[i] > max)
			max = input[i];
		
		if(input[i] < min)
			min = input[i];
		
	}
	printf("\nMin: %d \t Max: %d",min,max);
	
}
