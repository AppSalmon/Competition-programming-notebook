bool isPrime[N];
void sieve() {
	// bool isPrime[N+1];
	for(int i = 0; i <= N;++i) 
	{
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i = 2; i * i <= N; ++i) 
	{
		if(isPrime[i] == true) 
		{
			// Mark all the multiples of i as composite numbers
			for(int j = i * i; j <= N; j += i)
				isPrime[j] = false;
		}
	}
}

void sieve2(){
	isprime[0] = 0;
	isprime[1] = 1;

	for(int i = 2; i*i<N; i++){
		if(isprime[i] == 0){
			for(int j = i*i; j <=N; j+=i){
				if(isprime[j] == 0){
					isprime[j] = i;
				}
			}
		}
	}
	for (int i = 2; i < N; ++i) {
		if (isprime[i] == 0) {
			isprime[i] = i;
		}
	}
}