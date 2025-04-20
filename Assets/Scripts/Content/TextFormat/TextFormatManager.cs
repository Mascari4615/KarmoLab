using UnityEngine;
using TMPro;
using UnityEngine.UI;
using System;
using System.Collections.Generic;

namespace KarmoLab
{
	public partial class TextFormatManager : ButtonContent
	{
		protected override Dictionary<int, (Delegate function, string functionName)> InitializeFunctionMap()
		{
			return new Dictionary<int, (Delegate function, string functionName)>
			{
				{ 1, ((FunctionWithMainInput)KakaoFormat, nameof(KakaoFormat)) },
			};
		}
	}
}