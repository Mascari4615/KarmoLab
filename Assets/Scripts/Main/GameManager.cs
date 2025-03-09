using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace KarmoLab
{
	[DefaultExecutionOrder(-900)]
	public class GameManager : MonoBehaviour
	{
		[SerializeField] private List<Button> buttons;
		private List<Content> contents = new();
		private Content currentContent = null;

		private void Awake()
		{
			Init();
		}

		private void Init()
		{
			InitializeContents();
		}

		public void InitializeContents()
		{
			contents = transform.GetComponentsInChildren<Content>(true).ToList();

			foreach (Content content in contents)
			{
				content.Init();
			}

			for (int i = 0; i < buttons.Count; i++)
			{
				if (i >= contents.Count)
				{
					buttons[i].gameObject.SetActive(false);
					continue;
				}

				MLog.Log($"Button {i} is set to {contents[i].name}");
				
				int index = i;
				buttons[i].onClick.AddListener(() =>
				{
					SetContent(contents[index]);
				});

				TextMeshProUGUI buttonText = buttons[i].GetComponentInChildren<TextMeshProUGUI>();
				buttonText.text = contents[i].name;
			}
		}

		private void SetContent(Content content)
		{
			currentContent?.Hide();
			currentContent = content;
			currentContent.Show();
		}
	}
}