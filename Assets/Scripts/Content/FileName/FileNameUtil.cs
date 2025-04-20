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

		public static bool FileNameStartsWith(FileInfo fileInfo, List<string> prefixes)
		{
			if ((prefixes == null) || (prefixes.Count == 0))
			{
				return true; // No prefixes provided, consider it a match
			}

			foreach (string prefix in prefixes)
			{
				if (string.IsNullOrEmpty(prefix) || (prefix == FileNameManager.TEMP_PATH))
				{
					continue; // Skip empty prefixes
				}

				if (fileInfo.Name.StartsWith(prefix))
				{
					return true; // Match found
				}
			}
			return false; // No match found
		}
	}
}