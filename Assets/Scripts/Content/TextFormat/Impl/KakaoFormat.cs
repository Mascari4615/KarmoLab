using System;
using System.IO;
using System.Text;
using UnityEngine;

namespace KarmoLab
{
	public partial class TextFormatManager : Content
	{
		// KakaoTalk 대화 Text를 내가 원하는 Format으로
		public void KakaoFormat(string filePath)
		{
			MLog.Log($"{nameof(KakaoFormat)} is called.");
			MLog.Log($"Path: {filePath}");

			if (File.Exists(filePath) == false)
			{
				MLog.Log("The provided file path does not exist.");
				return;
			}

			string folderPath = Path.GetDirectoryName(filePath);
			string fileName = Path.GetFileNameWithoutExtension(filePath);
			string fileExtension = Path.GetExtension(filePath);
			string newFilePath = Path.Combine(folderPath, $"{fileName}_formatted{fileExtension}");

			StringBuilder formattedText = new();
			string[] lines = File.ReadAllLines(filePath);
			
			// 앞에 4줄은 제외
			lines = lines[4..];

			foreach (string line in lines)
			{
				// 라인이 비어있거나 공백으로만 이루어진 경우는 건너뜁니다.
				if (string.IsNullOrWhiteSpace(line))
				{
					continue;
				}

				// 첫 번째 ','를 기준으로 나눕니다.
				string[] parts = line.Split(new[] { ',' }, 2);

				bool isChatBeginningBlock = (parts.Length == 2) && parts[0].Contains("202");
				// timePart가 '202@년'를 포함하는지 확인,
				// 대화 내용 중 줄바꿈한 Line에 쉼표가 들어간 경우도 있어서.
				if (isChatBeginningBlock)
				{
					string time = string.Empty;
					{
						// 2025년 3월 26일 오후 12:27
						// ->
						// - 12:27

						string timePart = parts[0].Trim();
						string[] timeParts = timePart.Split(" ");

						if (timeParts.Length == 5)
						{
							// 오전/오후를 12시간제로 변환
							if (timeParts[^2] == "오후")
							{
								int hour = int.Parse(timeParts[^1].Split(':')[0]);
								if (hour != 12)
								{
									hour += 12; // 오후는 12를 더합니다.
								}
								time = $"{hour}:{timeParts[^1].Split(':')[1]}";
							}
							else if (timeParts[^2] == "오전")
							{
								int hour = int.Parse(timeParts[^1].Split(':')[0]);
								if (hour == 12)
								{
									hour = 0; // 오전 12시는 자정이므로 0으로 설정합니다.
								}
								time = $"{hour}:{timeParts[^1].Split(':')[1]}";
							}
							else
							{
								MLog.Log($"Invalid time format: {parts[0]}");
								time = $"{parts[0]}"; // Fallback to original time string
							}
						}
						else
						{
							MLog.Log($"Invalid time format: {parts[0]}");
							time = $"- {parts[0]}"; // Fallback to original time string
						}
					}

					string message = parts[1].Trim();
					{
						//  김도윤 : 아름드리
						// ->
						// 아름드리

						// ':'가 있는 경우, ':' 이후의 내용을 가져옵니다.
						int colonIndex = message.IndexOf(':');
						message = message[(colonIndex + 1)..].Trim(); // ':' 이후의 내용을 가져옵니다.
					}

					formattedText.AppendLine($"- {time} {message}");
				}
				else
				{
					// ':'가 없는 경우, 원본 라인을 그대로 추가합니다.
					formattedText.AppendLine(line.Trim());
				}
			}

			File.WriteAllText(newFilePath, formattedText.ToString());
			MLog.Log("Formatted text has been saved.");
		}
	}
}