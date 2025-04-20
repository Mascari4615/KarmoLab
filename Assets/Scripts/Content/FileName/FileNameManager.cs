using UnityEngine;
using TMPro;
using UnityEngine.UI;
using System;
using System.Collections.Generic;

namespace KarmoLab
{
	public partial class FileNameManager : ButtonContent
	{
		private const string TEMP_PATH = "TEMP_PATH";

		protected override Dictionary<int, (Delegate function, string functionName)> InitializeFunctionMap()
		{
			return new Dictionary<int, (Delegate function, string functionName)>
			{
				{ 1, ((FunctionWithMainInput)ChangeWinScreenshotName, nameof(ChangeWinScreenshotName)) },
				{ 2, ((FunctionWithMainInput)ChangeVRCScreenshotName, nameof(ChangeVRCScreenshotName)) },
				{ 3, ((FunctionWithTwoInputs)RemoveSomeString, nameof(RemoveSomeString)) },
				{ 4, ((FunctionWithMainInput)KarmoRegex.Func4, nameof(KarmoRegex.Func4)) },
				{ 5, ((FunctionWithTwoInputs)FileNameToString, nameof(FileNameToString)) },
				{ 6, ((FunctionWithTwoInputs)ChangeNameToDate, nameof(ChangeNameToDate)) },
			};
		}
	}
}