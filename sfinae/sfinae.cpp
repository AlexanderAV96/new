#include <vector>
#include <iostream>
#include <list>
#include <iterator>
#include <type_traits>
#include <string>
#include <bitset>


template<class T , class U>
struct is_same : std::false_type { };

template<class T>
struct is_same<T , T> : std::true_type { };




template < class T >
void print( T & arg , typename std::enable_if< std::is_same< T , int8_t >::value || std::is_same< T , int16_t >::value || std::is_same< T , int32_t >::value  || std::is_same< T , int64_t >::value >::type* = {} )
{
	
	
	
	auto const Value = reinterpret_cast< const uint8_t* >( &arg );
	for ( int i = ( sizeof( arg ) - 1 ); i >= 0; i-- )
	{

		std::cout << static_cast< int > ( Value [ i ] );

		if ( i > 0 )
		{
			std::cout << ".";
		}

		

	}
	
	
	std::cout << std::endl;
	
	
	
}

//1
template < class T>
void print( T const& arg , typename std::enable_if< is_same< T , std::vector<int>  >::value   >::type* = {} )//::value* = {}
{
	for ( int i = 0; i < arg.size( ); i++ )
	{

		if ( i == ( arg.size( ) - 1 ) ) { std::cout << arg[i] << '\n'; }
		else { std::cout << arg[i] << '.'; }


	}
}


template < typename T >
void print( T const& arg , typename std::enable_if< is_same< T , std::list<short>  >::value   >::type* = {} )
{
	
	auto it2 = arg.end( );
	it2--;
	
	for ( auto it = arg.begin( ); it != arg.end( ); it++ )
	{
		if ( *it != *it2 ) { std::cout << *it << "."; }
		else {  std::cout << *it << '\n';
		}


	}
}

template < typename T >
void print( T const& arg , typename std::enable_if< is_same< T , std::string  >::value   >::type* = {} )
{
	std::cout << arg << '\n';
}


template < class T    >
void print( T const& numb, typename std::enable_if< !std::is_same< T , int8_t >::value || !std::is_same< T , int16_t >::value || !std::is_same< T , int32_t >::value || !std::is_same< T , int64_t >::value
			|| !std::is_same< T , std::vector<int>  >::value|| !std::is_same< T , std::list<short>  >::value || !std::is_same< T , std::string  >::value >::type )
{
	std::cout << "smthng wrng ";
}







int main( )
{


	int8_t _8bit = -1;
	int16_t _16bit{ 0 };
	int32_t _32bit{ 2130706433 };
	int64_t _64bit{ 8875824491850138409 };
	std::string str{ "Hello, World!" };
	std::vector <int> vic{ 100,200,300,400 };
	std::list <short> lst{ 400,300,200,100 };



	print( _8bit );
	print( _16bit );
	print( _32bit );
	print( _64bit );
	print( str );
	print( vic );
	print( lst );


	

	
	
	

	




}
