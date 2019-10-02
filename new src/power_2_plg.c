double power(double x,int n) 
{
	if( n == 0 )
		return 1;
	else if (n == 1)
		return x;
	else 
	{
		if(n%2 == 0)
			return pow(n/2)*pow(n/2);
		else
			return pow(n/2)*pow(n/2)*x;
	}

}
