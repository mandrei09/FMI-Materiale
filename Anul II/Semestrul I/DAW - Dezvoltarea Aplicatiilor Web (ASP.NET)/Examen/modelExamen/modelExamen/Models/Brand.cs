using System.ComponentModel.DataAnnotations;

namespace modelExamen.Models
{
    public class Brand
    {
        public int Id { get; set; }

        [Required(ErrorMessage = "Numele brand-ului este obligatoriu")]
        public string Nume { get; set; }

        public virtual ICollection<Giftcard>? Giftcards { get; set; }
    }
}
