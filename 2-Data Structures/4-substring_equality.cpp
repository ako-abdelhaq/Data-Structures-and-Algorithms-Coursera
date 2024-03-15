#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Source code of the Hash fuction from : https://github.com/kartikdutt18

class Solver {

public:
	Solver( string s)  : s( s ), S( s.size() ) {
        Power();
        Hash();
	}

	bool ask(int a, int b, int l) {
        if ( a == b ) {
            return true;
        }
        
        long long a_m1 = Check1( a, l );
        long long b_m1 = Check1( b, l );
        
        if ( a_m1 != b_m1 ) {
          return false;
        }
        
        long long a_m2 = Check2( a, l );
        long long b_m2 = Check2( b, l );
        
        if ( a_m2 != b_m2 ) {
          return false;
        }
        
        return true;
	}

private:
  string s;
  unsigned int S;
  const long long prime1 = 1000000007;
  const long long prime2 = 1000000009;
  const long long mult1 = rand() % prime1; 
  const long long mult2 = rand() % prime2; 

  vector< long long > power1;
  vector< long long > power2;

  vector< long long > Hash1;
  vector< long long > Hash2;

  void Power() {
    power1.resize( S );
    power1[ 0 ] = 1;
    for ( int i = 1; i < S ; ++i ) {
      power1[ i ] = ( power1[ i - 1 ] * mult1 ) % prime1;
    }
    power2.resize( S );
    power2[ 0 ] = 1;
    for ( int i = 1; i < S; ++i ) {
      power2[ i ] = ( power2[ i - 1 ] * mult2 ) % prime2;
    }
  }

  void Hash() {
    Hash1.resize( S + 1 ) ;
    Hash2.resize( S + 1 ) ;
    Hash1[ 0 ] = 0;
    Hash2[ 0 ] = 0;
    for ( unsigned int i = 0; i < S; ++i ) {
      Hash1[ i + 1 ] = ( Hash1[ i ] + s[ i ] * power1[ i ] ) % prime1;
      Hash2[ i + 1 ] = ( Hash2[ i ] + s[ i ] * power2[ i ] ) % prime2;
    }
  }

  long long Check1 (  const int start , const int length ) {
    long long a = ( Hash1[ start + length ] + prime1 - Hash1[ start ] ) % prime1;
    return ( a * power1[ S - start - 1 ] ) % prime1;
  }
  
  long long Check2 (  const int start , const int length ) {
    long long a = ( Hash2[ start + length ] + prime2 - Hash2[ start ] ) % prime2;
    return ( a * power2[ S - start - 1 ] ) % prime2;
  }
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver( s );
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << ( solver.ask(a, b, l) ? "Yes\n" : "No\n" );
	}
	return 0;
}
	