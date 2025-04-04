using UnityEngine;
using System;
using System.IO;
using System.Text.RegularExpressions;

namespace KarmoLab
{
public partial class FileNameManager : Content
{
	private static void ChangeWinScreenshotName(string path)
	{
		MLog.Log($"{nameof(ChangeWinScreenshotName)} is called.");
		MLog.Log($"Path: {path}");

		string folderPath = path;
		if (!Directory.Exists(folderPath))
		{
			MLog.Log("The provided folder path does not exist.");
			return;
		}

		string[] prefixes = { "Screenshot 20", "스크린샷 20" };
		DirectoryInfo directory = new DirectoryInfo(folderPath);
		FileInfo[] files = directory.GetFiles();

		if (files.Length == 0)
		{
			MLog.Log("No files found.");
			return;
		}

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
				
				try
				{
					file.MoveTo(newFilePath);
				}
				catch (Exception e)
				{
					MLog.Log($"Failed to rename: {file.Name} -> {newFileName}");
					MLog.Log(e.Message);

					// 이미 존재하는 파일이 있을 경우
					// 파일 이름 뒤에 _1을 붙여서 다시 시도

					string newName = FileNameUtil.GetNewFileName(folderPath, newFileName, 1);
					newFilePath = Path.Combine(folderPath, newName);
					file.MoveTo(newFilePath);
				}

				MLog.Log($"Renamed: {oldFileName} -> {newFileName}");
			}
		}
	}
}
}