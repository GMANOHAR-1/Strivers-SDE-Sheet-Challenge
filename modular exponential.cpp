 
int modularExponentiation(int x, int n, int m) {
 	int answer = 1;

 	while (n > 0) {
 		if (n & 1)  {
			answer = (1LL * answer * x) % m;
		}
 		x = (1LL * x * x ) % m;

 		n >>= 1;
	}
 	return answer;
}
