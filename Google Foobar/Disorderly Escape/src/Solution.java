import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;

public class Solution {
    public static ArrayList<BigInteger> fact;

    public static BigInteger factorial(int n) {
        if(fact.get(n).equals(BigInteger.valueOf(-1))) {
            if(n==0 || n==1)
                fact.set(n, BigInteger.valueOf(1));
            else fact.set(n, BigInteger.valueOf(n).multiply(factorial(n-1)));
        }
        return fact.get(n);
    }

    public static TreeMap<Integer, Integer> Counter(ArrayList<Integer> arr) {
        TreeMap<Integer, Integer> cnt = new TreeMap<>();
        for(Integer x: arr) {
            if(cnt.containsKey(x)) {
                cnt.put(x, cnt.get(x)+1);
            } else {
                cnt.put(x, 1);
            }
        }
        return cnt;
    }

    public static int gcd(int a, int b) {
        if(a>b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        if(a==0) return b;
        return gcd(b%a, a);
    }

    public static BigInteger count_cycles(ArrayList<Integer> c, int n) {
        BigInteger up = factorial(n);
        BigInteger down = BigInteger.valueOf(1);

        for(Map.Entry<Integer,Integer> e: Counter(c).entrySet()) {
            int num = e.getKey();
            int occurance = e.getValue();

            down = down.multiply(power(num, occurance));
            down = down.multiply(factorial(occurance));
        }
        return up.divide(down);
    }

    private static BigInteger power(int base, int pow) {
        if(pow==0) return BigInteger.valueOf(1);
        if(pow%2==1) return BigInteger.valueOf(base).multiply(power(base, pow-1));
        BigInteger rt = power(base, pow/2);
        return rt.multiply(rt);
    }

    private static BigInteger power(BigInteger base, BigInteger pow) {
        if(pow.equals(BigInteger.valueOf(0))) return BigInteger.valueOf(1);
        if(pow.mod(BigInteger.valueOf(2)).equals(BigInteger.valueOf(1))) {
            return base.multiply(power(base, pow.subtract(BigInteger.valueOf(1))));
        }
        BigInteger rt = power(base, pow.divide(BigInteger.valueOf(2)));
        return rt.multiply(rt);
    }

    private static ArrayList<ArrayList<Integer>> increasing_partitions(int n, int mnsize) {
        ArrayList<ArrayList<Integer>> parts = new ArrayList<>();
        if(mnsize*2>n) {
            ArrayList<Integer> ret  = new ArrayList<>();
            ret.add(n);
            parts.add(ret);
            return parts;
        }
        for(int i=mnsize; i<=n/2; i++) {
            for(ArrayList<Integer> suffix: increasing_partitions(n-i, i)) {
                ArrayList<Integer> arr = new ArrayList<>();
                arr.add(i);
                arr.addAll(suffix);
                parts.add(arr);
            }
        }
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(n);
        parts.add(arr);
        return parts;
    }

    public static String solution(int w, int h, int s) {
        fact = new ArrayList<>();
        for(int i=0; i<30; i++) {
            fact.add(BigInteger.valueOf(-1));
        }

        BigInteger W = new BigInteger(String.valueOf(w));
        BigInteger H = new BigInteger(String.valueOf(h));
        BigInteger S = new BigInteger(String.valueOf(s));

        BigInteger totalCombinations = BigInteger.valueOf(0);

        for(ArrayList<Integer> partition_width:increasing_partitions(w,1)) {
            for(ArrayList<Integer> partition_height: increasing_partitions(h,1)) {
                BigInteger m = count_cycles(partition_width, w).multiply(count_cycles(partition_height, h));
                BigInteger t2 = BigInteger.valueOf(0);
                for(int j: partition_height) {
                    for(int i: partition_width) {
                        t2 = t2.add(BigInteger.valueOf(gcd(i,j)));
                    }
                }
                BigInteger t1 = power(BigInteger.valueOf(s), t2);
                totalCombinations = totalCombinations.add( m.multiply(t1) );
            }
        }

        return totalCombinations.divide(factorial(w).multiply(factorial(h))).toString();
    }

//    public static void main(String[] args) {
//        System.out.println(solution(2,3,4));
////        System.out.println(factorial(4));
//    }
}