vector<int> primes; // we'll preload primes once at the beginning
int phi(int n) {
  int ret = n;
  for (int i = 0; i < primes.size(); i++) {
    if (n % primes[i] == 0) {
      ret -= ret / primes[i];
    }
  }
  return ret;
}