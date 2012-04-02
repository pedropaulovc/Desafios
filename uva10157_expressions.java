import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static final int MAX_N = 300, MAX_D = 150;
	static BigInteger[][] qtdExpressoes = new BigInteger[MAX_N + 1][MAX_D + 1];

	private static BigInteger calcularQtdExpressoes(int n, int d) {
		BigInteger resposta = BigInteger.ZERO;

		if (n < 0 || d < 0)
			return BigInteger.ZERO;
		if (n == 0 && d >= 0)
			return BigInteger.ONE;
		if (qtdExpressoes[n][d] != null)
			return qtdExpressoes[n][d];

		for (int i = 2; i <= n; i += 2) {
			resposta = resposta.add(calcularQtdExpressoes(i - 2, d - 1).multiply(
					calcularQtdExpressoes(n - i, d)));
		}

		qtdExpressoes[n][d] = resposta;
		return resposta;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		while (scanner.hasNext()) {
			int n = scanner.nextInt();
			int d = scanner.nextInt();

			System.out.println(calcularQtdExpressoes(n, d).subtract(
					calcularQtdExpressoes(n, d - 1)));
		}
	}
}

