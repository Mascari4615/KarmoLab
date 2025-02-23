using TMPro;
using UnityEngine;

public class MLog : Singleton<MLog>
{
	private static TMP_InputField inputFieldLog;
	private static TextMeshProUGUI textLog;

	public static void Log(string log)
	{
		Debug.Log(log);

		if (inputFieldLog == null)
			inputFieldLog = GameObject.Find("[InputField] Log").GetComponent<TMP_InputField>();
		inputFieldLog.text += log + "\n";

		if (textLog == null)
			textLog = GameObject.Find("[Text] Log").GetComponent<TextMeshProUGUI>();
		textLog.text += log + "\n";
	}
}
