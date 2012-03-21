import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static BigInteger calculaQtdFibonacci(BigInteger a, BigInteger b){
		BigInteger f1 = BigInteger.ONE;
		BigInteger f2 = BigInteger.ONE;
		BigInteger tmp, qtd = BigInteger.ZERO;
		
		while(f2.compareTo(a) < 0){
			tmp = f1.add(f2);
			f1 = f2;
			f2 = tmp;
		}

		while(f2.compareTo(b) <= 0){
			tmp = f1.add(f2);
			f1 = f2;
			f2 = tmp;
			qtd = qtd.add(BigInteger.ONE);
		}

		return qtd;
	}


	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		BigInteger a, b;
		
		a = scanner.nextBigInteger();
		b = scanner.nextBigInteger();
		while (a.compareTo(BigInteger.ZERO) != 0 || b.compareTo(BigInteger.ZERO) != 0) {
			System.out.println(calculaQtdFibonacci(a, b));
			
			a = scanner.nextBigInteger();
			b = scanner.nextBigInteger();
		}
	}
}
