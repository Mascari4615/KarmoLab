using UnityEngine;
using System;
using System.Collections.Generic;
using System.IO;

namespace KarmoLab
{
	public static class FileNameUtil
	{
		public static string GetNewFileName(string folderPath, string targetName, string extension, int subIndex)
		{
			if (File.Exists(Path.Combine(folderPath, $"{targetName}_{subIndex}{extension}")))
			{
				return GetNewFileName(folderPath, targetName, extension, subIndex + 1);
			}
			string leading2SubIndex = subIndex.ToString().PadLeft(2, '0');
			string newFileName = $"{targetName}_{leading2SubIndex}";
			return newFileName;
		}
	}
}