using UnityEngine;
using System;
using System.Collections.Generic;
using System.IO;

namespace KarmoLab
{
	public static class FileNameUtil
	{
		public static string GetNewFileName(string folderPath, string targetName, int subIndex)
		{
			string newFileName = $"{targetName}_{subIndex}.png";
			if (File.Exists(Path.Combine(folderPath, newFileName)))
			{
				return GetNewFileName(folderPath, targetName, subIndex + 1);
			}
			return newFileName;
		}
	}
}