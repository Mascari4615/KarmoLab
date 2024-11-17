using System;
using System.IO;

namespace CSharpPlayground
{
	class KarmoFileNameChanger
	{
		static void Main(string[] args)
		{
			if (args.Length == 0)
			{
				Console.WriteLine("Please provide a folder path.");
				return;
			}

			switch (args[0])
			{
				case "1":
					Func1(args[1]);
					break;
				case "2":
					Func2(args[1]);
					break;
				case "3":
					Func3(args[1]);
					break;
				default:
					Console.WriteLine("Invalid function number.");
					break;
			}
		}

		private static void Func1(string path)
		{
			string folderPath = path;
			if (!Directory.Exists(folderPath))
			{
				Console.WriteLine("The provided folder path does not exist.");
				return;
			}

			string prefix = "스크린샷_20";
			DirectoryInfo directory = new DirectoryInfo(folderPath);
			FileInfo[] files = directory.GetFiles();

			foreach (FileInfo file in files)
			{
				if (file.Name.StartsWith(prefix))
				{
					string newFileName = file.Name.Substring(prefix.Length);
					string newFilePath = Path.Combine(folderPath, newFileName);
					file.MoveTo(newFilePath);
					Console.WriteLine($"Renamed: {file.Name} -> {newFileName}");
				}
			}

			Console.WriteLine("File renaming completed.");
		}

		private static void Func2(string path)
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
					string newFileName = $"{date.Replace("-", "")}_{time.Replace("-", "")}.png";
					string newFilePath = Path.Combine(folderPath, newFileName);
					file.MoveTo(newFilePath);
					Console.WriteLine($"Renamed: {file.Name} -> {newFileName}");
				}
			}
		}

		private static void Func3(string path)
		{
			// remove '-' from the file name

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
					string newFileName = file.Name.Replace("-", "");
					string newFilePath = Path.Combine(folderPath, newFileName);
					file.MoveTo(newFilePath);
					Console.WriteLine($"Renamed: {file.Name} -> {newFileName}");
				}
			}
		}
	}
}