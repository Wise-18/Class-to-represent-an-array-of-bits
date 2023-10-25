// binnums.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>

class TBinNumber 
{
private:
	int n;
public:
	TBinNumber( int  _n = 0 )
	{
		n = _n;
	}

	int get( int i )
	{
		return (n >> i) & 1;
	}

	void set( int i,  int bit )
	{
		n = (n & ~(1 << i)) | (bit << i);
	}

	std::string toStr( int base )
	{
		std::string r = "";

		if (n == 0)
			return "0";

		for( int t = n; t != 0; t /= base )
		{ 
			r = (char) ('0'+ t % base) + r;
		}

		return r;
	}

	void set10( int v )
	{
		n = v;
	}
};

void numMenu( TBinNumber &num )
{
    int n;
    while (true)
    {
		printf( "  Number menu: %s\t%s\n", num.toStr(2).c_str(), num.toStr(10).c_str());
        printf( "  1. Set bit\n" );
        printf( "  2. Clear bit\n" );
        printf( "  3. Enter in 10\n" );
        printf( "  0. Quit\n" );

        scanf( "%d", &n );

        if (n == 0) break;
        if (n == 1)
        { // Set bit
			int i, v;

			printf( "    Enter index: " );
			scanf( "%d", &i );
			printf( "    Enter value: " );
			scanf( "%d", &v );

			num.set( i, v );
        }
        if (n == 2)
        { // Clear bit
			int i;

			printf( "    Enter index: " );
			scanf( "%d", &i );

			num.set( i, 0 );
        }
        if (n == 3)
        { // Enter in 10
			int v;

			printf( "    Enter value (10): " );
			scanf( "%d", &v );

			num.set10( v );
        }
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	TBinNumber num1, num2;

    int n;
    while (true)
    {
        printf( "Menu\n");
		printf( "1. Number 1: %s\t%s\n", num1.toStr(2).c_str(), num1.toStr(10).c_str() );
        printf( "2. Number 2: %s%\t%s\n", num2.toStr(2).c_str(), num2.toStr(10).c_str() );
        printf( "3. And \n" );
        printf( "4. Or \n" );
        printf( "5. Xor\n" );
        printf( "0. Quit\n" );

        scanf( "%d", &n );

        if (n == 0) break;
        if (n == 1)
        { // Number 1
			numMenu( num1 );
        }
        if (n == 2)
        { // Number 2
			numMenu( num2 );
        }
        if (n == 3)
        { // And 
			int i, v1, v2;
			TBinNumber r;

			for( i = 0; i < 30; i++ )
			{
				v1 = num1.get(i);
				v2 = num2.get(i);

				r.set( i, v1 & v2 );
			}

			printf( "Result %s\t%s\n", r.toStr(2).c_str(), r.toStr(10).c_str() );
        }
        if (n == 4)
        { // Or 
			int i, v1, v2;
			TBinNumber r;

			for( i = 0; i < 30; i++ )
			{
				v1 = num1.get(i);
				v2 = num2.get(i);

				r.set( i, v1 | v2 );
			}

			printf( "Result %s\t%s\n", r.toStr(2).c_str(), r.toStr(10).c_str() );
        }
        if (n == 5)
        { // Xor
			int i, v1, v2;
			TBinNumber r;

			for( i = 0; i < 30; i++ )
			{
				v1 = num1.get(i);
				v2 = num2.get(i);

				r.set( i, v1 ^ v2 );
			}

			printf( "Result %s\t%s\n", r.toStr(2).c_str(), r.toStr(10).c_str() );
        }
    }

	return 0;
}

