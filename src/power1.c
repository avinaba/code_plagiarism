double power(double x,double n) 
{
	double result=1;
	
	for(int i=0;i<n;i++)
	{
		result = result * x;
	}
	
	return result;
}
