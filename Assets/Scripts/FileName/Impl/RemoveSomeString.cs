using System;
using System.IO;
using System.Text.RegularExpressions;
using UnityEngine;

public partial class FileNameManager : MonoBehaviour
{
	public void RemoveSomeString(string path, string removeString = "-")
	{
		MLog.Log($"{nameof(RemoveSomeString)} is called.");
		MLog.Log($"Path: {path}");
		MLog.Log($"Remove String: {removeString}");

		string folderPath = path;
		if (!Directory.Exists(folderPath))
		{
			MLog.Log("The provided folder path does not exist.");
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
				MLog.Log($"Renamed: {file.Name} -> {newFileName}");
			}
		}
	}
}