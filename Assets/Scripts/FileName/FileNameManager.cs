using UnityEngine;
using TMPro;
using UnityEngine.UI;

public partial class FileNameManager : MonoBehaviour
{
	[SerializeField] private TMP_InputField inputFieldMain;
	[SerializeField] private TMP_InputField inputFieldSub;

	[SerializeField] private TMP_InputField inputFieldOutput;

	[SerializeField] private Button[] buttons;

	private void Start()
	{
		Init();
	}

	private void Init()
	{
		for (int i = 0; i < buttons.Length; i++)
		{
			int num = i + 1;
			buttons[i].onClick.AddListener(() =>
			{
				SomeFunc(num);
			});
		}
	}

	public void SomeFunc(int num)
	{
		MLog.Log($"Function {num} is called.");

		switch (num)
		{
			case 1:
				ChangeWinScreenshotName(inputFieldMain.text);
				break;
			case 2:
				ChangeVRCScreenshotName(inputFieldMain.text);
				break;
			case 3:
				RemoveSomeString(inputFieldMain.text, inputFieldSub.text);
				break;
			case 4:
				KarmoRegax.Func4(inputFieldMain.text);
				break;
			case 5:
				FileNameToString(inputFieldMain.text);
				break;
			default:
				MLog.Log("Invalid function number.");
				break;
		}
	}

	public void OutputResult(string result)
	{
		MLog.Log(result);
		inputFieldOutput.text = result;
	}
}
