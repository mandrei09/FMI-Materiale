using System.ComponentModel.DataAnnotations;

namespace MihaiAndreiAlexandru241.Models
{
    public class Client
    {
        [Key,Required]
        public int Id { get; set; }
        [Required(ErrorMessage = "Numele clientului este obligatoriu!")]
        public string Nume { get; set; }
    }
}
