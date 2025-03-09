using System;
using System.IO;
using System.Text;
using UnityEngine;

namespace KarmoLab
{
	public partial class FileNameManager : Content
	{
		// 경로 내 파일들의 이름을 포맷에 맞게 출력하는 함수
		public void FileNameToString(string path)
		{
			MLog.Log($"{nameof(FileNameToString)} is called.");
			MLog.Log($"Path: {path}");

			string folderPath = path;
			if (!Directory.Exists(folderPath))
			{
				MLog.Log("The provided folder path does not exist.");
				return;
			}

			DirectoryInfo directory = new(folderPath);
			FileInfo[] files = directory.GetFiles();

			StringBuilder sb = new();

			foreach (FileInfo file in files)
			{
				// 확장자 없는 이름
				string fileName = Path.GetFileNameWithoutExtension(file.Name);
				string result = $"![{fileName}](SOMEPATH/{file.Name})";
				sb.AppendLine(result);
			}

			OutputResult(sb.ToString());
		}
	}
}