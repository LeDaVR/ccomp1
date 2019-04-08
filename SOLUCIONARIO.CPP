
“Hello, World” 
2.1
Hello World I 
# include < iostream >using namespace std ;
int main ()
{
	const char * str = " Hello , World ! " ;
	cout << str << " \ n " ;
	return 0;
}

2.2
Hello World II (9 points)
1. for loop: 

# include < iostream >
using namespace std ;
int main ()
{
	int N ;
	cin >> N ;
	for (; N - - > 0;)
	{
		cout << " Hello , World !\ n " ;
	}
	return 0;
}

2. while loop: (3 points)
# include < iostream >
using namespace std ;
int main ()
{

	int N ;
	cin >> N ;
	while (N - - > 0)
	{
		cout << " Hello , World !\ n "
	}
	return 0;
}

3. do...while loop: (3 points)

# include < iostream >
using namespace std ;
int main ()
{
	int N ;
	cin >> N ;
	do
	{
		cout << " Hello , World !\ n " ;
	}
	while ( - - N > 0) ;
	return 0;
}

3.2
Basic Statistics (10 points)
# include < iostream >
using namespace std ;
int main ()
{
	int N ;
	cout << " Enter N : " ;
	cin >> N ;
	int acc = 0;
	// handle the first number separately
	cin >> acc ;
	int minVal = acc ;
	int maxVal = acc ;
	// then process the rest of the input
	for ( int i = 1; i < N ; ++ i )
	{
		int a ;
		cin >> a ;
		acc += a ;
		if ( a < minVal )
		{
			minVal = a ;
		}
		if ( a > maxVal )
		{
			maxVal = a ;
		}
	}
	cout<<" Mean : " << ( double ) acc / N << " \ n " ;
	cout<<" Max : " << maxVal << " \ n " ;
	cout<<" Min : " << minVal << " \ n " ;
	cout<<" Range : " << ( maxVal - minVal ) << " \ n " ;
	return 0;
}


Prime Numbers (10 points)
# include < iostream >
using namespace std ;
int main ()
{
	int N ;
	cin >> N ;
	for ( int i = 2; N > 0; ++ i )
	{
		bool isPrime = true ;
		for ( int j = 2; j < i ; ++ j )
		{
			if ( i % j == 0)
		{
		isPrime = false ;
		break ;
		}
		}
		if ( isPrime )
		{
			--N ;
			cout << i << " \ n " ;
		}
	}
	return 0;
}


Ternary operator 
# include < iostream >
using namespace std ;
int main ()
{
	while (1)
	{
		int N ;
		cin >> N ;
		cout << (( N % 5 == 0 && N >= 0) ? N /5 : -1) << " \ n " ;
	}
	return 0;
}


3.4.2  continue
# include < iostream >
using namespace std ;
int main ()

{
	while (1)
	{
		int N ;
		cin >> N ;

		if ( N % 5 > 0)
		{
			cout << " -1\ n " ;
			continue ;
		}
		cout << N /5 << " \ n " ;
	}
	return 0;
}

3.4.3  break (3 points)
# include < iostream >
using namespace std ;
int main ()
{
	while (1)
	{
		int N ;
		cin >> N ;
		if ( N % 5 > 0)
		{
			cout << " -1\ n " ;
			continue ;
		}
		if ( N == -1)
		{
			break ;
		}
		cout << N /5 << " \ n " ;
	}
	cout << " Goodbye !\ n " ;
	return 0;
}


3.5
/ bob and dole are integers
int accumulator = 0;
while ( true )
{
	if ( dole == 0) break ;
	accumulator += (( dole % 2 == 1) ? bob : 0) ;
	dole /= 2;
	bob *= 2;
 }
	cout << accumulator << " \ n " ;



4.4
Rewriting Factorial 

# include < iostream >
using namespace std ;
long long accumulator = 1;
int main ()
{
	int number ;
	cout << " Enter a number : " ;
	cin >> number ;
	if ( number < 0)
	{
		cout << " No negative numbers allowed !\ n " ;
		return 1;
	}
	if ( number > 20)
	{
		cout << " Program will not produce correct result !\ n " ;
	}
	for (; number > 0; accumulator *= number - -) ;
	cout << " The factorial of " << number << " is " << accumulator << " .\ n " ;
	return 0;
}

4.5 Rewriting Factorial II 

# include < iostream >
using namespace std ;
int main ()
{
	int number ;
	cout << " Enter a number : " ;
	cin >> number ;
	switch ( number )
	{
		case 0:
		case 1:
			cout << " 1\ n " ;
			break ;
		case 2:
			cout << " 2\ n " ;
			break ;
		case 3:
			cout << " 6\ n " ;
		break ;
		case 4:
			cout << " 24\ n " ;
			break ;
		case 5:
			cout << " 120\ n " ;
			break ;
		case 6:
			cout << " 720\ n " ;
			break ;
		case 7:
			cout << " 5040\ n " ;
			break ;
		case 8:
			cout << " 40320\ n " ;
			break ;
		case 9:
			cout << " 362880\ n " ;
			break ;
		case 10:
			cout << " 3628800\ n " ;
			break ;
		default :
			cout << " Input not supported !\ n " ;
			break ;
	}
	return 0;
}
