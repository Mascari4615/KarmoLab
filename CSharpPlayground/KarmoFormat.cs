using System;
using System.IO;
using System.Text.RegularExpressions;

public class KarmoFormat
{
	public static void Main()
	// public static void Main_KarmoFormat()
	{
		Console.WriteLine(NoSpace(@"ㅁ	ㅋ	ㄹ	ㅁ	ㅇ	ㅊ	ㄷ	ㅇ
ㅂ	ㄲ	ㅈ	ㅂ	ㄱ	ㄷ	ㅈ	ㅇ
ㅁ	ㄹ	ㅇ	ㅂ	ㅎ	ㅇ	ㅅ	ㄱ
ㅊ	ㄱ	ㅇ	ㄲ	ㄴ	ㄹ	ㅎ	ㅂ
ㄱ	ㅌ	ㅅ	ㄱ	ㅊ	ㅎ	ㅈ	ㅅ
ㄸ	ㅂ	ㅋ	ㄷ	ㅋ	ㅌ	ㅊ	ㄹ
ㄹ	ㅇ	ㄹ	ㄱ	ㅇ	ㄱ	ㅍ	ㅇ
ㅁ	ㅈ	ㅅ	ㄹ	ㅇ	ㅎ	ㅊ	ㅍ"));
	}

	public static string NoSpace(string s)
	{
		return s.Replace(" ", "").Replace("\t", "").Replace("\n", "").Replace("\r", "");
	}
}