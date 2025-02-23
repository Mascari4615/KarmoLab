using System;
using System.Text;

public class Solution
{
	public string solution(string s)
	{
		StringBuilder sb = new StringBuilder(s);
		int wordStartIndex = 0;
		for (int i = 0; i < s.Length; i++)
		{
			if (s[i] == ' ')
				wordStartIndex = i + 1;
			else
				sb[i] = (i - wordStartIndex) % 2 == 0 ? char.ToUpper(sb[i]) : char.ToLower(sb[i]);

			/*
			 * ¦�� �빮��, Ȧ�� �ҹ���
			 * 65 �빮��, 97 �ҹ���
			 * 
			 * ToUpper ToLower ���縦 ���� �Ʒ��� Ǯ������
			 * 
			 * sb[i] = (char)(sb[i] + ((i - wordStartIndex) % 2 == 0
			 * ? sb[i] >= 97 ? -32 : 0 
			 * : sb[i] >= 97 ? 0 : 32));
			 */
		}
		return sb.ToString();
	}
}