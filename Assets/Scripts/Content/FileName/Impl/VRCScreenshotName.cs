using UnityEngine;
using System;
using System.IO;
using System.Text.RegularExpressions;

namespace KarmoLab
{
	public partial class FileNameManager : Content
	{
		private static void ChangeVRCScreenshotName(string path)
		{
			MLog.Log($"{nameof(ChangeVRCScreenshotName)} is called.");
			MLog.Log($"Path: {path}");

			string folderPath = path;
			if (!Directory.Exists(folderPath))
			{
				MLog.Log("The provided folder path does not exist.");
				return;
			}

			string prefix = "VRChat_";
			DirectoryInfo directory = new DirectoryInfo(folderPath);
			FileInfo[] files = directory.GetFiles();

			if (files.Length == 0)
			{
				MLog.Log("No files found.");
				return;
			}

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
					MLog.Log($"Renamed: {file.Name} -> {newFileName}");
				}
			}
		}
	}
}