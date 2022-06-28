import java.util.*;
public class Program7_1 
{
    // 입력받을 정보 수, 확장성을 위해
	public static final int INPUT_COUNT = 10;
	public static void main(String[] args) 
	{
        // float 보다 정확한 계산을 위해 double 사용
		Vector<Double> heights = new Vector<Double>(INPUT_COUNT);
		Vector<Double> weights = new Vector<Double>(INPUT_COUNT);
		Scanner s = new Scanner(System.in);

		System.out.print("2000~" + (2000 + INPUT_COUNT - 1) + "년까지 1년 단위로 키 (cm)를 입력\n>>");
		for (int i = 0; i < INPUT_COUNT; i++)
		{
			heights.add(s.nextDouble());
		}
		System.out.print("2000~" + (2000 + INPUT_COUNT - 1) + "년까지 1년 단위로 몸무게 (kg)를 입력\n>>");
		for (int i = 0; i < INPUT_COUNT; i++)
		{
			weights.add(s.nextDouble());
		}

		int biggestBMIIndex = 0;
		double biggestBMI = 0;
		for (int i = 0; i < INPUT_COUNT; i++)
		{
            // 입력을 Cm 로 받았기 때문에 M 로 변환
            double cmToMeter = heights.get(i) / 100.0;
			if (biggestBMI < weights.get(i) / (cmToMeter * cmToMeter))
            {
                biggestBMI = weights.get(i) / (cmToMeter * cmToMeter);
                biggestBMIIndex = i;
            }
		}
		System.out.print("가장 BMI가 큰 년도는 " + (2000 + biggestBMIIndex) + "년 " + (Math.round(biggestBMI * 10) / 10.0));
        s.close();
	}
}
