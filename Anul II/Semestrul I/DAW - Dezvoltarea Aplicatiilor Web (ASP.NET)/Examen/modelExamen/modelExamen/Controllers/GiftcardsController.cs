using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.SqlServer.Query.Internal;
using modelExamen.Models;

namespace modelExamen.Controllers
{
    public class GiftcardsController : Controller
    {
        private AppDbContext db = new AppDbContext();
        public IActionResult Index()
        {
            var cards = db.Giftcards.Include("Brand");
            ViewBag.Cards = cards;

            if (TempData.ContainsKey("message"))
            {
                ViewBag.Message = TempData["message"];
            }

            return View();
        }

        public IActionResult Show(int id)
        {
            Giftcard card = db.Giftcards.Include("Brand").Where(c => c.Id == id).First();
            return View(card);
        }

        public IActionResult New()
        {
            Giftcard giftcard = new Giftcard();

            giftcard.Brd = GetAllBrands();

            return View(giftcard);
        }

        [HttpPost]
        public IActionResult New(Giftcard giftcard)
        {
            giftcard.Brd = GetAllBrands();

            if (giftcard.DataExp < DateTime.Now)
            {
                ModelState.AddModelError("Date", "Data trebuie sa fie mai mare decat data curenta");
            }

            if (ModelState.IsValid)
            {
                db.Giftcards.Add(giftcard);

                db.SaveChanges();
                TempData["message"] = "Cardul a fost adaugat";

                return RedirectToAction("Index");
            }
            else
            {
                return View(giftcard);
            }

        }

        public IActionResult Edit(int id)
        {
            Giftcard giftcart = db.Giftcards.Include("Brand")
                                            .Where(x => x.Id == id)
                                            .First();


            giftcart.Brd = GetAllBrands();
            return View(giftcart);
        }

        [HttpPost]
        public IActionResult Edit(int id, Giftcard requestGiftCard)
        {
            Giftcard giftcard = db.Giftcards.Find(id);
            requestGiftCard.Brd = GetAllBrands();

            if (requestGiftCard.DataExp < DateTime.Now)
            {
                ModelState.AddModelError("Date", "Data trebuie sa fie mai mare decat data curenta");
            }

            if (ModelState.IsValid)
            {
                giftcard.Denumire = requestGiftCard.Denumire;
                giftcard.Descriere = requestGiftCard.Descriere;
                giftcard.DataExp = requestGiftCard.DataExp;
                giftcard.Procent = requestGiftCard.Procent;
                giftcard.BrandId = requestGiftCard.BrandId;

                TempData["message"] = "Cardul a fost modificat";
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            else
            {
                return View(requestGiftCard);
            }
        }

        [HttpPost]
        public IActionResult Delete(int id)
        {
            Giftcard giftcard = db.Giftcards.Find(id);
            db.Giftcards.Remove(giftcard);
            db.SaveChanges();
            TempData["message"] = "Cardul a fost sters";
            return RedirectToAction("Index");
        }

        public IActionResult Cautare()
        {
            var giftcards = db.Giftcards.Include("Brand");
            var search = "";
            // MOTOR DE CAUTARE
            if (Convert.ToString(HttpContext.Request.Query["search"]) != null)
            {
                // eliminam spatiile libere 
                search = Convert.ToString(HttpContext.Request.Query["search"]).Trim();

            // Cautare in articol (Title si Content)
            List<int> cardsids = db.Giftcards.Where(c => c.Denumire.Contains(search)|| c.Descriere.Contains(search)).Select(c => c.Id).ToList();
               
                giftcards = db.Giftcards.Where(c => cardsids.Contains(c.Id)).Include("Brand").Where(c => 
                    c.DataExp.Month == DateTime.Now.Month && 
                    c.DataExp.Year == DateTime.Now.Year && 
                    c.DataExp.Day <= DateTime.Now.Day+5 &&
                    c.Procent >= 30).OrderByDescending(c => c.DataExp);
            }

            ViewBag.SearchString = search;
            ViewBag.Giftcards = giftcards;

            return View();

        }


        [NonAction]
        public IEnumerable<SelectListItem> GetAllBrands()
        {
            var selectList = new List<SelectListItem>();

            var brands = from brn in db.Brands
                         select brn;

            foreach (var brand in brands)
            {

                selectList.Add(new SelectListItem
                {
                    Value = brand.Id.ToString(),
                    Text = brand.Nume.ToString()

                });
            }

            return selectList;
        }

    }
}
