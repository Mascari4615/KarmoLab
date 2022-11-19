using System;
using System.Windows.Forms;
using System.Threading;
using OpenQA.Selenium;
using OpenQA.Selenium.Edge;

namespace WebCrawler
{
    public partial class Form1 : Form
    {
        private EdgeDriverService _driverService;
		private EdgeOptions _options;
		private EdgeDriver _driver;

        private string newPostNumber;
        private string lastPostNumber;

        public Form1()
        {
            InitializeComponent();

            _driverService = EdgeDriverService.CreateDefaultService();
            _driverService.HideCommandPromptWindow = false;
            _options = new EdgeOptions();
			_options.UseChromium = true;
            _driver = new EdgeDriver(_driverService, _options);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            newPostNumber = "0";
            lastPostNumber = "1733";

            while (true)
            {
                for (int pageNumber = 4; pageNumber <= 50; pageNumber++)
                {
                    _driver.Navigate().GoToUrl($"https://gall.dcinside.com/mgallery/board/lists/?id=game_dev&page={pageNumber}");

                    for (int i = pageNumber == 4 ? 28 : 2; i <= 51; i++)
                    {
                        string curPostNumber = _driver.FindElement(By.XPath($"//*[@id='container']/section[1]/article[2]/div[2]/table/tbody/tr[{i}]/td[1]")).Text;
                        if (int.Parse(curPostNumber) > int.Parse(lastPostNumber) && int.Parse(curPostNumber) > int.Parse(newPostNumber)) { newPostNumber = curPostNumber; }
                        if (int.Parse(curPostNumber) <= int.Parse(lastPostNumber)) goto End;

                        if (_driver.FindElement(By.XPath($"//*[@id='container']/section[1]/article[2]/div[2]/table/tbody/tr[{i}]/td[3]/a[1]/em")).GetAttribute("class") == "icon_img icon_movie" || _driver.FindElement(By.XPath($"//*[@id='container']/section[1]/article[2]/div[2]/table/tbody/tr[{i}]/td[3]/a[1]/em")).GetAttribute("class") == "icon_img icon_txt")
                        {
                            log.Text += $"\n {curPostNumber}";
                            continue;
                        }

                        var curPost = _driver.FindElement(By.XPath($"//*[@id='container']/section[1]/article[2]/div[2]/table/tbody/tr[{i}]/td[3]/a"));
                        curPost.Click();

                        try
                        {
                            IWebElement appending_file_box_div = _driver.FindElement(By.XPath("//*[@id='container']/section/article[2]/div[1]/div/div[7]/ul"));
                            var links = appending_file_box_div.FindElements(By.TagName("a"));
                            if (links != null)
                            {
                            Restart:
                                foreach (var link in links)
                                {
                                    try
                                    {
                                        link.Click();
                                    }
                                    catch (OpenQA.Selenium.ElementClickInterceptedException)
                                    {
                                        try
                                        {
                                            _driver.FindElement(By.XPath("//*[@id='wif_adx_banner_close']")).Click();
                                        }
                                        catch (Exception)
                                        {

                                        }
                                        goto Restart;
                                    }

                                    _driver.Manage().Timeouts().ImplicitWait = TimeSpan.FromSeconds(200);
                                }
                                _driver.Manage().Timeouts().ImplicitWait = TimeSpan.FromSeconds(500);
                            }

                        }
                        catch (OpenQA.Selenium.NoSuchElementException)
                        {
                            log.Text += $"\n {curPostNumber}";
                        }

                        _driver.Navigate().Back();
                    }
                }
            End:;
                lastPostNumber = newPostNumber;
                //_driver.Manage().Timeouts().ImplicitWait = TimeSpan.FromSeconds(3000);
                Thread.Sleep(3000);
            }      
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void postNumber_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
