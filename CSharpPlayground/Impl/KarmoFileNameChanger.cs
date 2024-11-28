using System;
using System.IO;

namespace CSharpPlayground
{
	public class KarmoFileNameChanger
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
	}
}