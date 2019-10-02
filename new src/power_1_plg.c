long double power(long double x,int exp) 
{
	long double res=1;
	
	for(int i=0;i<exp;i++)
		res = res * x;

	
	return res;
}
