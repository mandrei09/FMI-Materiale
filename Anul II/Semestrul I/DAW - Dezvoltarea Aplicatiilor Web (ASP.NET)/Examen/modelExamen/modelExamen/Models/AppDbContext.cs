using Microsoft.EntityFrameworkCore;

namespace modelExamen.Models
{
    public class AppDbContext : DbContext
    {
        public AppDbContext() : base()
        {
        }
        protected override void OnConfiguring
       (DbContextOptionsBuilder options)
        {
            options.UseSqlServer(
            @"Data Source=(localdb)\mssqllocaldb;Initial Catalog=modelExamenDB;Integrated Security=True;MultipleActiveResultSets=True");
        }
        public DbSet<Giftcard> Giftcards { get; set; }
        public DbSet<Brand> Brands { get; set; }
    }
}
