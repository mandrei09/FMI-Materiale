library(shiny) #Librarie pentru interfata cu utilizatorul
library(shinythemes) #Tema pentru UI
library(ggplot2) #librarie pentru grafic 

ui <- fluidPage( theme = shinytheme("united"),        
  navbarPage("Benford App",
            #experiment 1
            tabPanel("Recenzii", # denumirea tab-ului pentru experimentul curent
                      h3("Legea lui Benford"),
                      uiOutput('formula'), # functie ce primeste ca parametru id-ul rezultatului 
                      #pe care dorim sa il transmitem catre interfata UI 
                      h4("Aplicații și Jocuri"),
                      # in cadrul interfatei se va afisa un scurt text descriptiv al experimentului curent
                      textOutput("text1"),
                      textOutput("text2"),
                      
                      sidebarLayout(
                        # meniul de setare al datelor pe baza carora se va genera graficul      
                        sidebarPanel(
                          # meniu select de tip dropdown pentru tipul de date
                          selectInput("tip", "Alege tipul de date:", 
                                      choices=c('aplicatii', 'jocuri')),
                          # selectarea tipului de valori asupra carora se va realiza experimentul
                          
                          
                          
                          # range bar pentru selectarea marimii de referinta
                          sliderInput("n", "Marime de referinta", min = 0, max =20000, value = 7000),
                          
                          hr(),
                          # afisarea sursei de unde sunt preluate datele
                          helpText("Sursa date:"),
                          conditionalPanel(condition = "input.tip == 'aplicatii' ",
                          tags$a(href="https://www.kaggle.com/datasets/lava18/google-play-store-apps", "Google Play Store Apps")),
                          conditionalPanel(condition = "input.tip == 'jocuri' ",
                          tags$a(href="https://www.kaggle.com/datasets/rahuldabholkar/steam-pc-games", "PC Games")),
                        ),
                        
                        #afisare grafic / tabel cu date
                        mainPanel(
                          #creare tab-uri
                          tabsetPanel(
                            tabPanel("Grafic", plotOutput("date")), 
                            tabPanel("Vizualizare date tabel", DT::dataTableOutput("mytable") )
                          )
                        )
                        
                      )
            ),   
            helpText("Proiect realizat de Filimon Ioana-Andreea, Furdui Vlad-Rares, Mihai Andrei-Alexandru (241)")
  )
)

# paragrafele accesate in header-ul aplicatiei pentru fiecare experiment in parte
# prin intermediul variabilelor de tip "text*i*" (unde i este un numar natural) mentionate anterior
server <- function(session,input,output) {
  #zona de text
  output$text1<-renderText({
    "Una dintre aplicabilitățile legii lui Benford este cea de a identifica posibiliele fraude la nivelul statisticilor, iar cum review-urile constau, într-o mare parte, într-unul
    dintre cele mai puternice puncte de referință în convingerea utilizatorului de a-și cumpăra o aplicație sau un joc, această lege poate verifica veridicitatea acestora.
    "
  })
  output$text2<-renderText({
    "
    Astfel, sunt introduse numărul de recenzii pentru aplicațiile de pe Google Play, dar și pentru jocurile de pe cea mai ulilizată platformă în acest sens, Steam, date pe care
    generarea graficului se bazează în generarea acestuia.
    
    "
  })
  
  output$formula <- renderUI({
    withMathJax(
      #afisare formula legea lui Benford
      helpText('$$P(d)=lg (d+1) -lg(d)=lg(\\frac{d+1}{d})=lg(1+\\frac {1}{d}), d\\in\\{1..9\\}$$')
    )
  })

  #functie care genereaza graficul legii lui Benford pentru un set de date
  Benford<- function(rate, linii_coloana)
  {
    #extrag prima cifra
    primaCifra<-function(x) as.numeric(substr(gsub('[0.]', '', x), 1, 1))
    #vector de frecventa pt cifrele de la 1 la 9
    frecv<-c(0,0,0,0,0,0,0,0,0)

    for (i in 1:linii_coloana)
    {
      cifra<-primaCifra(rate[i])
      frecv[cifra]<-frecv[cifra]+1#calculez frecventa
    }

    total<-sum(frecv)#o sa ma folosesc de nr total de aparitii in calc procentului

    #vector care retine procentul pentru fiecare cifra
    procent<-c(0,0,0,0,0,0,0,0,0)
    for (i in 1:9)
    {
      procent[i]<-frecv[i]/total #se calculeaza procentul  aparitiilor cifrei i raportat la nr total de aparitie al cifrelor
    }

    benford<-c(0,0,0,0,0,0,0,0,0)
    for (i in 1:9)
    {
      benford[i]<-log10(1+ 1/i)#calculez valorile standard ale lui Benford 
    }
    #formez un data frame din care o sa generez graficul
    frame3<-data.frame(
      numere=c("1","2", "3", "4", "5", "6", "7", "8", "9"),
      ben=benford,
      procente=procent
    )
    #generare grafic
    ggplot(data = frame3, aes(x = numere, group=1))+ geom_bar(aes(y = procente), stat = "identity", color=NA, fill="lightblue") + geom_line(aes(y = ben), stat = "identity", color="red") 
    
  }
  
  # Functia preia un vector de rate si numarul de linii 
  # sau coloane din acele rate si extrage prima cifra din fiecare rata. Apoi calculeaza frecventa fiecarei cifre 
  # de la 1 la 9. Ulterior, functia calculeaza procentul fiecarei cifre din totalul de aparitii al tuturor cifrelor si 
  # valorile standard ale lui Benford. La final, functia formeaza un data frame cu numerele, valorile standard ale 
  # lui Benford si procentele calculate anterior si genereaza un grafic care compara aceste valori.
  
  #grafice
  output$date <- renderPlot({
    
    #citire din fisierul dat ca input din dropdown
    nume_csv<-paste(input$tip, ".csv", sep="")
    data1<-(read.csv(nume_csv, header=TRUE))
    
    #afisare tabel cu date  
    if(nume_csv == "aplicatii.csv")
    tabel<- data.frame(
      Nume=data1$App,
      Rating=data1$Rating,
      Marime=data1$Size,
      Reviews=data1$Reviews,
      Instalari=data1$Installs
      )
    
    
    if(nume_csv == "jocuri.csv")
      
      tabel<- data.frame(
        Nume=data1$title,
        Pret=data1$price,
        Reviews=data1$Reviews,
        ProcentDeApreciere=data1$percent_positive
        )
      
    output$mytable = DT::renderDataTable({tabel})

    rate<-data1$Reviews
   
    
    #se aplica legea lui Benford pe n date
    linii_coloana<-input$n
    
    Benford(rate, linii_coloana)
    
  })
  
  # Utilizatorul poate selecta un fișier CSV din lista de opțiuni din "dropdown", care apoi va fi afișat într-un tabel 
  # în outputul aplicației. De asemenea, utilizatorul poate selecta coloana din fișierul CSV care urmează să fie 
  # analizată și numărul de rânduri care trebuie analizate prin intermediul unui alt "slidebar".
  # Apoi, funcția "Benford" este apelată pentru a aplica legea lui Benford asupra datelor selectate. 
  # În cele din urmă, funcția returnează un grafic care compară distribuția actuală a datelor cu 
  # distribuția standard prevăzută de legea lui Benford.
  
}

# apelul pentru initializarea interfatei.
shinyApp(ui = ui, server = server,options = list(height = 1080))


 
