using System;
using System.IO;
using System.Text.RegularExpressions;

namespace CSharpPlayground
{
	public class KarmoRegax
	{
		public static void Func1(string path)
		{
			string folderPath = path;
			if (!Directory.Exists(folderPath))
			{
				Console.WriteLine("The provided folder path does not exist.");
				return;
			}

			string[] prefixes = { "Screenshot 20", "스크린샷 20" };
			DirectoryInfo directory = new DirectoryInfo(folderPath);
			FileInfo[] files = directory.GetFiles();

			foreach (FileInfo file in files)
			{
				bool isMatched = false;
				for (int i = 0; i < prefixes.Length; i++)
				{
					if (file.Name.StartsWith(prefixes[i]))
					{
						isMatched = true;
						break;
					}
				}

				if (isMatched)
				{
					// Screenshot 2024-05-14 192005
					// to
					// 240514_192005

					// Regular expression
					// ^Screenshot 20(\d{2})-(\d{2})-(\d{2}) (\d{6})$
					// $1$2$3_$4

					string[] parts = file.Name.Split(' ');
					string date = parts[1];
					string time = parts[2];

					// 2024-05-14 -> 240514
					date = date.Replace("-", "").Substring(2);

					string oldFileName = file.Name;
					string newFileName = $"{date}_{time}";
					string newFilePath = Path.Combine(folderPath, newFileName);
					file.MoveTo(newFilePath);
					Console.WriteLine($"Renamed: {oldFileName} -> {newFileName}");
				}
			}
		}

		public static void Func2(string path)
		{
			string folderPath = path;
			if (!Directory.Exists(folderPath))
			{
				Console.WriteLine("The provided folder path does not exist.");
				return;
			}

			string prefix = "VRChat_";
			DirectoryInfo directory = new DirectoryInfo(folderPath);
			FileInfo[] files = directory.GetFiles();

			foreach (FileInfo file in files)
			{
				if (file.Name.StartsWith(prefix))
				{
					// VRChat_2024-11-04_19-09-40.662_1920x1080
					// to
					// 241104_190940.png

					// Regular expression
					// ^VRChat_(\d{4})-(\d{2})-(\d{2})_(\d{2})-(\d{2})-(\d{2})\.\d{3}_\d+x\d+$
					// $1$2$3_$4$5$6.png

					string[] parts = file.Name.Split('_', '.');
					string date = parts[1];
					string time = parts[2];

					// 2024-11-04 -> 241104
					date = date.Replace("-", "").Substring(2);

					// 19-09-40 -> 190940
					time = time.Replace("-", "");

					string newFileName = $"{date}_{time}.png";
					string newFilePath = Path.Combine(folderPath, newFileName);
					file.MoveTo(newFilePath);
					Console.WriteLine($"Renamed: {file.Name} -> {newFileName}");
				}
			}
		}

		public static void Func3(string path, string removeString = "-")
		{
			string folderPath = path;
			if (!Directory.Exists(folderPath))
			{
				Console.WriteLine("The provided folder path does not exist.");
				return;
			}

			string prefix = "";
			DirectoryInfo directory = new DirectoryInfo(folderPath);
			FileInfo[] files = directory.GetFiles();

			foreach (FileInfo file in files)
			{
				if (file.Name.StartsWith(prefix))
				{
					// 확장자랑 분리
					string[] parts = file.Name.Split('.');
					string fileName = parts[0];
					string extension = parts[1];

					string newFileName = fileName.Replace(removeString, "");
					string newFilePath = Path.Combine(folderPath, newFileName);
					file.MoveTo(newFilePath);
					Console.WriteLine($"Renamed: {file.Name} -> {newFileName}");
				}
			}
		}

		public static void Func4(string path)
		{
			// 앞 2자리 제거
			string folderPath = path;
			if (!Directory.Exists(folderPath))
			{
				Console.WriteLine("The provided folder path does not exist.");
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
					Console.WriteLine($"Renamed: {file.Name} -> {newFileName}");
				}
			}
		}

		// 경로 내 파일들의 이름을 포맷에 맞게 출력하는 함수
		public static void Func5(string path)
		{
			// 앞 2자리 제거
			string folderPath = path;
			if (!Directory.Exists(folderPath))
			{
				Console.WriteLine("The provided folder path does not exist.");
				return;
			}

			DirectoryInfo directory = new DirectoryInfo(folderPath);
			FileInfo[] files = directory.GetFiles();

			foreach (FileInfo file in files)
			{
				// 확장자 없는 이름
				string fileName = Path.GetFileNameWithoutExtension(file.Name);
				Console.WriteLine($"![{fileName}](SOMEPATH/{file.Name})");
			}
		}

		//

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
					// Console.WriteLine(match.Value);

					// foreach (Group group in match.Groups)
					{
						// Console.WriteLine(group.Value);
					}

					string newLine = action(match);
					Console.WriteLine(newLine);

					// lines[i] = action(match);
				}
			}

			// 4. 수정된 라인을 파일에 저장
			// File.WriteAllLines(filePath, lines);

			Console.WriteLine("Done");
		}
	}
}