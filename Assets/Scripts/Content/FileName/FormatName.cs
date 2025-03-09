using System;
using System.IO;
using System.Text.RegularExpressions;
using UnityEngine;

namespace KarmoLab
{
	public class KarmoRegax
	{
		public static void Func4(string path)
		{
			// 앞 2자리 제거
			string folderPath = path;
			if (!Directory.Exists(folderPath))
			{
				MLog.Log("The provided folder path does not exist.");
				return;
			}

			string prefix = "2023";
			DirectoryInfo directory = new DirectoryInfo(folderPath);
			FileInfo[] files = directory.GetFiles();

			foreach (FileInfo file in files)
			{
				if (file.Name.StartsWith(prefix))
				{
					string newFileName = file.Name.Substring(2);
					string newFilePath = Path.Combine(folderPath, newFileName);
					file.MoveTo(newFilePath);
					MLog.Log($"Renamed: {file.Name} -> {newFileName}");
				}
			}
		}

		public static void Main_KarmoRegex()
		{
			Regex(
				// @"C:\Users\masca\source\repos\Mascari4615.github.io\_posts\Stone\Life\2024-09-25-Like.md",
				@"C:\Users\masca\source\repos\Mascari4615.github.io\_posts\Stone\Life\2024-07-13-Music.md",
				 // @"- \[https://x\.com/[a-zA-Z0-9_]+/status/\d+\]",
				 // @"- \[.*?\]\(https:\/\/x\.com\/[a-zA-Z0-9_]+\/status\/\d+\)",
				 @"""videoId"":\s*""([^""]+)""",
				(Match match) =>
				{
					// string newLine = match.Replace("- [", "");
					// newLine = newLine.Replace("]", "");
					// return newLine;

					return match.Groups[1].Value;
				});
		}

		// @"\[김도윤\] \[(오전|오후) \d{1,2}:\d{2}\]"

		// // 3. 찾은 라인 수정
		// // 예시 1 "[김도윤] [오전 8:07]" 를 -> "오전 8:07 -" 로 변경
		// // 예시 2 '[김도윤] [오후 18:07]' 를 -> '오후 18:07 -' 로 변경

		// string newLine = match.Value.Replace("[김도윤] ", "");

		// // 대괄호 제거
		// newLine = newLine.Replace("[", "");
		// newLine = newLine.Replace("]", "");

		// // 뒤에 - 추가
		// newLine += " -";

		// // 라인 수정
		// lines[i] = regex.Replace(lines[i], newLine);

		public static void Regex(string filePath, string pattern, Func<Match, string> action)
		{
			// 텍스트 파일을 읽어서, 특정 정규식이 포함된 라인을 찾고, 해당 라인을 수정해서 저장하는 예제

			// 1. 텍스트 파일 읽기
			string[] lines = File.ReadAllLines(filePath);

			// 2. 정규식을 이용한 라인 찾기
			Regex regex = new Regex(pattern);

			for (int i = 0; i < lines.Length; i++)
			{
				Match match = regex.Match(lines[i]);
				if (match.Success)
				{
					// MLog.Log(match.Value);

					// foreach (Group group in match.Groups)
					{
						// MLog.Log(group.Value);
					}

					string newLine = action(match);
					MLog.Log(newLine);

					// lines[i] = action(match);
				}
			}

			// 4. 수정된 라인을 파일에 저장
			// File.WriteAllLines(filePath, lines);

			MLog.Log("Done");
		}
	}
}