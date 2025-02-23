using System;
using System.Collections.Generic;

public class Solution
{
	public long solution(long n)
	{
		long answer = 0;
		List<int> list = new List<int>();
		for (long i = n; i != 0; i /= 10)
			list.Add((int)(i % 10));
		list.Sort();
		for (int i = 0; i < list.Count; i++)
			answer += list[i] * (long)Math.Pow(10, i);

		return answer;
	}

	// �ٸ� �е� Ǯ�̸� ���� �Ʒ�ó�� Ǫ�ô���

	// n -> string -> char[]
	// System.Array.Sort()
	// System.Array.Reverse()
	// System.Convert.ToInt64(new string());
}