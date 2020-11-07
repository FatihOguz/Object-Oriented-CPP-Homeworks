#include <iostream>
using namespace std;
unsigned int fib(int start,int level) /* start : begiining fibonacci pattern , level : masch as for loop fibonacci series */
{
	int i;
	if(level==0)		/* first case for fibonacci */
	{
		return start;
	}
	if(level==1)		/* second case for fibonacci */
	{
		return start;
	}
	if(level==2)		/* third case for fibonacci */
	{
		return 2*start;
	}
	unsigned int ans=start+start;
	unsigned int temp1=start;
	unsigned int temp2=ans;
	for(i=3;i<=level;i++)
	{
		ans=ans+temp1;			/* fibonacci pattern  */
		temp1=temp2;
		temp2=ans;
	}
	return ans;
}

void pyramid(int number)
{
	unsigned int ans=1;
	int i=1,j=1,k=0,f=0;

	unsigned int max=1;
	unsigned int cor;
	unsigned int start,level;

	if(number<0)
	{
		return;							/* do not draw pyramid for fibonacci series */
	}

		
for(i=0;i<=number;i++)					/* number of lines */
	{
		f=k;							/* The number i is an auxiliary number but it should affect the i number. */
		cout<<fib(1,i)<<" ";			/* write first fibonacci series */
	
		for(j=1;j<=i;j++)
		{
			if(number%2==0)			/* piramid örüntüsünde level tek ise merkez nokta tektir aksi halde çift */
			{
				cor=number/2;
				if(i==cor)
				{
					if(i%2==0)
					{
						if(j==cor/2)
						{
							ans=fib(fib(1,j),f-1);  
						}
					}
					else
					{
						if(j==(cor+1)/2)
						{
							ans=fib(fib(1,j),f-1);
						}
					}
				}
			}
			else
			{
				cor=(number+1)/2;
				if(i==cor)
				{
					if(i%2==0)
					{
						if(j==cor/2)
						{
							ans=fib(fib(1,j),f-1);		/*fonk içindeki fonk hangi katsayýlý fib oldugunu 2. parametre kaçýncý fib sayýsý oldugunu söyler */
						}
					}
					else
					{
						if(j==(cor+1)/2)
						{
							ans=fib(fib(1,j),f-1);		/*fonk içindeki fonk hangi katsayýlý fib oldugunu 2. parametre kaçýncý fib sayýsý oldugunu söyler */
						}
					}	
				}	
			}
			
			
			
/*****************************************************************************************************************************************************************************/
			
			
		
			max=fib(fib(1,j),f-1);					/* if number is greater than max then number assign to max number. */
			
			cout<<fib(fib(1,j),f-1)<<" ";				/* draw pyramid */
			f--;
		}
		cout<<endl;			
		k++;					/* ilk sayýlarýn fibonacci olmasýnda kullanýlýr */
	}
	if(max<0)
	{
		max=max*(-1);
	}
	
/************************************************************************************************************************************************/
	cout<<"Biggest number:"<<max<<endl;

	if(number%2==0)					/* number is even number */
	{
		cor=(number/2);
		if(cor%2==0)			/* if number is even number then heart is odd number*/
		{
			cout<<"Heart of the pyramid:"<<ans<<endl;
		}
		else		/* if number is odd number then heart is even number. */
		{
				cout<<"Heart of the pyramid:"<<ans<<" "<<ans<<endl;
		}
	}
	else				/* number is not even number */
	{
		cor=(number+1)/2;
		if(cor%2==0)			/* if cor is even number then heart is odd number*/
		{
			cout<<"Heart of the pyramid:"<<ans<<endl;	
		}
		else				/* if cor is odd number then heart is odd number. */
		{
			cout<<"Heart of the pyramid:"<<ans<<" "<<ans<<endl;	
		}
	}
	cout<<endl;

}


int main()
{
	int number;
	pyramid(-5);		/* does not draw pyramid in negative condition. */
	pyramid(0);			/* draws a 1 digit pyramid in case 0. */
	pyramid(46);		/* integer overflow limit but define unsigned so program works true. */
	pyramid(7);			/* natural case */
	pyramid(1);			/* heart case of 2 level */
	cin>>number;
	pyramid(number);
	return 0;
}

