using UnityEngine;
using TMPro;
using UnityEngine.UI;
using System;
using System.Collections.Generic;

namespace KarmoLab
{
	public partial class TextFormatManager : Content
	{
		private const string TEMP_PATH = "TEMP_PATH";

		[SerializeField] private TMP_InputField inputFieldMain;
		[SerializeField] private TMP_InputField inputFieldSub;
		[SerializeField] private TMP_InputField inputFieldOutput;
		[SerializeField] private Button[] buttons;

		// 함수 타입 정의
		private delegate void FunctionWithMainInput(string input);
		private delegate void FunctionWithTwoInputs(string mainInput, string subInput);

		// 함수와 이름을 저장할 딕셔너리
		private Dictionary<int, (Delegate function, string functionName)> functionMap;

		public override void Init()
		{
			InitializeFunctionMap();

			for (int i = 0; i < buttons.Length; i++)
			{
				int num = i + 1;
				SetFunc(buttons[i], num);
			}
		}

		public override void Show()
		{
			gameObject.SetActive(true);
		}

		public override void Hide()
		{
			gameObject.SetActive(false);
		}

		private void InitializeFunctionMap()
		{
			functionMap = new Dictionary<int, (Delegate function, string functionName)>
			{
				{ 1, ((FunctionWithMainInput)KakaoFormat, nameof(KakaoFormat)) },
			};
		}

		public void SetFunc(Button button, int num)
		{
			string functionName = "NULL";

			if (functionMap.TryGetValue(num, out var functionInfo))
			{
				functionName = functionInfo.functionName;

				if (functionInfo.function is FunctionWithMainInput mainInputFunc)
				{
					button.onClick.AddListener(() =>
					{
						MLog.Log($"Function {num} ({functionName}) is called.");
						mainInputFunc(inputFieldMain.text);
					});
				}
				else if (functionInfo.function is FunctionWithTwoInputs twoInputsFunc)
				{
					button.onClick.AddListener(() =>
					{
						MLog.Log($"Function {num} ({functionName}) is called.");
						string subString = string.IsNullOrEmpty(inputFieldSub.text) ? TEMP_PATH : inputFieldSub.text;
						twoInputsFunc(inputFieldMain.text, subString);
					});
				}
			}
			else
			{
				MLog.Log("Invalid function number.");
			}

			TextMeshProUGUI buttonText = button.GetComponentInChildren<TextMeshProUGUI>();
			buttonText.text = functionName;
		}

		public void OutputResult(string result)
		{
			MLog.Log(result);
			inputFieldOutput.text = result;
		}
	}
}