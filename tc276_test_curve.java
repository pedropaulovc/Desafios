import java.lang.Math.*;

public class TestCurve {
	public int[]  determineGrades(int[] scores){
		int max = scores[0];
		int min = scores[0];
	
		
		int len = scores.length;
		
		for(int i = 0; i < len; i++){
			if(scores[i] > max)
				max = scores[i];
			if(scores[i] < min)
				min = scores[i];
		}
		
		int coef = 100/max;
			
		for(int i = 0; i < len; i++){
			scores[i] = scores[i] * coef;
		}
		
		return scores;
		
	}

}
