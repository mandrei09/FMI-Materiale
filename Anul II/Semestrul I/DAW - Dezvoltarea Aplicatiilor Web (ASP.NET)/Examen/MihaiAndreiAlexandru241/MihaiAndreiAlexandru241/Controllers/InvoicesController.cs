using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using MihaiAndreiAlexandru241.Models;

namespace MihaiAndreiAlexandru241.Controllers
{
    
    public class InvoicesController : Controller
    {
        private readonly AppDbContext db;

        public InvoicesController(AppDbContext context)
        {
            db = context;
        }
        public IActionResult Index()
        {
            var facturi = db.Invoices.Include("Client");
            ViewBag.Facturi = facturi;

            if (TempData.ContainsKey("message"))
            {
                ViewBag.Message = TempData["message"];
            }

            

            return View();
        }
        public IActionResult Show(int id)
        {
            Invoice factura = db.Invoices.Include("Client").Where(c => c.Id == id).First();
            return View(factura);
        }

        public IActionResult New()
        {
            Invoice factura = new Invoice();

            factura.DataEmitere=DateTime.Now;

            factura.Clients = GetAllClients();

            return View(factura);
        }

        [HttpPost]
        public IActionResult New(Invoice factura)
        {
            factura.Clients = GetAllClients();

            if (factura.DataScadenta > factura.DataEmitere)
            {
                ModelState.AddModelError("Date", "Data trebuie sa fie mai mare decat data curenta");
            }

            if (ModelState.IsValid)
            {
                db.Invoices.Add(factura);

                db.SaveChanges();
                TempData["message"] = "Factura a fost adaugata";

                return RedirectToAction("Index");
            }
            else
            {
                return View(factura);
            }
        }

        public IActionResult Edit(int id)
        {
            Invoice factura = db.Invoices.Include("Client")
                                            .Where(x => x.Id == id)
                                            .First();

            factura.Clients = GetAllClients();
            return View(factura);
        }

        [HttpPost]
        public IActionResult Edit(int id, Invoice fact)
        {
            Invoice factura = db.Invoices.Find(id);
            fact.Clients = GetAllClients();

            if (fact.DataScadenta > fact.DataEmitere)
            {
                ModelState.AddModelError("Date", "Data trebuie sa fie mai mare decat data curenta");
            }

            if (ModelState.IsValid)
            {
                factura.Titlu = fact.Titlu;
                factura.Valoare = fact.Valoare;
                factura.DataScadenta = fact.DataScadenta;
                factura.ClientId = fact.ClientId;

                TempData["message"] = "Factura a fost modificata";
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            else
            {
                return View(fact);
            }
        }

        [HttpPost]
        public IActionResult Delete(int id)
        {
            Invoice factura = db.Invoices.Find(id);
            db.Invoices.Remove(factura);
            db.SaveChanges();
            TempData["message"] = "Factura a fost stearsa cu succes";
            return RedirectToAction("Index");
        }

        
        public IActionResult Cautare(DateTime data1, DateTime data2)
        {
            var facturi = db.Invoices.Include("Client");
            var search = "";
            // MOTOR DE CAUTARE
            if (Convert.ToString(HttpContext.Request.Query["search"]) != null)
            {
                // eliminam spatiile libere 
                search = Convert.ToString(HttpContext.Request.Query["search"]).Trim();

                List<int> idFacturi = db.Invoices.Where(c => c.Titlu.Contains(search) || ((c.Valoare).ToString()).Contains(search)).Select(c => c.Id).ToList();

                facturi = db.Invoices.Where(c => idFacturi.Contains(c.Id)).Include("Client").Where(c =>
                    (c.DataScadenta<=data1 &&
                    c.DataScadenta>= data2) ||
                    (c.DataScadenta<=data1 && c.DataScadenta>=data2)).OrderBy(c => c.Titlu);
            }

            ViewBag.SearchString = search;
            ViewBag.Facturi = facturi;

            return View();
        }
        


        [NonAction]
        public IEnumerable<SelectListItem> GetAllClients()
        {
            var selectList = new List<SelectListItem>();

            var clients = from client in db.Clients
                         select client;

            foreach (var client in clients)
            {

                selectList.Add(new SelectListItem
                {
                    Value = client.Id.ToString(),
                    Text = client.Nume.ToString()

                });
            }

            return selectList;
        }
    }
}
