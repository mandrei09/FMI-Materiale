using Microsoft.EntityFrameworkCore;
using MihaiAndreiAlexandru241.Models;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllersWithViews();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

var connectionString = builder.Configuration.GetConnectionString("DefaultConnection");
builder.Services.AddDbContext<AppDbContext>(options =>
options.UseSqlServer(connectionString));

app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();

// Data Source=(localdb)\mssqllocaldb;Initial Catalog=ExamenDB;Integrated Security=True;MultipleActiveResultSets=True

//Nu am putut realiza conexiunea cu baza de date. Tot primesc o eroare dubioasa, am incercat sa rezolv dar n-am reusit nimic. 
//Am incercat sa scriu programul nerulandu-l cum am crezut eu, sper sa fie ok.
//Unable to create an object of type 'AppDbContext'. For the different patterns supported at design time, see https://go.microsoft.com/fwlink/?linkid=851728
