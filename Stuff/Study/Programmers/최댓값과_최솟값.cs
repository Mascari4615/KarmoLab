using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
	public string solution(string s)
	{
		List<int> ss = s.Split(' ').Select(x => int.Parse(x)).ToList();
		return $"{ss.Min()} {ss.Max()}";
	}

	// List<int> ss = s.Split(' ').Select(int.Parse).ToList(); 
	// �̷��Ե� �� �� �ֱ���

	// Sort �⺻ �� �����ڰ� ����..?
	// Min Max �ִ� 2n �ε� ��ͺ��� ��������
	// �����ٸ� Sort �ϰ� First Last ���ٵ�

	// ��� ǥ������� 'log N'�� ���α׸� ���ϴ� �� �ƴ϶�, ���� ����ǰ� ����� ������ �����صаű���
	// ��� ǥ����� ���� ����Ÿ���� �ƴ϶�
	// ����ؼ� ������ ��(n)�� �����Կ� ���� ����Ÿ�� �������� ǥ���ϱ� ���� �� (�־��� ��츦 �����ϴ� ��)
	// ���� ����Ÿ�Ӱ� �ٸ� �� �ִٴ� �� �ٽ� �����ؾ߰ڴ�

	// int.Parse �Լ��� - + ��ȣ�� ó���ϴ±���
}