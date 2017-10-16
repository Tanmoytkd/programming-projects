import java.math.BigInteger;

public class PrimeTester {
  public static boolean isPrime(int n) {
    BigInteger number = new BigInteger(n + "");
    return number.isProbablePrime(10);
  }
  public static void main(String[] args) {
    System.out.println(isPrime(13));
  }
}