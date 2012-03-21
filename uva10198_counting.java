import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static BigInteger[] maneiras = new BigInteger[1001];

	public static BigInteger calcularManeiras(int num){
		if(num < 0)
			return BigInteger.ZERO;
		if(maneiras[num] != null)
			return maneiras[num];
		
		BigInteger total = BigInteger.ZERO;
		total = total.add(Main.calcularManeiras(num - 1));
		total = total.add(Main.calcularManeiras(num - 1));
		total = total.add(Main.calcularManeiras(num - 2));
		total = total.add(Main.calcularManeiras(num - 3));
		
		maneiras[num] = total;
		
		return total;
	}	
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int num;

		maneiras[0] = BigInteger.ZERO;
		maneiras[1] = new BigInteger("2");
		maneiras[2] = new BigInteger("5");
		maneiras[3] = new BigInteger("13");
		while (scanner.hasNextInt()) {
			num = scanner.nextInt();
			System.out.println(Main.calcularManeiras(num));
		}
	}
}
