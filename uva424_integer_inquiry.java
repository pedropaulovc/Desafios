import java.math.BigInteger;
import java.util.Scanner;

public class Uva424IntegerInquiry {
	public static void main_424(String[] args) {
		Scanner scanner = new Scanner(System.in);
		BigInteger num = new BigInteger("0");

		String linha = scanner.nextLine();
		while (!linha.equals("0")) {
			num = num.add(new BigInteger(linha));
			linha = scanner.nextLine();
		}
		
		System.out.println(num);
	}
}
