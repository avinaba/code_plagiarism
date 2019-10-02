int main()
{
   char string[200];
   int start, mid, end, len = 0;
 
   scanf("%s",string);
 
   while ( string[len] != '\0' )
      len++;
 
   end = len - 1;
   mid = len/2;
 
   for( start = 0 ; start < mid ; start++ )
   {
      if ( string[start] != string[end] )
      {
         break;
      }
      end--;
   }
   if( start == mid )
      printf("Palindrome.\n");
   else
	   printf("Not Palindrome.");
 
   return 0;
}
