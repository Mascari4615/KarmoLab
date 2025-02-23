using KarmoBlazorServer.Areas.Identity;
using KarmoBlazorServer.Data;
using Microsoft.AspNetCore.Components;
using Microsoft.AspNetCore.Components.Authorization;
using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Identity.UI;
using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
var connectionString = builder.Configuration.GetConnectionString("DefaultConnection") ?? throw new InvalidOperationException("Connection string 'DefaultConnection' not found.");
builder.Services.AddDbContext<ApplicationDbContext>(options =>
	options.UseSqlServer(connectionString));
builder.Services.AddDatabaseDeveloperPageExceptionFilter();
builder.Services.AddDefaultIdentity<IdentityUser>(options => options.SignIn.RequireConfirmedAccount = false)
	.AddEntityFrameworkStores<ApplicationDbContext>();
builder.Services.AddRazorPages();
builder.Services.AddServerSideBlazor();
builder.Services.AddScoped<AuthenticationStateProvider, RevalidatingIdentityAuthenticationStateProvider<IdentityUser>>();
// builder.Services.AddSingleton<WeatherForecastService>();
// Scoped creates an instance for each user
builder.Services.AddScoped<UserRecordService>();
builder.Services.AddScoped<SpecialThingService>();

// Register the pizzas service
// builder.Services.AddSingleton<TodoService>();
// builder.Services.AddSqlServer<TodoContext>("Data Source=KarmoBlazerServer.db");
// Context�� ASP.NET Core�� ���Ӽ� ���� �ý��ۿ� ���
// Context�� Sqlite �����ͺ��̽� �����ڸ� ����ϵ��� �����մϴ�.
// ���� ���� .db�� ����Ű�� Sqlite ���� ���ڿ��� �����մϴ�.

// ���� ������ �ϴ� �� SQL Server
// ���� DB ������ ����ϴ� Sqlite�� ��� ����ó�� ���� ���ڿ��� �ϵ� �ڵ��ص� ��������,
// SQL Server ���� ��Ʈ��ũ DB�� ��� ���� ���ڿ��� �׻� �����ϰ� �����ؾ� �Ѵ�

// ���� ������ ��� ��� �����ڸ� ���
// ���δ��� ������ ��� Azure Key Vault ���� ���񽺸� ����ϴ� ���� ����

// Read the connection string from the appsettings.json file
// Set the database connection for the EndtoEndContext
builder.Services.AddDbContext<KarmoBlazorServerDB.Data.KarmoBlazorServer.KarmoAppContext>(options =>
options.UseSqlServer(builder.Configuration.GetConnectionString("DefaultConnection")));
var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
	app.UseMigrationsEndPoint();
}
else
{
	app.UseExceptionHandler("/Error");
	// The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
	app.UseHsts();
}

app.UseHttpsRedirection();

app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

app.MapControllers();
app.MapBlazorHub();
app.MapFallbackToPage("/_Host");

app.Run();
