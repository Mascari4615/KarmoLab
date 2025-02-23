namespace CSharpPlayground
{
	// dotnet run
	public class KarmoPlayground
	{
		public static void Main(string[] args)
		{
			if (args.Length == 0)
			{
				Console.WriteLine("Please provide a folder path.");
				return;
			}

			string key = args[0];
			switch (key)
			{
				case "1":
					KarmoRegax.Func1(args[1]);
					break;
				case "2":
					KarmoRegax.Func2(args[1]);
					break;
				case "3":
					KarmoRegax.Func3(args[2], args[1]);
					break;
				case "4":
					KarmoRegax.Func4(args[1]);
					break;
				case "5":
					KarmoRegax.Func5(args[1]);
					break;
				case "6":
					YoutubePlaylistDataRegex.Regex(args[1]);
					break;
				default:
					Console.WriteLine("Invalid function number.");
					break;
			}
		}
	}
}