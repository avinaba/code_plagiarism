double power(double x,int n) 
{
	if( n == 0 )
		return 1;
	else if (n == 1)
		return x;
	else 
	{
		double r = pow(n/2);
		if(n%2 == 0)
			return r*r;
		else
			return r*r*x;
	}

}
