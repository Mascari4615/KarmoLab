using System;
using System.Collections.Generic;
using System.Collections;

public class Solution
{
	public string solution(string s)
	{
		// return s[ .. ].ToString();
		// �� ������ ���� 8 ���� ���� (������ ������ ������ 6)

		return (s.Length % 2 == 1)
			? s.Substring(s.Length / 2, 1)
			: s.Substring(s.Length / 2 - 1, 2);
	}
}