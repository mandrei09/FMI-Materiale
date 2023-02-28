using Microsoft.AspNetCore.Mvc.Rendering;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace modelExamen.Models
{
    public class Giftcard
    {
        [Key]
        public int Id { get; set; }

        [Required(ErrorMessage ="Cardul trebuie sa aiba un nume")]
        public string Denumire { get; set; }

        [Required(ErrorMessage ="Cardul trebuie sa aiba descriere")]
        public string Descriere { get; set; }

        [Required(ErrorMessage ="Data trebuie sa fie completata")]
        public DateTime DataExp { get; set; }

        [Required(ErrorMessage ="Procentul trebuie sa fie completat")]
        [Range(1,100)]
        public int Procent { get; set; }

        [Required(ErrorMessage ="Cardul trebuie sa aiba un brand asociat")]
        public int BrandId { get; set; }
        public virtual Brand? Brand { get; set; }

        [NotMapped]
        public IEnumerable<SelectListItem>? Brd { get; set; }

    }
}
