using Microsoft.AspNetCore.Mvc.Rendering;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace MihaiAndreiAlexandru241.Models
{
    public class Invoice
    {
        [Key,Required]
        public int Id { get; set; }
        [Required(ErrorMessage = "Titlul facturii este obligatoriu!")]
        public string Titlu { get; set; }
        [Required(ErrorMessage = "Valoarea facturii este obligatorie!")]
        public int Valoare { get; set; }
        [Required(ErrorMessage = "Selectati data emiterii facturii!")]
        public DateTime DataEmitere { get; set; }
        [Required(ErrorMessage = "Selectati data scadenta facturii!")]
        public DateTime DataScadenta { get; set; }
        [Required(ErrorMessage = "Dati ID-ul clientului!")]
        public int ClientId { get; set; }
        // Int32.TryParse(Textbox.Text, out integer)
        [NotMapped]
        public IEnumerable<SelectListItem>? Clients { get; set; }
    }
}
