using System;
using System.IO;
using System.Text.RegularExpressions;

namespace CSharpPlayground
{
	public class YoutubePlaylistDataRegex
	{
		public static void Regex(string filePath)
		{
			// 텍스트 파일을 읽어서, 특정 정규식이 포함된 라인을 찾고, 해당 라인을 수정해서 저장하는 예제

			// 1. 텍스트 파일 읽기
			string[] lines = File.ReadAllLines(filePath);

			// 2. 정규식을 이용한 라인 찾기
			Regex titleRegex = new Regex(@"""title"": ""([^""]*)""");
			Regex videoIdRegex = new Regex(@"""videoId"":\s*""([^""]+)""");

			for (int i = 0; i < lines.Length; i++)
			{
				Match titleMatch = titleRegex.Match(lines[i]);
				Match videoIdMatch = videoIdRegex.Match(lines[i]);

				if (titleMatch.Success)
				{
					Console.Write($"- [{titleMatch.Groups[1].Value}]");
				}

				if (videoIdMatch.Success)
				{
					Console.Write($"(https://youtu.be/{videoIdMatch.Groups[1].Value})\n");
				}
			}

			Console.WriteLine("Done");
		}
	}
}